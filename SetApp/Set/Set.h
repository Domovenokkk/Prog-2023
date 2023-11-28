#ifndef INCLUDE_SET_H_
#define INCLUDE_SET_H_

#include <iostream>
#include "BitField.h"

class TSet {
private:
	size_t maxPower;                       // ������������ �������� ���������
	TBitField bitField;                    // ������� ���� ��� �������� ���������
public:
	TSet(int mp) : bitField(mp), maxPower(mp) {}
	TSet(const TSet& s) : bitField(s.bitField), maxPower(s.maxPower) {}

	TSet(const TBitField& bf) : bitField(bf), maxPower(bf.size()) {}


	operator TBitField(); // �������������� ���� � �������� ����

	size_t GetMaxPower() const noexcept;

	void InsElem(size_t Elem); // �������� ������� � ���������
	void DelElem(size_t Elem); // ������� ������� �� ���������
	bool IsMember(size_t Elem) const; // ��������� ������� �������� � ���������

	TSet operator+ (const int Elem);  // ����������� � ���������
	TSet operator- (const int Elem);  // �������� � ���������
	TSet operator+ (const TSet& s);
	TSet operator* (const TSet& s); // �����������

	TSet operator~ ();
	int operator== (const TSet& s) const;
	int operator!= (const TSet& s) const;
	TSet& operator=(const TSet& s);

	friend std::istream& operator>>(std::istream& in, TSet& bf);
	friend std::ostream& operator<<(std::ostream& out, const TSet& bf);
};

#endif  // INCLUDE_SET_H_

TSet::operator TBitField() { return bitField; }

size_t TSet::GetMaxPower() const noexcept { return maxPower; }

void TSet::InsElem(size_t Elem) 
{
	if (Elem < 0 || Elem >= maxPower) { throw std::logic_error("Out of range."); }
	else { return bitField.set(Elem); }
}

void TSet::DelElem(size_t Elem) 
{
	if (Elem < 0 || Elem >= maxPower) { throw std::logic_error("Out of range."); }
	else { return bitField.reset(Elem); }
}

bool TSet::IsMember(size_t Elem) const
{
	if (Elem < 0 || Elem >= maxPower) { throw std::logic_error("Out of range."); }
	else { return bitField.test(Elem); }
}

TSet TSet:: operator+(const int Elem) 
{
	if (Elem < 0 || Elem >= maxPower) { throw std::logic_error("Out of range."); }
	else {
		TSet ts(*this);
		ts.InsElem(Elem);
		return ts;
	}
}

TSet TSet:: operator-(const int Elem) 
{
	if (Elem < 0 || Elem >= maxPower) { throw std::logic_error("Out of range."); }
	else {
		TSet ts(*this);
		ts.DelElem(Elem);
		return ts;
	}
}

TSet TSet:: operator+(const TSet& s) 
{
	TSet ts(*this);
	if (s.maxPower > maxPower) { ts.maxPower = s.maxPower; }
	else { ts.maxPower = maxPower; }
	ts.bitField = bitField | s.bitField;
	return ts;
}

TSet TSet:: operator*(const TSet& s) 
{
	TSet ts(*this);
	if (s.maxPower > maxPower) { ts.maxPower = s.maxPower; }
	else { ts.maxPower = maxPower; }
	ts.bitField = bitField & s.bitField;
	return ts;
}

TSet TSet:: operator~() {
	TSet ts(*this);
	ts.bitField = ~bitField;
	return ts;
}

int TSet:: operator==(const TSet& s) const { return (bitField == s.bitField); }

int TSet:: operator!=(const TSet& s) const { return (bitField != s.bitField); }

TSet& TSet:: operator=(const TSet& s) 
{
	maxPower = s.maxPower;
	bitField = s.bitField;
	return *this;
}

std::istream& operator>>(std::istream& istr, TSet& s) {
	int elem;
	istr >> elem;
	s = s + elem;
	return istr;
}

std::ostream& operator<<(std::ostream& ostr, const TSet& s) {
	for (int i = 0; i < s.maxPower; i++) {
		if (s.bitField.test(i) == 1) {
			ostr << i << " ";
		}
	}
	return ostr;
}