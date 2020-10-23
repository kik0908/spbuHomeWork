#include <iostream>


int random(int start, int end) {
    return start + rand() % (end-start);
}


double** generate_matrix(size_t n) {
    double** array = new double* [n];

    for (size_t i = 0; i < n; ++i) {
        array[i] = new double[n];
        for (size_t j = 0; j < n; ++j) {
            array[i][j] = random(-15, 15);
        }
    }
    return array;
}

/*
double get_coef(double op, double x) {
    return x / op;
}
*/

void to_triangle(double** array, size_t n) {
    double coef, op;
    for (size_t i = 0; i < n-1; ++i) {
        op = array[i][i];
        for (size_t j = i+1; j < n; ++j) {
            coef = array[j][i] / op; //get_coef(op, array[j][i]);
            std::cout << coef << ' ' << i << ' ' << j << '\n';
            for (size_t k = i; k < n; ++k) {
                array[j][k] -= array[i][k] * coef;
            }
        }
    }
}

void print_matrix(double** mat, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cout << mat[i][j] << '\t';
        }
        std::cout << '\n';
    }
}


double get_opredelitel(double** matrix, size_t n) {
    to_triangle(matrix, n);

    double ans = 1;
    for (size_t i = 0; i < n; ans *= matrix[i][i++]);
    return ans;
}


int main() {
    size_t size = 3;
    double** matrix = generate_matrix(size);
    print_matrix(matrix, size);
    to_triangle(matrix, size);
    print_matrix(matrix, size);

    std::cout << get_opredelitel(matrix, size);

    return 0;
}