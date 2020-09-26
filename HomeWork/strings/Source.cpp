#include <iostream>


int main() {
	char str[] = "Hello";
	char hell[] = { 'h', 'e', 'l', 'l' };
	std::cout << str << '\n';
	std::cout << hell << '\n';
	hell[17] = 'w';
	std::cout << str << '\n';
	std::cout << hell << '\n';
	std::cout << strlen(str) << '\n';
	char strcp[100];
	strcpy_s(strcp, str);
	std::cout << strcp;

	return 0;
}