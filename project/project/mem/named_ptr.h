#pragma once

template <typename T>
struct NamedPtr {
private:
	T* pointer = nullptr;
	unsigned int* refcount = nullptr;


public:
	NamedPtr() {
		pointer = nullptr;
		refcount = new unsigned int(0);
	}

	NamedPtr(const NamedPtr& obj) {
		this->pointer = obj.pointer;
		this->refcount = obj.refcount;
		if (this->pointer == nullptr) {
			(*this->count)++;
		}
	}

	NamedPtr(NamedPtr&& obj) {
		this->pointer = obj.pointer;
		this->refcount = obj.refcount;
		obj.pointer = nullptr;
		obj.refcount = nullptr;
	}

	NamedPtr&operator=(NamedPtr&& obj) {
		this->pointer = obj.pointer;
		this->refcount = obj.refcount;
		obj.pointer = nullptr;
		obj.refcount = nullptr;
	}

	~NamedPtr(NamedPtr&& obj) {
		(*this->refcount)--;
		if ((*this->refcount) <= 0) {
			delete this->refcount;
			delete this->pointer;
		}
	}
	
	T* operator->() const {
		return this->pointer;
	}
	T& operator*() const {
		return this->pointer;
	}

};