#include <iostream>
using namespace std;


int nod(int x, int y) {
	while (x != y) {
		if (x > y) { x = x - y; }
		else { y = y - x; }
	}
	return y;
}
int nok(int x, int y) {
	return x * y / nod(x, y);
}

enum rationalERRORDiv {
	DivisionByZero
};
class rational {
protected:
	int numerator;
	int denumerator;
public:
	rational(int _numerator, int _denumerator) {
		numerator = _numerator;
		denumerator = _denumerator;
	}
	rational(const rational& num) {
		numerator = num.numerator;
		denumerator = num.denumerator;
	}
	rational() :denumerator(1), numerator(0) {};

	int getNumerator() { return numerator; }
	int getDenumerator() { return denumerator; }
	void setNumerator(int _numerator) { numerator = _numerator; }
	void setDenumerator(int _denumerator) {
		if (_denumerator != 0) { denumerator = _denumerator; }
		else { throw DivisionByZero; }
	}

	rational operator+(const rational& num) {
		int NOK = nok(num.denumerator, this->denumerator);
		this->numerator = this->numerator * (NOK / this->denumerator) + num.numerator * (NOK / num.denumerator);
		this->denumerator = NOK;
		return rational{ this->numerator, this->denumerator };
	}


	rational operator*(const rational& num) {
		this->numerator = num.numerator * this->numerator;
		this->denumerator = num.denumerator * this->denumerator;
		return rational{ this->numerator, this->denumerator };
	}
	
	rational operator/(const rational& num) {
		this->numerator = this->numerator * num.denumerator;
		this->denumerator = this->denumerator * num.numerator;
		return rational{ this->numerator, this->denumerator };
	}

	rational operator-(const rational& num) {
		int NOK = nok(num.denumerator, this->denumerator);
		this->numerator = this->numerator * (NOK / this->denumerator) - num.numerator * (NOK / num.denumerator);
		this->denumerator = NOK;
		return rational{ this->numerator, this->denumerator };
	}

	rational operator=(const rational& num) {
		numerator = num.numerator;
		denumerator = num.denumerator;
		return rational(numerator, denumerator);
	}

	void printff() {
		cout << this->numerator << " " << this->denumerator << endl;
	}

	void rationalSimplify(const rational& NUM) {
		int NOK = nok(this->numerator, this->denumerator);
		this->numerator = this->numerator / NOK;
		this->denumerator = this->denumerator / NOK;
	}
};

class rationalWithIntPart : public rational {
	int intPart;
public:
	int getIntPart() { return this->intPart; }
	void setIntPart(int intPart) { this->intPart = intPart; }
	rationalWithIntPart() = default;
	rationalWithIntPart(int _IntPart, int _Num, int _Denum) {
		if (_Denum != 0) {
			this->setDenumerator(_Denum);
			this->setNumerator(_Num);
			this->intPart = _IntPart;
		}
		else { throw DivisionByZero; }
	};
	rationalWithIntPart(const rationalWithIntPart& NUMBER) {
		this->setDenumerator(NUMBER.denumerator);
		this->setNumerator(NUMBER.numerator);
		this->intPart = NUMBER.intPart;
	};

	void rationalSelectInt(const rationalWithIntPart& NUMBER) {
		this->intPart = this->getNumerator() / this->getDenumerator();
		this->setNumerator(this->getNumerator() % this->getDenumerator());
	}

	void Print() {
		cout << this->intPart << " " << this->numerator << " " << this->denumerator << endl;
	}
};
void main() {
	rationalWithIntPart n1(2, 4, 5);
	rationalWithIntPart n2;
	n2.rationalSelectInt(n2);
	n2.Print();
}