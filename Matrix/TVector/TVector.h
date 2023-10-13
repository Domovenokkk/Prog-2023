#pragma once

#include <iostream>
const int MAX_VECTOR_SIZE = 100000000;

template<typename T>
class TVector {
protected:
    size_t _size;
    T* pMem;
public:
    TVector(size_t sz = 1) : _size(sz) {
        if (sz == 0)
            throw std::length_error("Vector size should be greater than zero");
        if (sz > MAX_VECTOR_SIZE)
            throw std::length_error("Vector size cannot be greater than MAX_VECTOR_SIZE = ", MAX_VECTOR_SIZE);
        pMem = new T[sz]();
    }

    TVector(T* data, size_t sz) : _size(sz) {
        // еще один способ ввода исключений
        assert(data != nullptr && "TVector constructor requires non-nullptr argument.");
        pMem = new T[sz];
        // дл€ массивов можно использовать std-функции с условием, что вы знаете как они там реализованы!
        std::copy(data, data + sz, pMem);
    }

    TVector(const TVector& v) {
        _size = v._size;
        pMem = v.pMem;
    }

    ~TVector() {
        delete[] pMem;
        pMem = nullptr;
    }

    T& operator[](size_t ind) {
        if (ind < 0 || ind > MAX_VECTOR_SIZE) {
            throw std::length_error("The index cannot have this value.");
        }
        return pMem[ind];
    }

    bool operator==(const TVector& v) const с;
    bool operator!=(const TVector& v) const noexcept;

    TVector operator+(double val);
    TVector operator-(double val);
    TVector operator*(double val);

    TVector operator+(T val);
    TVector operator-(T val);
    TVector operator*(T val);

    TVector operator+(const TVector& v);
    TVector operator-(const TVector& v);

    // почитать о noexcept(noexcept(T())) - объ€снить назначение при сдаче
    T operator*(const TVector& v) noexcept(noexcept(T()));

    friend void swap(TVector& lhs, TVector& rhs) noexcept;

    // ввод/вывод
    friend istream& operator>>(istream& istr, TVector& v);
    friend ostream& operator<<(ostream& ostr, const TVector& v);
};

template <class T>
void swap(TVector<T>& lhs, TVector<T>& rhs) noexcept {
    std::swap(lhs.sz, rhs.sz);
    std::swap(lhs.pMem, rhs.pMem);
}

template <class T>
std::istream& operator>>(std::istream& istr, TVector<T>& v) {
    for (size_t i = 0; i < v.sz; i++)
        istr >> v.pMem[i];
    return istr;
}

template <class T>
std::ostream& operator<<(std::ostream& ostr, const TVector<T>& v) {
    for (size_t i = 0; i < v.sz; i++)
        ostr << v.pMem[i] << ' ';
    return ostr;
}