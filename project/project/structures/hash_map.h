#pragma once
#include<iostream>
#include <vector>
#include <list>
#include <stdexcept>


//i decided to use seperate chaining, bucket refers to datastructure i am storing it in in this case its linked list
//for hashing function i choose standard library std::hash instead of relieing on my own implementetion

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

	size_t getBucketIndex(const KeyType& key) const {
		return std::hash<KeyType>{}(key) % capacity;
	};

public:

	HashMap(size_t initialCapacity = DEFAULT_CPACITY) : capacity(initialCapacity), size(0) {
		this->buckets.resize(capacity);
	}

	void insert(KeyType& const key, ValueType& const value) {

		size_t bucketIndex = this->getBucketIndex(key);

		for (const auto& kvp : buckets[getBucketIndex]) {
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
	}

	ValueType get(KeyType& const key) const {

		size_t bucketIndex = this->getBucketIndex(key);

		for (const auto& kvp : buckets[getBucketIndex]) {
			if (kvp.key == key) {
				return kvp.value
			}
		}
		throw std::out_of_range("Key not found");

	}

	void remove(KeyType& const key) {
		size_t bucketIndex = this->getBucketIndex(key);

		for (auto it = buckets[bucketIndex].begin(); it != buckets[bucketIndex].end(); ++it) {
			if (it->key == key) {
				buckets[bucketIndex].erase(kvp);
				size--;
				return;
			}
		}
		throw std::out_of_range("Key not found");


	}

};


