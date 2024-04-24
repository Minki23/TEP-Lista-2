#include <iostream>
#include <string>
#include "CNumber.h"

const int default_lenght = 1;

int CNumber::operator>=(int number) {
	number = 0;
	for (int i = 0;i < isize;++i) {
		number += number_table[isize-i-1] * pow(10, isize - i - 1);
	}
	if (negative) {
		number *= -1;
	}
	return number;
};
CNumber& operator>=(int number,CNumber& c_other_number) {
	c_other_number = number;
	return c_other_number;
};
CNumber& CNumber::operator>=(CNumber& c_other_number) {
	c_other_number = *this;
	return c_other_number;
};

CNumber::CNumber()
{
	isize = default_lenght;
	number_table = new int[isize];
	for (int i = 0;i < isize;++i) {
		number_table[i] = 0;
	}
	negative = false;
};

CNumber::CNumber(int const value)
{
	negative = value < 0 ? true : false;
	isize = value == 0 ? 1 : int(log10(abs(value)) + 1);
	number_table = new int[isize];
	for (int i = 0;i < isize;++i) {
		*(number_table + i) = int(abs(value) / pow(10, i)) % 10;
	}
}; 

CNumber::CNumber(const CNumber& tocopy) {
	this->isize = tocopy.isize;
	this->number_table = new int[this->isize];
	this->negative = tocopy.negative;
	for (int i = 0;i < this->isize;i++) {
		this->number_table[i] = tocopy.number_table[i];
	}
}

CNumber::~CNumber()
{
	delete[] number_table;
}

std::string CNumber::sToStr() {
	std::string nString = "";
	for (int i = 0; i < isize; ++i) {
		nString = std::to_string(number_table[i]) + nString;
	}
	if (negative) {
		nString = "-"+nString;
	}
	return nString;
}

CNumber& CNumber::operator=(const int value) {
	delete[] number_table;
	negative = value < 0 ? true : false;
	isize = value==0 ? 1:int(log10(abs(value)) + 1);
	number_table = new int[isize];
	for (int i = 0;i < isize;++i) {
		*(number_table + i) = int(abs(value) / pow(10, i)) % 10;
	}
	return *this;
}

CNumber& CNumber::operator=(CNumber c_num_other) {
	isize = c_num_other.isize;
	std::swap(negative, c_num_other.negative);
	std::swap(number_table, c_num_other.number_table);
	return *this;
}

CNumber CNumber::operator+(const CNumber& c_num_other) {
	CNumber result;
	if (negative == c_num_other.negative) {
		result.isize = std::max(isize, c_num_other.isize) + 1;
		result.number_table = new int[result.isize];
		for (int i = 0; i < result.isize; i++) {
			result.number_table[i] = 0;
		}
		int carry = 0;
		for (int i = 0; i < result.isize; i++) {
			const int sum = carry + (i < isize ? number_table[i] : 0) + (i < c_num_other.isize ? c_num_other.number_table[i] : 0);
			result.number_table[i] = sum % 10;
			carry = sum / 10;
		}
		while (result.number_table[result.isize - 1] == 0 && result.isize > 1) {
			result.isize--;
		}
		result.negative = negative;
	}
	else {
		CNumber copy = c_num_other;
		CNumber copythis = *this;
		result = negative ? copy - (copythis).negate() : *this - copy.negate();
	}
	return result;
}

CNumber CNumber::operator-(const CNumber& c_num_other) {
	CNumber result;
	if (negative == c_num_other.negative) {
		if (*this < c_num_other) {
			CNumber copy = c_num_other;
			result = copy - *this;
			result.negate();
			return result;
		}

		result.isize = std::max(isize, c_num_other.isize);
		result.number_table = new int[result.isize];
		for (int i = 0; i < result.isize; i++) {
			result.number_table[i] = 0;
		}

		int borrow = 0;
		for (int i = 0; i < result.isize; i++) {
			int diff = number_table[i] - borrow - (i < c_num_other.isize ? c_num_other.number_table[i] : 0);
			if (diff < 0) {
				diff += 10;
				borrow = 1;
			}
			else {
				borrow = 0;
			}
			result.number_table[i] = diff;
		}

		while (result.number_table[result.isize - 1] == 0 && result.isize > 1) {
			result.isize--;
		}

		result.negative = negative;
	}
	else {
		CNumber copy = c_num_other;
		CNumber copythis = *this;
		result = negative ? ((copythis).negate() + copy).negate() : *this + copy.negate();
	}
	return result;
}

CNumber CNumber::operator*(const CNumber& c_num_other) {
	CNumber result;
	delete[] result.number_table;
	if ((*this).isZero() || c_num_other.isZero()) {
		result.isize = 1;
		result.number_table = new int[result.isize];
		result.number_table[0] = 0;
		return result;
	}
	result.isize = isize + c_num_other.isize;
	result.number_table = new int[result.isize];
	for (int i = 0; i < result.isize; i++) {
		result.number_table[i] = 0;
	}
	for (int i = 0; i < isize; i++) {
		for (int j = 0; j < c_num_other.isize; j++) {
			const int sum = number_table[i] * c_num_other.number_table[j] + result.number_table[i + j];
			result.number_table[i + j] = sum % 10;
			result.number_table[i + j + 1] += sum / 10;
		}
	}
	while (result.number_table[result.isize - 1] == 0 && result.isize > 1) {
		result.isize--;
	}
	if (negative != c_num_other.negative) {
		result.negative = true;
	}
	return result;
}

CNumber& CNumber::negate() {
	negative = !negative;
	return *this;
}

bool CNumber::operator<(const CNumber& c_num_other) {
	if (negative != c_num_other.negative) {
		return negative ? true : false;
	}
	if(isize!=c_num_other.isize)
		return isize < c_num_other.isize ? true : false;
	for (int i = isize-1;i >=0 ;--i) {
		if (number_table[i] != c_num_other.number_table[i]) {
			return number_table[i] < c_num_other.number_table[i] ? true : false;
		}
	}
	return false;
}

CNumber CNumber::operator/(const CNumber& c_num_other) {
	if (c_num_other.isZero()) {
		return CNumber(0);
	}

	CNumber result;
	result.isize = isize;
	CNumber remainder=c_num_other;
	CNumber copy = *this;
	int counter=0;
	if ((*this).negative) {
		copy.negative=false;
	}
	if (remainder.negative) {
		remainder.negative = false;
	}
	while (remainder<copy || (remainder - copy).isZero())
	{
		counter++;
		copy = copy - remainder;
	}
	if ((negative || c_num_other.negative) && negative != c_num_other.negative) {
		counter *= -1;
	}
	result = counter;
	return result;
}

bool CNumber::isZero() const {
	return isize == 1 && number_table[0] == 0;
}
