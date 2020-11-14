#include <iostream>
#include <fstream>


int main() {
    std::ofstream out_file;
    out_file.open("out.txt");
    if (!out_file.is_open()) {
        std::cout << "Failed to open output file\n";
        return 1;
    }

    out_file.close();
    return 0;
}