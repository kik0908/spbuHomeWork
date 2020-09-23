#include <iostream>
#include "windows.h"

void translateTemp() {
	double fs, ff, df;
	std::cin >> fs >> ff >> df;
	std::cout.precision(5);

	std::cout << "T far\tT cel\tstate\n";
	for (fs; fs <= ff; fs += df) {
		double celsius = 5. / 9 * (fs - 32);
		std::cout << " " << fs << "\t" << celsius << "\t";
		if (celsius > 30)
			std::cout << "hot\n";
		else if (celsius < 15)
			std::cout << "cold\n";
		else
			std::cout << "norm\n";

	}

	system("pause");
}



long double power(double x, int n) {
	long double ans = 1;
	for (int i = 0; i <= n; ++i) {
		ans *= x;
	}

	return ans;
}


void task2() {
	size_t n;
	std::cin >> n;
	for (size_t i = 1; i <= n; ++i) {
		for (size_t j = 1; j <= i; ++j) {
			std::cout << '*';
		}
		std::cout << '\n';
	}
}


void task3() {
	size_t h;
	std::cin >> h;
	for (size_t i = 0; i < h; ++i) {
		for (size_t j = 0; j < h-i-1; ++j) {
			std::cout << ' ';
		}
		for (size_t j = 0; j < i*2+1; ++j) {
			std::cout << '*';
		}
		std::cout << '\n';
	}
}


void task4_1() {
	size_t h, h1;
	std::cout << "Enter height: ";
	std::cin >> h;
	h -= h % 2 ^ 1;
	h1 = h / 2 + h % 2;
	for (size_t i = 0; i < h; ++i) {
		for (size_t j = 0; j < abs((int)(h1 - i) - 1); ++j) {
			std::cout << ' ';
		}
		for (int j = 0; j < 2*(h1 - abs((int)(h1 - i) - 1))-1; ++j) {
			std::cout << '*';
		}
		std::cout << '\n';
	}
}


void task4_2() {
	size_t h, h1;
	std::cout << "Enter height: ";
	std::cin >> h;
	h -= h % 2 ^ 1;
	h1 = h / 2 + h % 2;
	for (size_t i = 0; i < h; ++i) {
		for (size_t j = 0; j < abs((int)(h1 - i) - 1); ++j) {
			std::cout << ' ';
		}
		std::cout << '*';
		for (int j = 1; j < 2 * (h1 - abs((int)(h1 - i) - 1)) - 2; ++j) {
			std::cout << ' ';
		}

		if (i != 0 and i != h-1) std::cout << '*';
		std::cout << '\n';
	}
}


void task4_3() {
	size_t h, h1;
	std::cout << "Enter height: ";
	std::cin >> h;
	h -= h % 2 ^ 1;
	h1 = h / 2 + h % 2;
	for (size_t i = 0; i < h; ++i) {
		for (size_t j = 0; j < abs((int)(h1 - i) - 1); ++j) {
			std::cout << ' ';
		}
		for (int j = 0; j < 2 * (h1 - abs((int)(h1 - i) - 1)) - 1; ++j) {
			if (j % 2 == 0) std::cout << '*';
			else std::cout << ' ';
		}
		std::cout << '\n';
	}
}

void task5() {
	double x, eps;
	std::cin >> x >> eps;
	double sum = 1;
	double last = 1;

	while (last >= eps) {
		last *= x;
		sum += last;
	}

	std::cout << sum;
}


int main() {

	task4_2();

	return 0;
}