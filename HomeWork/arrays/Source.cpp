#include <iostream>
#include <ctime>


void task1() {
	const size_t w = 6, h = 4;
	int arr[h][w];
	
	size_t c = 1;
	bool flag1 = true, flag2 = false;
	for (size_t i = 0; i < h; ++i) {
		if (i % 2 == 0) {
			for (size_t j = 0; j < w; ++j) {
				arr[i][j] = c++;
			}
		}
		else {
			for (size_t j = w; j > 0; --j) {
				arr[i][j-1] = c++;
			}
		}
	}

	for (size_t i = 0; i < h; ++i) {
		for (size_t j = 0; j < w; ++j) {
			std::cout << arr[i][j] << '\t';
		}
		std::cout << '\n';
	}

}




int main() {

	task1();

}