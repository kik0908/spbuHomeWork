#pragma once
#include <chrono>

using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::duration_cast;


static high_resolution_clock::time_point start;

template <typename Type>
using Comporator = bool(*)(Type const&, Type const&);

template <typename Type>
using Sort = void(*)(Type*, size_t const, Comporator<Type>);

void tic() {
    start = high_resolution_clock::now();
}

long long toc() {
    return duration_cast<milliseconds>(high_resolution_clock::now()-start).count();
}

void new_array(double arr[], size_t const Size) {
    for (size_t i = 0; i < Size; ++i) {
        arr[i] = (double)rand() / RAND_MAX;
    }
}

template <typename Type>
void copy_array(Type source[], Type dest[], size_t const Size) {
    for (size_t i = 0; i < Size; ++i) {
        dest[i] = source[i];
    }
}


template <typename Type>
bool greater(Type const& a, Type const& b) {
    return a > b;
}

template <typename Type>
bool greater_or_equal(Type const& a, Type const& b) {
    return a >= b;
}



template <typename Type>
void test_sort(const char sort_name[], Sort<Type> sort, Type arr[], size_t const Size, Comporator<Type> comp = greater) {
    Type* new_arr = new Type[Size];
    copy_array(arr, new_arr, Size);
    tic();
    sort(arr, Size, comp);
    std::cout << "Time " << toc() << '\n';
}


template <typename Type>
void test_sort_print(const char sort_name[], Sort<Type> sort, size_t const Size, Comporator<Type> comp = greater) {
    Type* arr = new Type[Size];
    new_array(arr, Size);
    sort(arr, Size, comp);
    for (size_t i = 0; i < Size; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}


size_t radix_sort_partition(int arr[], size_t l_idx, size_t r_idx, size_t const Digit) {
    int const mask = 1 << Digit;
    while (l_idx != r_idx) {
        while ((l_idx < r_idx) && !(arr[l_idx] & mask))
            ++l_idx;
        while ((l_idx < r_idx) && (arr[r_idx] & mask))
            --r_idx;

        std::swap(arr[l_idx], arr[r_idx]);
    }

    return (arr[l_idx] & mask) ? l_idx : l_idx + 1;
}


void redix_sort_rec(int arr[], size_t const Size, size_t const Digit) {
    if (Size <= 1 or Digit < 0)
        return;

    size_t l_idx = 0;
    size_t r_idx = Size;
    /*...
    * ....
    * ....
    */
}