#include "utils.h"

template <typename Type>
Type max(Type& a, Type& b) {
    return ((a) > (b) ? (a) : (b));
}

template <typename Type>
Type min(Type& a, Type& b) {
    return ((a) < (b) ? (a) : (b));
}

template <typename Type>
Type return_x(Type x) {
    return x;
}


template <typename Type>
void sort_by_choice(size_t size, Type* arr, Type(*func)(Type)) {
    if (func == nullptr) {
        func = return_x;
    }

    size_t ind_min, ind_max;
    Type tmp;

    for (size_t i = 0; i < size / 2; ++i) {
        ind_min = i;
        ind_max = i;
        for (size_t j = i; j < size - i; ++j) {
            if (func(arr[j]) < func(arr[ind_min])) {
                ind_min = j;
            }
            if (func(arr[j]) > func(arr[ind_max])) {
                ind_max = j;
            }
        }
        tmp = arr[i];
        arr[i] = arr[ind_min];
        arr[ind_min] = tmp;

        if (ind_max == i) {
            ind_max = ind_min;
        }

        tmp = arr[size-i-1];
        arr[size - i - 1] = arr[ind_max];
        arr[ind_max] = tmp;

    }
}

template <typename Type>
void sort_by_choice(size_t size, Type* arr) {
    size_t ind_min, ind_max;
    Type tmp;

    for (size_t i = 0; i < size / 2; ++i) {
        ind_min = i;
        ind_max = i;
        for (size_t j = i; j < size - i; ++j) {
            if (arr[j] < arr[ind_min]) {
                ind_min = j;
            }
            if (arr[j] > arr[ind_max]) {
                ind_max = j;
            }
        }
        tmp = arr[i];
        arr[i] = arr[ind_min];
        arr[ind_min] = tmp;

        if (ind_max == i) {
            ind_max = ind_min;
        }

        tmp = arr[size - i - 1];
        arr[size - i - 1] = arr[ind_max];
        arr[ind_max] = tmp;

    }
}