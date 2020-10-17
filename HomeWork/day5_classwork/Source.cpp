#include <iostream>


void task1() {
	int n;
	std::cin >> n;
	long long int* arr = new long long int[n];
	long long int buff, sum;
	sum = 1;
	buff = 1;

	arr[0] = buff;
	for (size_t i = 1; i <= n; ++i) {
		//sum += buff;
		buff *= 2;
		arr[i] = buff;
		sum += buff;
	}

	for (size_t i = 0; i <= n; ++i) {
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
	std::cout << sum;

	delete[] arr;


}

void task2() {
	int n, m;
	size_t c;
	c = 1;

	size_t sum1=0, sum2=0;

	std::cin >> n >> m;

	size_t** arr = new size_t*[n];

	for (size_t i = 0; i < n; ++i) {
		arr[i] = new size_t[m];
		for (size_t j = 0; j < m; ++j) {
			arr[i][j] = c++;  
			if (i == j) sum1 += arr[i][j];
			if (n - i == j+1) sum2 += arr[i][j];
		}
	}

	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < m; ++j) {
			std::cout << arr[i][j] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << sum1 << ' ' << sum2;

	for (size_t i = 0; i < n; ++i) {
		delete[] arr[i];
	}
	delete[] arr;

}


int main() {
	task2();

	return 0;
}