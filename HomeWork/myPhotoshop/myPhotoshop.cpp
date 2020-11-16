#include <iostream>
#include "BmpStructures.h"
#include "ImgFunctions.h"
#include "utils.h"

int main()
{
	RgbImg img = read_rgb_img("test.bmp");
	RgbImg new_img = to_black_white_img(img);
	write_rgb_img("out1.bmp", new_img);
	delete[] new_img.pixels;
	int arr[8] = { 8,4,5,1,3,2,3,7 };
	sort_by_choice(8, arr);
	for (size_t i = 0; i < 8; ++i) {
		std::cout << arr[i];
	}

	return 0;
}