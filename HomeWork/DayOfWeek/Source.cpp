#include <iostream>


int main() {
	unsigned int day;
	
	std::cout << "Enter day: ";
	std::cin >> day;

	switch (day)
	{
		case 0: std::cout << "mon\n"; break;
		case 1: std::cout << "tue\n"; break;
		case 2: std::cout << "wed\n"; break;
		case 3: std::cout << "thur\n"; break;
		case 4: std::cout << "fri\n"; break;
		case 5: std::cout << "sat\n"; break;
		case 6: std::cout << "sun\n"; break;
		default: std::cout << "wrong num"; break;
	}

	system("pause");
	return 0;
}