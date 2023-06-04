#pragma once
#include<iostream>
#include <vector>
#include <list>
#include <stdexcept>


//seperate chaining, open addresing  (think about using one of those)

template<typename KeyType, typename ValueType>
class HashMap {

private:
	struct KeyValuePair {
		KeyType key;
		ValueType value;
		KeyValuePair(const KeyType& k, const ValueType& v): key(k), value(v)
	};

	typedef std::list<KeyValuePair> Bucket;

	std::vector<Bucket> buckets;
	size_t size;
	size_t capacity;
	static const size_t DEFAULT_CAPACITY = 16;
	

public:
	
};