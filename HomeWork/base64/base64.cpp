#include <iostream>

char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char* base64_encode(const char* data, size_t size) {
    size_t new_size = 4 * size / 3 + (size % 3);
    char* ans = new char[new_size+1];
    size_t j = 0;

    char _, _1, _2, _3, _4, _5;
    for (size_t i = 0; i < size-(size%3); i+=3) {
        _ = (char)(data[i] & 252) >> 2;
        _1 = data[i] & 3;
        _2 = (data[i + 1] &240)>>4;
        _3 = data[i + 1] &15;
        _4 = (data[i + 2] &192)>>6;
        _5 = data[i + 2] & 63;
        
        ans[j++] = alphabet[_];
        ans[j++] = alphabet[(_1<<4)+_2];
        ans[j++] = alphabet[(_3 << 2) + _4];
        ans[j++] = alphabet[_5];

    }
    char ans1[3];
    for (size_t i = 0; i < size % 3; ++i) {
        ans1[i] = data[size - i];
    }
    for (size_t i = size % 3; i < 3; ++i) {
        ans1[i] = 0;
    }
    


    ans[new_size] = '\0';
    return ans;
}



int main()
{   
    char a[] = "1234567";
    std::cout << base64_encode(a, 7);
    std::cout << (-1) % 8;
    return 0;
}