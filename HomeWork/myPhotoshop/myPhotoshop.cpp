#include <iostream>
#include "BmpStructures.h"
#include "ImgFunctions.h"
#include "utils.h"

int main()
{	
	char filename[] = "test3.bmp";

	RgbImg img = read_rgb_img(filename);
	create_noice(img, 1500);
	write_rgb_img("out.bmp", img);

	std::cout << "Noice" << '\n';

	RgbImg new_img = to_black_white_img(img);
	write_rgb_img("out1.bmp", new_img);
	delete[] new_img.pixels;

	std::cout << "Black" << '\n';

	new_img = blur_filter(img, (size_t)1);
	write_rgb_img("out2.bmp", new_img);
	delete[] new_img.pixels;

	std::cout << "Blur" << '\n';

	new_img = median_filter(img, (size_t)1);
	write_rgb_img("out3.bmp", new_img);
	new_img = median_filter(img, (size_t)2);
	write_rgb_img("out4.bmp", new_img);
	new_img = median_filter(img, (size_t)5);
	write_rgb_img("out5.bmp", new_img);


	return 0;
}