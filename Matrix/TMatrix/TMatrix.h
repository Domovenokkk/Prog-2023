#include "../TVector/TVector.h"
#define INCLUDE_MATRIX_H_
#include <iostream>
const int MAX_MATRIX_SIZE = 10000;

template <class T>
class TMatrix : private TVector<TVector<T>> {
    using TVector<TVector<T>>::pMem;
    using TVector<TVector<T>>::sz;
public:
    TMatrix(size_t s = 1) : TVector<TVector<T>>(s) {
        for (size_t i = 0; i < sz; i++)
            pMem[i] = TVector<T>(sz);
    }
    // почему можно сделать так? ќбъ€снить.
    using TVector<TVector<T>>::operator[];

    // сравнение
    bool operator==(const TMatrix& m) const noexcept;
    bool operator!=(const TMatrix& m) const noexcept;

    // матрично-скал€рные операции
    TMatrix operator*(const T& val);

    // матрично-векторные операции
    TVector<T> operator*(const TVector<T>& v);

    // матрично-матричные операции
    TMatrix operator+(const TMatrix& m);
    TMatrix operator-(const TMatrix& m);
    TMatrix operator*(const TMatrix& m);

    // ввод/вывод
    friend std::istream& operator>>(std::istream& istr, TMatrix& v);
    friend std::ostream& operator<<(std::ostream& ostr, const TMatrix& v);
};