#pragma once
#include<iostream>
#include <vector>
#include <list>
#include <stdexcept>


// I decided to use separate chaining, where each bucket refers to the data structure I am storing the elements in.In this case, I am using a linked list.Instead of relying on my own implementation of a hashing function, I chose to use the standard library's std::hash function.

template<typename KeyType, typename ValueType>
class HashMap {

private:
	struct KeyValuePair {
		KeyType key;
		ValueType value;
	};

	typedef std::list<KeyValuePair> Bucket;

	std::vector<Bucket> buckets;
	size_t size;
	size_t capacity;
	static const size_t DEFAULT_CAPACITY = 16;

	const size_t getBucketIndex(const KeyType& key) const {
		return std::hash<KeyType>{}(key) % capacity;
	};

public:

	HashMap(size_t initialCapacity = DEFAULT_CAPACITY) : capacity(initialCapacity), size(0) {
		this->buckets.resize(capacity);
	}

	void insert(const KeyType& key, const ValueType& value) {

		size_t bucketIndex = this->getBucketIndex(key);
		std::cout << "hashed key: " << bucketIndex << std::endl;

		for (const auto& kvp : this->buckets[bucketIndex]) {
			if (kvp.key == key) {
				throw std::invalid_argument("Duplicate key");
			}
		}

		KeyValuePair kv{ key, value };
		buckets[bucketIndex].push_back(kv);

		if (size > capacity) {
			size_t newCapacity = capacity * 2;
			this->rehash(newCapacity);
		}
		size++;
	}

	const ValueType get(const KeyType& key) const {

		size_t bucketIndex = this->getBucketIndex(key);

		for (const auto& kvp : buckets[getBucketIndex]) {
			if (kvp.key == key) {
				return kvp.value;
			}
		}
		throw std::out_of_range("Key not found");

	}

	void remove(const KeyType& key) const {
		size_t bucketIndex = this->getBucketIndex(key);

		for (auto it = buckets[bucketIndex].begin(); it != buckets[bucketIndex].end(); ++it) {
			if (it->key == key) {
				buckets[bucketIndex].erase(it->key);
				size--;
				return;
			}
		}
		throw std::out_of_range("Key not found");

	}

	const size_t getSize() const {
		return size;
	}

	const bool isEmpty() const {
		return size == 0;
	}

	const size_t getCapacity() const{
		return this->capacity;
	}

	void logHashMap() {
		std::cout
		<< "HASH MAP SIZE: " << this->getSize() << std::endl
		<< "HASH MAP CAPACITY: " << this->getCapacity() << std::endl;

		for (size_t i = 0; i < this->getCapacity(); i++) {
			for (const auto& kvp : buckets[i]) {
				std::cout << "key:value " <<
				kvp.key << ":" << kvp.value << std::endl;
			}
		}
	}

private:

	void rehash(size_t updatedCap) {
		std::vector<Bucket> newBuckets(updatedCap);
		size_t oldCapacity = capacity;
		capacity = updatedCap;
		size = 0;

		for (size_t i = 0; i < oldCapacity; ++i) {
			for (const auto& kvp : buckets[i]) {
				size_t newBucketIndex = this->getBucketIndex(kvp.key);
				newBuckets[newBucketIndex].push_back(kvp);
				size++;
			}
		}

		this->buckets = std::move(newBuckets);

	}
};


