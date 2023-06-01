#include "TCompl.h"
#include <string>
#include <cmath>

void interface_input(TCompl& x, TCompl& y);
void interface_input(TCompl& x, double& y);
void interface_options();

int main()
{
	
	TCompl a, b;
	int operation_id;
	TCompl res;

	interface_input(a, b);

	do
	{
		interface_options();

		std::cin >> operation_id;

		switch (operation_id)
		{
			std::cin >> operation_id;

		case 1:

			res = a + b;
			break;

		case 2:

			res = a - b;
			break;

		case 3:

			res = a * b;
			break;

		case 4:

			res = a / b;
			break;

		case 5:

			res = a = b;
			break;

		case 6:

			res = a += b;
			break;

		case 7:
			res = a -= b;
			break;

		case 8:

			res = a *= b;
			break;

		case 9:

			res = a /= b;
			break;

		case 10:

			res = a == b;
			break;

		case 11:

			res = a != b;
			break;

		case 12:

			int b_int;

			if (b.GetIm() == 0 && (abs(round(b.GetRe()) - b.GetRe()) < std::numeric_limits<double>::epsilon()))
			{
				b_int = static_cast<int>(round(b.GetRe()));
			}
			else
			{
				std::cout << "Input b as an int: ";
				std::cin >> b_int;
				b = b_int; //Changing "original" b complex number to 0 + 0i
			}
			
			res = a ^ b_int;
			break;

		case 13:
			std::cin.ignore();
			interface_input(a, b);
			break;

		case 14:

			break;
		}

		if (operation_id != 13)
		{
			std::cout << "\n ----Operation details---- \n";
			std::cout << "a: " << a << '\n';
			std::cout << "b: " << b << '\n';
			std::cout << "returned value: " << res << std::endl << std::endl;
		}
		
	}	while (operation_id != 14);

	
	
	return 0;
}

void interface_input(TCompl& x, TCompl& y)
{
	std::cout << "Expression format: \na <operation> b\n";

	std::cout << "Input a: ";
	std::cin >> x;
	std::cout << "Input b: ";
	std::cin >> y;
}

void interface_input(TCompl& x, double& y)
{
	std::cout << "Expression format: \na <operation> b\n";

	std::cout << "Input a: ";
	std::cin >> x;
	std::cout << "Input b: ";
	std::cin >> y;
	std::cin.ignore();
}

void interface_options()
{
	std::cout << "\nWhich operation do you want to test?\n";
	std::cout << "1. +\n";
	std::cout << "2. -\n";
	std::cout << "3. *\n";
	std::cout << "4. /\n";
	std::cout << "5. =\n";
	std::cout << "6. +=\n";
	std::cout << "7. -=\n";
	std::cout << "8. *=\n";
	std::cout << "9. /=\n";
	std::cout << "10. ==\n";
	std::cout << "11. !=\n";
	std::cout << "12. Test a^b, where b is int. New input is needed.\n";
	std::cout << "13. Change the variables' values\n";
	std::cout << "14. Exit\n\n";
}