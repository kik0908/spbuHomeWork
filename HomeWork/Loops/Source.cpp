#include <iostream>


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
	double x, eps;
	std::cin >> x >> eps;
	double sum = 1;
	double last = 1;

	while ( last >= eps) {
		last *= x;
		sum += last;
	}

	std::cout << sum;
}


void task3() {
	size_t n;
	std::cin >> n;
	for (size_t i = 1; i <= n; ++i) {
		for (size_t j = 1; j <= i; ++j) {
			std::cout << '*';
		}
		std::cout << '\n';
	}
}



int main() {

	return 0;
}