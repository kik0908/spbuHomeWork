#include <iostream>
#include "sorts.h"
#include <ctime>
#include "utils.h"


int main()
{
    srand(time(NULL));
    const size_t Size = 100'000'000;
    double* arr = new double[Size];
    new_array(arr, Size);

    //test_sort("Bubble sort", bubble_sort, arr, Size);
    //test_sort("Selection sort", selection_sort, arr, Size);
    //test_sort("Insertion sort", insertion_sort, arr, Size);
    //test_sort("merge sort", merge_sort, arr, Size);
    //test_sort_print("heap sort", heap_sort<double>, Size);
    test_sort("quick sort", quick_sort, arr, Size, greater_or_equal);


    return 0;
}