#include <iostream>
#include <fstream>

void array_to_file(int* arr, size_t size, std::ofstream& out) {
    for (size_t i = 0; i < size; ++i) {
        out << arr[i] << ' ';
    }
    out << '\n';
}

void array_to_bin_file(int* arr, size_t size, const char* file_name) {
    std::fstream out(file_name, std::ios::out | std::ios::binary);
    out.write((char*)arr, sizeof(int)*size);
    out.close();
}


int main()
{
    std::cout << "Hello World!\n";
    return 0;
}