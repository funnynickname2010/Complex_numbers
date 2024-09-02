#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <sstream>  

#define PI 3.141592653589793238462643383279502884
#define SEE_CONSTRUCTORS

class TCompl
{
private:

	double Re;
	double Im;

public:

	TCompl operator +(const TCompl& op2);
	TCompl operator -(const TCompl& op2);
	TCompl operator *(const TCompl& op2);
	TCompl operator /(const TCompl& op2); //Try catch
	TCompl operator ^(const int power);

	TCompl& operator =(const TCompl& op2);
	TCompl& operator +=(const TCompl& op2);
	TCompl& operator -=(const TCompl& op2);
	TCompl& operator *=(const TCompl& op2); 
	TCompl& operator /=(const TCompl& op2);

	bool operator ==(const TCompl& op2);
	bool operator !=(const TCompl& op2);

	TCompl(double re, double im);
	TCompl(double re);
	TCompl();
	TCompl(const TCompl& op2);
	~TCompl();

	//void Set(double re, double im);

	int ConvertToInt();

	//double GetRe() const;
	//double GetIm() const;

	friend std::istream& operator >>(std::istream& in, TCompl& c);
	friend std::ostream& operator <<(std::ostream& in, TCompl& c);
};
