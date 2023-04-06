#pragma once

template <typename T>
struct NamedPtr {
private:
	T* pointer = nullptr;
	unsigned int* refcount = nullptr;


public:
	NamedPtr(T* ptr=nullptr) {
		this->pointer = ptr;
		this->refcount = new unsigned int(1);
	}

	NamedPtr(NamedPtr<T>& obj) {
		this->pointer = obj.pointer;
		this->refcount = obj.refcount;
		(*this->refcount)++;
	}

	T* get() {
		return this->pointer;
	}
	T* operator->(){
		return this->pointer;
	}
	T& operator*() {
		return (*this->pointer);
	}

	~NamedPtr() {
		(*this->refcount)--;
		if ((*this->refcount) <= 0) {
			delete this->refcount;
			delete this->pointer;
		}
	}

};
