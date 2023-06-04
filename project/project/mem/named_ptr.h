#pragma once
#include <iostream>

template<typename T>
class NamedPtr {
public:
	NamedPtr(T* ptr = nullptr)
		: m_ptr(ptr),
		m_refCount(new int(1))
	{
	}

	~NamedPtr()
	{
		(*m_refCount)--;
		if (*m_refCount == 0) {
			delete m_ptr;
			delete m_refCount;
		}
	}

	NamedPtr(const NamedPtr& other)
		: m_ptr(other.m_ptr),
		m_refCount(other.m_refCount)
	{
		(*m_refCount)++;
	}

	NamedPtr& operator=(const NamedPtr& other)
	{
		if (this != &other) {
			(*m_refCount)--;
			if (*m_refCount == 0) {
				delete m_ptr;
				delete m_refCount;
			}
			m_ptr = other.m_ptr;
			m_refCount = other.m_refCount;
			(*m_refCount)++;
		}
		return *this;
	}

	T& operator*() const
	{
		return *m_ptr;
	}

	T* operator->() const
	{
		return m_ptr;
	}

	bool operator==(const NamedPtr& other) const
	{
		return m_ptr == other.m_ptr;
	}

	bool operator!=(const NamedPtr& other) const
	{
		return m_ptr != other.m_ptr;
	}

private:
	T* m_ptr;
	int* m_refCount;
};