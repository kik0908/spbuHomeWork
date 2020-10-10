#include <iostream> 

int main() {
	double x1, x2, dx, eps;
	std::cin >> x1 >> x2 >> dx >> eps;

	double sum = 0;
	int n = 1;
	double term;

	while (x1 <= x2) {
		term = x1;
		sum = 0;
		do {
			sum += term;
			++n;
			term = -1 * term * x1 * x1 / ((2 * n - 1) * (2 * n - 2));
		} while (abs(term) >= eps);
	}

	return 0;
}