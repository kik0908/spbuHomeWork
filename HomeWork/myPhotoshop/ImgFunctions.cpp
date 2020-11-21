#include "ImgFunctions.h"
#include <fstream>
#include <exception>
#include <iostream>
#include "utils.h"

RgbImg read_rgb_img(const char filename[])
{
    std::ifstream bmp_in(filename, std::ios::binary);
    if (!bmp_in.is_open())
        throw std::runtime_error("Failed to open input file");

    BITMAPFILEHEADER bmfh;
    BITMAPINFOHEADER bmih;

    bmp_in.read((char*)&bmfh, sizeof(BITMAPFILEHEADER));
    bmp_in.read((char*)&bmih, sizeof(BITMAPINFOHEADER));

    RgbImg img;
    img.height = bmih.biHeight;
    img.width = bmih.biWidth;
    img.pixels = new RGB * [img.height];

    for (size_t row = 0; row < img.height; ++row)
    {
        img.pixels[row] = new RGB[img.width];
        for (size_t col = 0; col < img.width; ++col)
            bmp_in.read((char*)&img.pixels[row][col], 3);
    }

    bmp_in.close();
    return img;
}

void write_rgb_img(char const filename[], RgbImg const& img)
{
    std::ofstream bmp_out(filename, std::ios::binary);
    if (!bmp_out.is_open())
        throw std::runtime_error("Failed to open output file");

    BITMAPFILEHEADER bmfh;
    char bfType[] = { 'B', 'M' };
    bmfh.bfType = *((WORD*)bfType); // ('M' << 8) | 'B';
    bmfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    bmfh.bfSize = bmfh.bfOffBits + img.height * img.width * 3;
    bmfh.bfReserved1 = bmfh.bfReserved2 = 0;

    BITMAPINFOHEADER bmih;
    bmih.biClrImportant = bmih.biClrUsed = bmih.biCompression = 0;
    bmih.biPlanes = bmih.biXPelsPerMeter = bmih.biYPelsPerMeter = 1;
    bmih.biSize = sizeof(BITMAPINFOHEADER);
    bmih.biSizeImage = bmfh.bfSize - bmfh.bfOffBits;
    bmih.biHeight = img.height;
    bmih.biWidth = img.width;
    bmih.biBitCount = 24;

    bmp_out.write((char*)&bmfh, sizeof(BITMAPFILEHEADER));
    bmp_out.write((char*)&bmih, sizeof(BITMAPINFOHEADER));

    for (size_t row = 0; row < img.height; ++row)
    {
        for (size_t col = 0; col < img.width; ++col)
            bmp_out.write((char*)&img.pixels[row][col], 3);
    }

    bmp_out.close();
}

void print_rgb_img_info(const char filename[])
{
    std::ifstream bmp_in(filename, std::ios::binary);
    if (!bmp_in.is_open())
        throw std::runtime_error("Failed to open input file");

    BITMAPFILEHEADER bmfh;
    BITMAPINFOHEADER bmih;

    bmp_in.read((char*)&bmfh, sizeof(BITMAPFILEHEADER));
    bmp_in.read((char*)&bmih, sizeof(BITMAPINFOHEADER));

    std::cout << bmfh.bfSize << std::endl;
    std::cout << bmfh.bfOffBits << std::endl;

    std::cout << bmih.biSize << std::endl;
    std::cout << bmih.biHeight << std::endl;
    std::cout << bmih.biWidth << std::endl;
    std::cout << bmih.biSizeImage << std::endl;

    bmp_in.close();
}

RgbImg to_black_white_img(RgbImg image)
{   
    size_t height = image.height;
    size_t width = image.width;

    RgbImg img;
    img.height = height;
    img.width = width;
    img.pixels = new RGB * [img.height];

    for (size_t row = 0; row < img.height; ++row)
    {
        img.pixels[row] = new RGB[img.width];
        for (size_t col = 0; col < img.width; ++col) {
            BYTE color = (image.pixels[row][col].Blue + image.pixels[row][col].Green + image.pixels[row][col].Red) / 3;
            RGB pixel;
            pixel.Blue = color;
            pixel.Red = color;
            pixel.Green = color;
            img.pixels[row][col] = pixel;
        }
    }


    return img;
}

RgbImg blur_filter(RgbImg image, size_t size_of_blur)
{
    size_t height = image.height;
    size_t width = image.width;

    RgbImg img;
    img.height = height;
    img.width = width;
    img.pixels = new RGB * [img.height];

    for (size_t row = 0; row < img.height; ++row)
    {
        img.pixels[row] = new RGB[img.width];
        for (size_t col = 0; col < img.width; ++col) {
            size_t color_r = 0;
            size_t color_g = 0;
            size_t color_b = 0;
            size_t count = 0;
            for (size_t i = max(0, (int)(row-size_of_blur)); i < min(img.height-1, row+size_of_blur)+1; ++i) {
                for (size_t j = max(0, (int)(col-size_of_blur)); j < min(img.width-1, col+size_of_blur)+1; ++j) {
                    ++count;
                    color_r += image.pixels[i][j].Red;
                    color_g += image.pixels[i][j].Green;
                    color_b += image.pixels[i][j].Blue;
                }
            }
            img.pixels[row][col].Red = color_r / count;
            img.pixels[row][col].Green = color_g / count;
            img.pixels[row][col].Blue = color_b / count;
        }
    }
    return img;
}

RgbImg median_filter(RgbImg image,  size_t size_of_blur)
{
    size_t height = image.height;
    size_t width = image.width;

    RgbImg img;
    img.height = height;
    img.width = width;
    img.pixels = new RGB * [img.height];
    const size_t SIZE = (size_of_blur * 2 + 1) * (size_of_blur * 2 + 1);
    BYTE* red_ch = new BYTE[SIZE];
    BYTE* green_ch = new BYTE[SIZE];
    BYTE* blue_ch = new BYTE[SIZE];

    size_t counter = 0;

    for (size_t row = 0; row < img.height; ++row)
    {
        img.pixels[row] = new RGB[img.width];
        for (size_t col = 0; col < img.width; ++col) {
            counter = 0;
            for (size_t i = max(0, (int)(row - size_of_blur)); i < min(img.height - 1, row + size_of_blur) + 1; ++i) {
                for (size_t j = max(0, (int)(col - size_of_blur)); j < min(img.width - 1, col + size_of_blur) + 1; ++j) {
                    red_ch[counter] = image.pixels[i][j].Red;
                    green_ch[counter] = image.pixels[i][j].Green;
                    blue_ch[counter] = image.pixels[i][j].Blue;
                    ++counter;
                }
            }
            sort_by_choice(SIZE, red_ch);
            sort_by_choice(SIZE, green_ch);
            sort_by_choice(SIZE, blue_ch);

            img.pixels[row][col].Red = red_ch[SIZE / 2];
            img.pixels[row][col].Green = green_ch[SIZE / 2];
            img.pixels[row][col].Blue = blue_ch[SIZE / 2];
        }
    }

    delete[] red_ch;
    delete[] green_ch;
    delete[] blue_ch;

    return img;
}

void create_noice(RgbImg image, size_t count) {
   RGB BLACK;
    BLACK.Red = 0;
    BLACK.Green = 0;
    BLACK.Blue = 0;

    RGB WHITE;
    WHITE.Red = 255;
    WHITE.Green = 255;
    WHITE.Blue = 255;

    const size_t SIZE = 2;

    RGB colors[SIZE] = { BLACK, WHITE };
    while (count--) {
        image.pixels[random(0, image.height)][random(0, image.width)] = random(colors, SIZE);
    }
}