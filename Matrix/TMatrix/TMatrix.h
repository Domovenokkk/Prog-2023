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
    // ������ ����� ������� ���? ���������.
    using TVector<TVector<T>>::operator[];

    // ���������
    bool operator==(const TMatrix& m) const noexcept;
    bool operator!=(const TMatrix& m) const noexcept;

    // ��������-��������� ��������
    TMatrix operator*(const T& val);

    // ��������-��������� ��������
    TVector<T> operator*(const TVector<T>& v);

    // ��������-��������� ��������
    TMatrix operator+(const TMatrix& m);
    TMatrix operator-(const TMatrix& m);
    TMatrix operator*(const TMatrix& m);

    // ����/�����
    friend std::istream& operator>>(std::istream& istr, TMatrix& v);
    friend std::ostream& operator<<(std::ostream& ostr, const TMatrix& v);
};