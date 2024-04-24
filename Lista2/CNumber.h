#pragma once
	class CNumber
	{
	public:
		CNumber();
		CNumber(const int value);
		CNumber(const CNumber& tocopy);
		~CNumber();

		CNumber& operator=(const int iValue);
		CNumber& operator=(CNumber c_num_other);
		CNumber operator+(const CNumber& c_num_other);
		CNumber operator-(const CNumber& c_num_other);
		CNumber operator*(const CNumber& c_num_other);
		CNumber operator/(const CNumber& c_num_other);

		std::string sToStr();
		bool operator<(const CNumber& c_num_other);

		int operator>=(int number);
		CNumber& operator>=(CNumber& c_other_number);
		friend CNumber& operator>=(int number, CNumber& c_other_number);

	private:
		bool negative;
		int isize;
		int* number_table;
		CNumber& negate();
		bool isZero() const;
	};

