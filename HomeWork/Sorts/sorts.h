#pragma once
#include "utils.h"


template <typename Type>
void bubble_sort(Type arr[], size_t const SIZE, Comporator<Type> comp = greater) {
    for (size_t i = 0; i < SIZE - 1; ++i) {
        for (size_t j = 0; j < SIZE - (i + 1); ++j) {
            if (comp(arr[j], arr[j + 1])) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename Type>
void selection_sort(Type arr[], size_t const Size, Comporator<Type> comp = greater) {
    size_t max_el;
    for (size_t i = 0; i < Size-1; ++i) {
        max_el = i;
        for (size_t j = i; j < Size; ++j) {
            if (comp(arr[max_el],arr[j])) {
                max_el = j;
            }
        }
        std::swap(arr[i], arr[max_el]);
    }
}


template <typename Type>
void insertion_sort(Type arr[], size_t const Size, Comporator<Type> comp = greater) {
    for (size_t iter = 0; iter < Size - 1; ++iter)
    {
        Type key = arr[Size - iter - 2];
        size_t idx = Size - iter - 1;
        for (; idx < Size; ++idx)
        {
            if (arr[idx] < key)
                arr[idx - 1] = arr[idx];
            else
                break;
        }
        arr[idx - 1] = key;
    }
}

template <typename Type>
void merge(Type arr[], size_t const Size, size_t const Split_idx, Comporator<Type> comp) {
    size_t lpos = 0;
    size_t rpos = Split_idx;
    size_t tmp_pos = 0;
    Type* tmp_sorted = new Type[Size];

    while (lpos < Split_idx and rpos < Size) {
        tmp_sorted[tmp_pos++] = comp(arr[lpos], arr[rpos]) ? arr[rpos++] : arr[lpos++];
    }


    while (lpos < Split_idx) {
        tmp_sorted[tmp_pos++] = arr[lpos++];
    }

    while (rpos < Size) {
        tmp_sorted[tmp_pos++] = arr[rpos++];
    }

    for (size_t i = 0; i < Size; ++i) {
        arr[i] = tmp_sorted[i];
    }
    delete[] tmp_sorted;
}


template <typename Type>
void merge_sort(Type arr[], size_t const Size, Comporator<Type> comp = greater) {
    if (Size == 1) {
        return;
    }
    const size_t Split_idx = Size / 2;
    merge_sort(arr, Split_idx, comp);
    merge_sort(arr + Split_idx, Size - Split_idx, comp);
    merge(arr, Size, Split_idx, comp);
}

template <typename Type>
void heap_elem(Type arr[], size_t const Size, size_t idx, Comporator<Type> comp = greater) {
    size_t const left_child = idx * 2 + 1;
    size_t const right_child = left_child + 1;
    
    while (idx * 2 + 1 < Size) {
        if (idx * 2 + 2 >= Size) {
            if (comp(arr[left_child], arr[idx])) {
                std::swap(arr[left_child], arr[idx]);
            }
            break;
        }
        else {
            size_t max_idx = comp(arr[left_child], arr[right_child]) ? left_child : right_child;
            if (comp(arr[left_child], arr[idx])) {
                std::swap(arr[left_child], arr[idx]);
                idx = max_idx;
            }
            else {
                break;
            }
        }
    }
}


template <typename Type>
void heap_sort(Type arr[], size_t const Size, Comporator<Type> comp = greater) {
    //1. make heap
    for (int idx = Size / 2 - 1; idx >= 0; --idx)
        heap_elem(arr, Size, idx, comp);

    //2. sort
    for (size_t iter = 0; iter < Size-1; ++iter) {
        std::swap(arr[0], arr[Size - iter - 1]);
        heap_elem(arr, Size - iter - 1, 0, comp);
    }
}

template <typename Type>
size_t quick_sort_partitation(Type arr[], size_t l_idx, size_t r_idx, Comporator<Type> comp) {
    size_t pivot_idx = (l_idx + r_idx) / 2;
    Type const Pivot = arr[pivot_idx];
    while (l_idx < r_idx) {
        while (comp(Pivot, arr[l_idx]) && l_idx < pivot_idx) 
            ++l_idx;
        while (comp(arr[r_idx], Pivot) && r_idx > pivot_idx) 
            --r_idx;

        if (l_idx == r_idx) {
            break;
        }

        std::swap(arr[l_idx], arr[r_idx]);

        if (l_idx == pivot_idx) {
            pivot_idx = r_idx;
        }
        else if (r_idx == pivot_idx) {
            pivot_idx = l_idx;
        }
    }
    return l_idx;
}

template <typename Type>
void quick_sort(Type arr[], size_t const Size, Comporator<Type> comp = greater_or_equal) {
    if (Size <= 1) {
        return;
    }

    size_t const Pivot = quick_sort_partitation(arr, 0, Size - 1, comp);
    quick_sort(arr, Pivot, comp);
    quick_sort(arr + Pivot + 1, Size - Pivot - 1, comp);

}