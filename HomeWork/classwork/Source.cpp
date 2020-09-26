#include <iostream>


int main() {
	unsigned char val = 0;
	do {
		std::cout << (int)val++ << '\n';
	} while ((unsigned char)(val) > 0);

}