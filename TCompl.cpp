#include "TCompl.h"

std::istream& operator>>(std::istream& in, TCompl& c)
{
	char operation = '\n';
	std::string input;

	// Read the input into a string buffer, handling spaces or newlines
	std::getline(in >> std::ws, input);

	std::istringstream iss(input);

	if (iss.peek() == '-')
	{
		iss >> operation;
		if (iss.peek() == 'i')
		{
			iss.ignore();
			c.Re = 0;
			c.Im = -1;
			return in;
		}
	}
	else if (iss.peek() == 'i')
	{
		iss.ignore();
		c.Re = 0;
		c.Im = 1;
		return in;
	}

	iss >> c.Re;
	if (operation == '-')
	{
		c.Re = -c.Re;
	}

	if (iss.peek() == 'i')
	{
		iss.ignore();
		c.Im = c.Re;
		c.Re = 0;
		return in;
	}

	iss >> std::ws; // Skip leading whitespace

	if (iss.peek() == '+' || iss.peek() == '-')
	{
		iss >> operation;
		if (iss.peek() == 'i')
		{
			iss.ignore();
			c.Im = (operation == '-') ? -1 : 1;
		}
		else
		{
			iss.putback(operation);
			iss >> c.Im;
		}
	}
	else
	{
		c.Im = 0;
	}

	// Clear any error flags that may have been set on the stream
	in.clear();

	return in;
}

std::ostream& operator <<(std::ostream& in, TCompl& c)
{
	char operation;

	if (c.Im > 0 && c.Im != 1 && c.Im != -1)
	{
		operation = '+';
		std::cout << c.Re << ' ' << operation << ' ' << c.Im << 'i';
	}
	else if (c.Im < 0 && c.Im != 1 && c.Im != -1)
	{
		operation = '-';
		std::cout << c.Re << ' ' << operation << ' ' << (c.Im * (-1)) << 'i';
	}
	else if (c.Im == 1)
	{
		operation = '+';
		std::cout << c.Re << ' ' << operation << ' ' << 'i';
	}
	else if (c.Im == -1)
	{
		operation = '-';
		std::cout << c.Re << ' ' << operation << ' ' << 'i';
	}
	else if (c.Im == 0)
	{
		std::cout << c.Re;
		return in;
	}

	return in;
}

TCompl::TCompl()
{
	Re = 0;
	Im = 0;

#ifdef SEE_CONSTRUCTORS
	std::cout << "Default constructor invoked" << std::endl;
#endif
}

TCompl::TCompl(double re, double im)
{
	Re = re;
	Im = im;

#ifdef SEE_CONSTRUCTORS
	std::cout << "2 parameters constructor invoked" << std::endl;
#endif
}

TCompl::TCompl(double re)
{
	Re = re;
	Im = 0;

#ifdef SEE_CONSTRUCTORS
	std::cout << "1 parameter constructor invoked" << std::endl;
#endif
}

TCompl::TCompl(const TCompl& op2)
{
	Re = op2.Re;
	Im = op2.Im;

#ifdef SEE_CONSTRUCTORS
	std::cout << "Copy constructor invoked" << std::endl;
#endif
}

TCompl::~TCompl()
{
#ifdef SEE_CONSTRUCTORS
	std::cout << "Destructor invoked" << std::endl;
#endif
}

double TCompl::GetRe()
{
	return Re;
}

double TCompl::GetIm()
{
	return Im;
}

bool TCompl::operator ==(const TCompl& op2)
{
	return ((Re == op2.Re) && (Im == op2.Im));
}

bool TCompl::operator !=(const TCompl& op2)
{
	return !((Re == op2.Re) && (Im == op2.Im));
}

TCompl& TCompl::operator =(const TCompl& op2)
{
	if (*this != op2)
	{
		Re = op2.Re;
		Im = op2.Im;
	}
	return *this;
}

TCompl& TCompl::operator +=(const TCompl& op2)
{
	Re += op2.Re;
	Im += op2.Im;
	return *this;
}

TCompl& TCompl::operator -=(const TCompl& op2)
{
	Re -= op2.Re;
	Im -= op2.Im;
	return *this;
}

TCompl& TCompl::operator *=(const TCompl& op2)
{
	*this = *this * op2;
	return *this;
}

TCompl& TCompl::operator /=(const TCompl& op2)
{
	*this = *this / op2;
	return *this;
}

TCompl TCompl::operator +(const TCompl& op2) 
{
	TCompl res;
	res.Re = Re + op2.Re;
	res.Im = Im + op2.Im;

	return res;
}

TCompl TCompl::operator -(const TCompl& op2)
{
	TCompl res;
	res.Re = Re - op2.Re;
	res.Im = Im - op2.Im;

	return res;
}

TCompl TCompl::operator *(const TCompl& op2) //Check
{
	TCompl res;
	res.Re = Re * op2.Re - Im * op2.Im;
	res.Im = Re * op2.Im + Im * op2.Re;

	return res;
}

TCompl TCompl::operator /(const TCompl& op2)
{
	TCompl res;

	try
	{
		if ((op2.Re * op2.Re + op2.Im * op2.Im) == 0)
		{
			throw std::runtime_error("Error. Division by zero. \n");
		}
		else
		{
			res.Re = (Re * op2.Re + Im * op2.Im) / (op2.Re * op2.Re + op2.Im * op2.Im);
			res.Im = (Im * op2.Re - Re * op2.Im) / (op2.Re * op2.Re + op2.Im * op2.Im);
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return res;
}

TCompl TCompl::operator ^(const int power)
{
	TCompl res(0, 0);
	double r, angle;
	bool need_calculations = 1;

	r = sqrt(Re * Re + Im * Im);

	if (Re == 0 && Im == 0 && power != 0)
	{
		res = 0;
		need_calculations = 0;
	}
	else if (Re == 0 && Im == 0 && power == 0)
	{
		std::cout << "\n Error: 0 in power 0, undefined result.\n";
		res = 0;
		need_calculations = 0;
	}
	else if (power == 0)
	{
		res = 1;
		need_calculations = 0;
	}
	else if (Re != 0)
	{
		angle = atan(Im / Re);

		if (((Im / Re) > 0) && Im < 0) //3-rd quarter
		{
			angle += PI;
		}
		else if (((Im / Re) < 0) && Im < 0) //4-th quarter
		{
			angle += PI;
		}
	}
	else if (Im != 0 && Re == 0)
	{
		if (Im > 0)
		{
			angle = asin(1);
		}
		else if (Im < 0)
		{
			angle = asin(-1);
		}
	}

	if (need_calculations)
	{
		angle = angle * power;

		res.Re = pow(r, power) * cos(angle);
		res.Im = pow(r, power) * sin(angle);
	}

	return res;
}

void TCompl::Set(double re, double im)
{
	Re = re;
	Im = im;
}