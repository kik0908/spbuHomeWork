#include <iostream>


int evklid(int a, int b) {
    int ost;
    do {
        ost = a % b;
        a = b;
        b = ost;

    } while (ost != 0);
    
    return a;
}

size_t str_size(char str[]) {
    size_t len = -1; 

    while (str[++len] != '\0');

    return len; // strlen(str);
}

int str_to_int(char str[]) {
    size_t len = str_size(str);
    int num = 0;
    for (size_t i = 0; i < len; ++i) {
        num *= 10;
        num += str[i] - '0';
    }

    return num;
}




int main() {
    std::cout << evklid(556, 1112) << '\n';
    char a[] = "12123";
    std::cout << str_size(a) << '\n';
    std::cout << str_to_int(a) << '\n';

    return 0;
}