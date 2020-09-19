#include <iostream>


int main() {
	unsigned int n;
	std::cout << "enter max n: ";
	std::cin >> n;
	unsigned int counter = 0;
	double sum = 0;
	while (++counter <= n) {
		sum += (double) 1 / counter;
	}

	sum = 0;
	counter = 1;
	
	do {
		sum += (double)1 / counter++;
	}
	while (counter <= n);
	
	sum = 0;

	for (int cntr = 1; cntr <= n; sum += 1. / cntr, ++cntr) {
		//sum += 1. / cntr;
	}


	std::cout << "Harmonic row sum is " << sum << '\n';

	system("pause");
	return 0;
}