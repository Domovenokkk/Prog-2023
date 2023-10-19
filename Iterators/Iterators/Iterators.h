#include <iostream>
#include <Windows.h>
#include <vector>

template<class T> class Vector;

template <class T> 
std::ostream& operator<<(std::ostream& ostr, const TVector<T>& vec);





template <class T>
class InIterator : public std::iterator<std::input_iterator_tag, T> {
private:
	T* ptr;
	InIterator(T* p) : ptr(p) {}
public:
	InIterator(const InIterator& it) : ptr(it.ptr) {}

	InIterator<T>& operator++() {
		++ptr;
		return *this;
	}

	T& operator*() {
		return *ptr;
	}

	bool operator!=(const InIterator& it) {
		return ptr != it.ptr;
	}

	bool operator==(const InIterator& it) {
		return ptr == it.ptr;
	}

};

template<class T>
class OutIterator : public std::iterator<std::output_iterator_tag, T> {
private:
	T* ptr;
	OutIterator(T* p) : ptr(p) {}
public:
	OutIterator(const OutIterator& it) : ptr(it.ptr) {}

	OutIterator<T>& operator++() const {
		++ptr;
		return *this;
	}

	const T& operator*() const { return *ptr; }

	bool operator==(const OutIterator& it) const { return ptr == it.ptr; }

	bool operator!=(const OutIterator& it) const { return ptr != it.ptr; }
};

template<class T>
class ForwardIterator : public std::iterator<std::forward_iterator_tag, T> {
private:
	T* ptr;
	ForwardIterator(T* p) : ptr(p) {}
public:
	ForwardIterator(const ForwardIterator& it) : ptr(it.ptr) {}

	ForwardIterator<T>& operator++() const {
		++ptr;
		return *this;
	}

	const T& operator*() const { return *ptr; }

	bool operator==(const ForwardIterator& it) const { return ptr == it.ptr; }

	bool operator!=(const ForwardIterator& it) const { return ptr != it.ptr; }

	ForwardIterator<T>& operator+(int x) {
		ptr = ptr + x;
		return *this;
	}
};


template<class T>
class BidIterator : public std::iterator<std::bidirectional_iterator_tag, T> {
private:
	T* ptr;
	BidIterator(T* p) : ptr(p) {}
public:
	BidIterator(const BidIterator& it) : ptr(it.ptr) {}

	BidIterator<T>& operator++() const {
		++ptr;
		return *this;
	}

	BidIterator<T>& operator--() const {
		--ptr;
		return *this;
	}

	const T& operator*() const { return *ptr; }

	bool operator==(const BidIterator& it) const { return ptr == it.ptr; }

	bool operator!=(const BidIterator& it) const { return ptr != it.ptr; }

	BidIterator<T>& operator+(int x) {
		ptr = ptr + x;
		return *this;
	}

	BidIterator<T>& operator-(int x) {
		ptr = ptr - x;
		return *this;
	}
};


template <class T>
class TVector {
protected:
	T* pMem;
	size_t size;
public:
	typedef InIterator<T> iterator;
	typedef InIterator<const T> const_iterator;
	TVector(size_t size_) {
		pMem = new T[size_];
		for (int i = 0; i < size_; i++) {
			pMem[i] = 0;
		}
	}

	TVector(const TVector<T>& v) {
		pMem = v.pMem;
		size = v.size;
	}
	~TVector() {
		delete[] pMem;
		pMem = nullptr;
	}

	T* begin() { return &pMem[0]; }
	T* end() { return (&pMem[size - 1] + 1); }

	friend std::ostream& operator<<<T>(std::ostream& ostr, const  TVector<T>& vec);
};

template <class T>
std::ostream& operator<<(std::ostream& ostr, const  TVector<T>& vec) {
	for (int i = 0; i < vec.size; i++) {
		ostr << vec[i] << " ";
	}
	return ostr;
}