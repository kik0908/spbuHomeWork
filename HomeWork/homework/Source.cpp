#include <iostream>
#include "windows.h"
#include <cmath>  

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
		for (size_t j = 0; j < h - i - 1; ++j) {
			std::cout << ' ';
		}
		for (size_t j = 0; j < i * 2 + 1; ++j) {
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
		for (int j = 0; j < 2 * (h1 - abs((int)(h1 - i) - 1)) - 1; ++j) {
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

		if (i != 0 and i != h - 1) std::cout << '*';
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

	std::cout << "Sum is " << ' ' << sum << '\n';
	std::cout << "Formula give answer is " << ' ' << 1.0 / (1.0 - x);
	std::cout << "Eps is " << abs(1.0 / (1.0 - x) - sum);
}

void task6() {
	std::cout << "Enter count of sinus and radians: ";
	double radians, n;
	std::cin >> n >> radians;
	for (size_t i = 0; i < n; ++i) {
		radians = sin(radians);
	}
	std::cout << radians;

}

void task7() {
	std::cout << "Input eps: ";
	double eps, c, pi;
	short d;
	d = 1;
	std::cin >> eps;
	c = 1;
	pi = 0;
	while (1. / c > eps) {
		pi += (1. / c * d);
		c += 2;
		d *= -1;
	}
	pi *= 4.0;
	std::cout << pi;
}


long double power(double x, int n) {
	long double ans = 1;
	for (int i = 0; i < n; ++i) {
		ans *= x;
	}

	return ans;
}

size_t fact(size_t n) {
	size_t ans = 1;
	for (size_t i = 2; i <= n; ++i) {
		ans *= i;
	}
	return ans;
}

//void task8() {
//	size_t n, d;
//	int  числитель, zn;
//	double ans;
//	int x;
//	std::cin >> x >> n;
//	d = 1;
//	std::cout << "n  \tans\n";
//	for (size_t i = 1; i <= n; i++) {
//		числитель = power(x, 2 * i + 1);
//		zn = fact(2 * n - 1);
//		std::cout << i << '\t' << (double)числитель / zn * d << '\n';
//		d *= -1;
//	}
//}


void task9() {
	size_t num;
	bool byte;
	size_t count = 0;
	std::cin >> num;
	while (num > 0) {
		byte = num & 1;
		if (byte == true) count += 1;
		byte = false;
		num >>= 1;
	}
	std::cout << count;
}


void task10() {
	size_t num;
	short razr;
	short b = sizeof(num)*8;
	std::cin >> num >> razr;
	razr = razr % b;
	num = (num >> razr) | (num << abs(((b - razr) % b)));
	std::cout << num;
}


int main() {

	task10();

	return 0;
}