#include <iostream>
#include <cmath>


void homeWorkTask1() {
	double a, b, c;

	std::cout << "Enter the arguments a, b and c: ";
	std::cin >> a >> b >> c;

	double d = b * b - 4 * a * c;
	if (d < 0) std::cout << "No roots";
	else if (d == 0) std::cout << (-b) / (2 * a);
	else std::cout << (b + std::sqrt(d)) / (2 * a) << " " << (b - std::sqrt(d)) / (2 * a);
}


void homeWorkTask2() {
	double x, y, r, R;
	std::cout << "Enter x and y: ";
	std::cin >> x >> y;
	std::cout << "Enter r and R: ";
	std::cin >> r >> R;

	x *= x;
	y *= y;
	r *= r;
	R *= R;

	if (x + y > r && x + y < R) std::cout << "Yes";
	else std::cout << "No";
}


void homeWorkTask3() {
	int num, n;
	std::cout << "Enter num and index of byte: ";
	std::cin >> num >> n;

	int a;
	a = (num & (1 << n)) >> n;
	std::cout << a;
}


void homeWorkTask4() {
	int num, n;
	std::cout << "Enter num and index of byte: ";
	std::cin >> num >> n;

	int a;
	a = num | (1 << n);
	std::cout << a;
}


void homeWorkTask5() {
	int num, n;
	std::cout << "Enter num and index of byte: ";
	std::cin >> num >> n;

	int a;
	a = num & ~(1 << n);
	std::cout << a;
}


void homeWorkTask6() {
	int num, n;
	std::cout << "Enter num and index of byte: ";
	std::cin >> num >> n;

	int a;
	a = num ^ (1 << n);
	std::cout << a;
}


void homeWorkTask7() {
	int num;
	std::cout << "Enter num: ";
	std::cin >> num;
	if ((num & (num - 1)) == 0) std::cout << "Yes, it is power of 2";
	else std::cout << "No, it is not power of 2";
}



int main() {

	return 0;
}