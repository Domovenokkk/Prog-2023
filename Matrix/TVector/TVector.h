
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
            throw std::logic_error("The index cannot have this value.");
        }
        return this->pMem[ind];
    }

    bool operator==(const TVector& v)const noexcept {
        if (_size != v._size) {
            throw std::logic_error("Vectors have different sizes");
        }
        TVector<T> res(*this);
        for (auto i = 0; i < _size; i++) {
            res[i] == v[i];
        }
    }
    bool operator!=(const TVector& v) const noexcept {
        return !(*this == v);
    }

    size_t size() const noexcept {
        return _size;
    }

    TVector operator+(T val) {
        for (auto i = 0; i < _size; i++) {
            pMem[i] = pMem[i] + val;
        }
    }
    TVector operator-(T val) {
        for (auto i = 0; i < _size; i++) {
            pMem[i] = pMem[i] - val;
        }
    }
    TVector operator*(T val) {
        for (auto i = 0; i < _size; i++) {
            pMem[i] = pMem[i] * val;
        }
    }

    TVector operator+(const TVector& v) {
        if (_size != v._size) {
            throw std::length_error("Vectors have different sizes");
        }
        TVector<T> res(*this);
        for (auto i = 0; i < _size; i++) {
            res[i] = res[i] + v[i];
        }
    }
    TVector operator-(const TVector& v) {
        if (_size != v._size) {
            throw std::length_error("Vectors have different sizes");
        }
        TVector<T> res(*this);
        for (auto i = 0; i < _size; i++) {
            res[i] = res[i] - v[i];
        }
    }

    // почитать о noexcept(noexcept(T())) - объ€снить назначение при сдаче
    T operator*(const TVector& v) noexcept(noexcept(T()))
    {
        T tmp;
        for (auto i = 0; i < _size; i++) {
            tmp = tmp + (*this)[i] * v[i];
        }
        return tmp;
    }

    friend void swap(TVector& lhs, TVector& rhs) noexcept;
    friend std::istream& operator>>(std::istream& istr, TVector& v);
    friend std::ostream& operator<<(std::ostream& ostr, const TVector& v);
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