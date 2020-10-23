#include <iostream>
#include <ctime>


int random(int start, int end) {
	return start + rand() % (end - start + 1);
}

void task1() {
	size_t M, N, A, B;

	std::cin >> M >> N >> A >> B;

	size_t** array = new size_t * [M];

	for (size_t i = 0; i < M; ++i) {
		array[i] = new size_t[N];
		for (size_t j = 0; j < N; ++j) {
			array[i][j] = random(A, B);
		}
	}

	for (size_t i = 0; i < M; ++i) {
		for (size_t j = 0; j < N; ++j) {
			std::cout << array[i][j] << '\t';
		}
		std::cout << '\n';
	}

	size_t* arr = new size_t[(M + N) * 2 - 4];
	size_t c = 0;
	for (size_t i = 0; i < N; ++i) {
		arr[c++] = array[0][i];
		arr[(M + N) * 2 - 4 - c - (M - 2)] = array[M - 1][i];
	}
	for (size_t i = 1; i < M - 1; ++i) {
		arr[c] = array[i][N - 1];
		arr[(c++) + N + 2] = array[i][0];
	}

	for (size_t i = 0; i < (M + N) * 2 - 4; ++i) {
		std::cout << arr[i] << ' ';
	}
}

int main() {
	task1();

	return 0;
}