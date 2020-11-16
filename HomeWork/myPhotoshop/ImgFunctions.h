#pragma once
#include "BmpStructures.h"

RgbImg read_rgb_img(char const filename[]);
void write_rgb_img(char const filename[], RgbImg const& img);
void print_rgb_img_info(char const filename[]);
RgbImg to_black_white_img(RgbImg image);
RgbImg blur_filter(RgbImg image, size_t size_of_blur);
RgbImg median_filter(RgbImg image, size_t size_of_blur);
void create_noice(RgbImg image, size_t count);