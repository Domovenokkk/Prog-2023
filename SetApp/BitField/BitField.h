#ifndef INCLUDE_BITFIELD_H_
#define INCLUDE_BITFIELD_H_

#include <iostream>

using elem_type = unsigned int;

class TBitField {
private:
	size_t bitLen;                      // длина битового поля (максимальное допустимое значение эл-та мн-ва, мощность универса)
	size_t memLen;                      // кол-во элементов, необходимое для хранения битового поля
	elem_type* pMem;                    // память для представления битового поля

	// служебные поля (не обязательны)
	//size_t bitsInElem;
	//size_t shiftSize;

	// служебные методы

	// индекс в pМем для бита pos
	size_t GetMemIndex(size_t pos) const noexcept 
	{
		if (pos < 0 || pos > bitLen) { throw std::logic_error("Out of range."); }
		else { return memLen - pos / (sizeof(elem_type) * 8) - 1; }
	}

	// битовая маска для бита pos
	elem_type GetMemMask(size_t pos) const noexcept 
	{
		if (pos < 0 || pos > bitLen) { throw std::logic_error("Out of range."); }
		else { return 1 << (pos % (sizeof(elem_type) * 8)); }
	}

public:
	// обязательный функционал
	TBitField(size_t _BitLen) {
		if (_BitLen <= 0) { throw std::logic_error("Out of range."); }
		else {
			bitLen = _BitLen;
			memLen = (_BitLen - 1) / (8 * sizeof(elem_type)) + 1;
			pMem = new elem_type[memLen];
			for (int i = 0; i < memLen; i++) {
				pMem[i] = 0;
			}
		}
	}                            
	TBitField(const TBitField & bf)
	{
		bitLen = bf.bitLen;
		memLen = bf.memLen;
		pMem = new elem_type[memLen];
		for (int i = 0; i < memLen; i++) { 
			pMem[i] = bf.pMem[i]; 
		}
	}
	~TBitField() 
	{
		delete[] pMem;
	}

	TBitField& operator=(const TBitField& bf);
	/*TBitField& operator=(TBitField&& bf) noexcept;*/
	bool operator==(const TBitField& bf) const noexcept;
	bool operator!=(const TBitField& bf) const noexcept;

	bool test(size_t i) const;                             // получить значение бита i
	void set(size_t i);                                    // установить бит i
	void reset(size_t i);                                  // очистить бит i

	TBitField  operator|(const TBitField& bf);             // или
	TBitField  operator&(const TBitField& bf);             // и
	TBitField  operator~(void);                            // отрицание

	// получить длину (к-во битов)
	size_t size() const noexcept { return bitLen; }

	friend void swap(TBitField& lhs, TBitField& rhs) noexcept;

	// ввод/вывод
	friend std::ostream& operator<<(std::ostream& ostr, const TBitField& bf);
};


TBitField& TBitField::operator=(const TBitField& bf) 
{
	bitLen = bf.bitLen;
	memLen = bf.memLen;
	delete[] pMem;
	pMem = new elem_type[memLen];
	for (auto i = 0; i < memLen; i++) {
		pMem[i] = bf.pMem[i];
	}
	return *this;
}

bool TBitField::operator==(const TBitField& bf) const noexcept
{
	if (bitLen != bf.bitLen) { return 0; }
	else {
		for (auto i = 0; i < memLen; i++) {
			if (pMem[i] == bf.pMem[i]) { return 0; }
		}
	}
	return 1;
}

bool TBitField::operator!=(const TBitField& bf) const noexcept 
{
	return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField& bf) 
{
	int BitLen = bitLen;
	if (bf.bitLen > BitLen) { BitLen = bf.bitLen; }
	TBitField tb(bitLen);
	for (auto i = 0; i < memLen; i++) {
		tb.pMem[i] = pMem[i] | bf.pMem[i];
	}
	return tb;
}

TBitField TBitField::operator&(const TBitField& bf) 
{
	int BitLen = bitLen;
	if (bf.bitLen > BitLen) { BitLen = bf.bitLen; }
	TBitField tb(bitLen);
	for (auto i = 0; i < memLen; i++) {
		tb.pMem[i] = pMem[i] & bf.pMem[i];
	}
	return tb;
}

bool TBitField::test(size_t i) const 
{
	if (i < 0 || i >= bitLen) { throw std::length_error("Out of range"); }
	else { return pMem[GetMemIndex(i)] & GetMemMask(i); }
}

void TBitField::set(size_t i) 
{
	if (i < 0 || i >= bitLen) { throw std::length_error("Out of range"); }
	else { pMem[GetMemIndex(i)] = pMem[GetMemIndex(i)] | GetMemMask(i); }
}

TBitField TBitField::operator~(void) 
{
	TBitField bt(*this);
	for (int i = 0; i < bitLen; i++) {
		if (bt.test(i)) { bt.reset(i); }
		else { bt.set(i); }
	}
	return bt;
}

void TBitField::reset(size_t i) 
{
	if (i < 0 || i >= bitLen) { throw std::length_error("Out of range"); }
	else { pMem[GetMemIndex(i)] = pMem[GetMemIndex(i)] & (~GetMemMask(i)); }
}

void swap(TBitField& lhs, TBitField& rhs) noexcept
{
	std::swap(lhs, rhs);
}

std::ostream& operator<<(std::ostream& ostr, const TBitField& bf)
{
	for (int i = 0; i < bf.size(); ++i)
	{
		ostr << bf.test(i) << " ";
	}
	ostr << "\n";
	return ostr;
}

std::istream& operator>>(std::istream& istr, TBitField& bf) {
	for (int i = 0; i < bf.size(); ++i)
	{
		int in;
		istr >> in;
		if (in) bf.set(i);
	}
	return istr;
}

#endif  // INCLUDE_BITFIELD_H_
