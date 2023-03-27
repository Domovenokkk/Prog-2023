#include <iostream>



int NOD(int x, int y) {
	int num;
	if (x < y) {
		num = x;
	}
	else {
		num = y;
	}
	for (int i = 2; i < num; i++) {
		if (!(x % i) && !(y & i)) {
			return i;
		}
		else return 1;
	}
}

class RationalNum {
protected:
	int numeration;
	int denomination;
	friend class RationalWithintPart;
public:
	RationalNum() = default;

	RationalNum(int _numeration, int _denomination) {
		numeration - _numeration;
		denomination - _denomination;
	}

	RationalNum(const RationalNum& num) {
		numeration = num.numeration;
		denomination = num.denomination;
	}


	void SetNumeration(int _numeration) {
		numeration = _numeration;
	}
	void SetDenomination(int _denomination) {
		denomination = _denomination;
	}
	int GetNumeration(int numeration) {
		return numeration;
	}
	int GetDenomination(int denomination) {
		return denomination;
	}


	RationalNum RationalAdd(const RationalNum& right) {
		RationalNum result;
		if (denomination == right.denomination) {
			result.numeration += right.numeration;
		}
		else {
			int denom = denomination;
			result.denomination = NOD(denomination, right.denomination);
			denom = denomination / denom;
			result.numeration = numeration * denom + right.numeration * denom;
			delete& denom;
		}
		return result;
	}

	RationalNum RationalSub(const RationalNum& right) {
		RationalNum result;
		if (denomination == right.denomination) {
			result.numeration += right.numeration;
		}
		else {
			int denom = denomination;
			result.denomination = NOD(denomination, right.denomination);
			denom = denomination / denom;
			result.numeration = numeration * denom + right.numeration * denom;
			delete& denom;
		}
		return result;
	}

	RationalNum RationalMult(const RationalNum& right) {
		RationalNum result;
		result.numeration = numeration * right.numeration;
		result.denomination = denomination * right.denomination;
		return result;
	}

	RationalNum RationalDiv(const RationalNum& right) {
		RationalNum result;
		result.numeration = numeration * right.denomination;
		result.denomination = denomination * right.numeration;
		return result;
	}

	void Simply() {
		denomination = denomination / NOD(numeration, denomination);
		numeration = numeration / NOD(numeration, denomination);
	}

};


class RationalWithintPart : RationalNum {
	int integer;
public:
	RationalWithintPart() = default;
	RationalWithintPart(int _numenation, int _denomination, int _integer) : RationalNum(_numenation, _denomination), integer(_integer) {}
	RationalWithintPart(const RationalNum& One) : RationalNum(One.numeration, One.denomination) {
		integer = 0;
		numeration = One.numeration;
		denomination = One.denomination;
	}
	RationalWithintPart(const RationalWithintPart& One) : RationalNum(One.numeration, One.denomination) {
		integer = One.integer;
		numeration = One.numeration;
		denomination = One.denomination;
	}
	void SetInteget(int _integer) {
		integer = _integer;
	}
	int GetInteger(int integer) {
		return integer;
	}

	RationalWithintPart WholePart(const class RationalNum& integer) {
		RationalWithintPart result;
		int k = 0;
		while (result.numeration > result.denomination) {
			k += 1;
			result.numeration -= result.denomination;
		}
		result.integer = k;
		return result;
	}
};


int main() {

}