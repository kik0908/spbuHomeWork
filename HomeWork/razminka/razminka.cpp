#include <iostream>

template <typename Type>
void print_array(Type* arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

template <typename Type>
bool in_array(Type* arr, size_t& size, Type element) {
    bool ans = false;
    for (size_t i = 0; i < size; ++i) {
        if (element == arr[i]) {
            ans = true;
            break;
        }
    }
    return ans;
}

template <typename Type>
void arr_map(Type* source, Type* map, Type* dest, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        dest[map[i]] = source[i];
    }
}

template <typename Type>
Type* peresech(Type* arr1, size_t size1, Type* arr2, size_t size2, size_t& outsize) {
    outsize = 0;
    Type* ans1 = new Type[size1 + size2];

    for (size_t i = 0; i < size1; ++i) {
        if (in_array(arr2, size2, arr1[i])) {
            ans1[outsize++] = arr1[i];
        }
    }
    Type* ans = new Type[outsize];
    for (size_t i = 0; i < outsize; ++i) {
        ans[i] = ans1[i];
    }
    return ans;
}

template <typename Type>
Type* trey(Type* arr1, size_t size1, Type* arr2, size_t size2, size_t& outsize) {
    outsize = 0;
    Type* ans1 = new Type[size1 + size2];

    for (size_t i = 0; i < size1; ++i) {
        if (!in_array(arr2, size2, arr1[i])) {
            ans1[outsize++] = arr1[i];
        }
    }
    for (size_t i = 0; i < size2; ++i) {
        if (!in_array(arr1, size1, arr2[i])) {
            ans1[outsize++] = arr2[i];
        }
    }
    Type* ans = new Type[outsize];
    for (size_t i = 0; i < outsize; ++i) {
        ans[i] = ans1[i];
    }
    return ans;
}

template <typename Type>
Type* obedenenie(Type* arr1, size_t size1, Type* arr2, size_t size2, size_t& outsize) {
    outsize = 0;
    Type* ans = new Type[size1 + size2];
    for (size_t i = 0; i < size1; ++i) {
        ans[outsize++] = arr1[i];
    }
    for (size_t i = 0; i < size2; ++i) {
        ans[outsize++] = arr2[i];
    }
    return ans;
}

template<typename Type>
Type** comb(Type* source, size_t size) {
    long long int factotial = 1;
    Type** ans = new Type * [factotial];
    for (size_t i = 1; i <= size; ++i) {
        factotial *= i;
    }
    std::cout << factotial;

    for (size_t i = 0; i < size; ++i) {
        source[0] = source[i];
    }
    return ans;
}


int main()
{
    const size_t size = 7;
    int arr1[size] = { 0, 1,2,3,4,5,6 };
    int arr2[size] = {6,5,4,3,2,1,0};
    int arr3[size];

    arr_map(arr1, arr2, arr3, size);
    print_array(arr3, size);
    std::cout << "------------" << std::endl;

    const size_t size4 = 4;
    const size_t size5 = 2;
    int arr4[size4] = { 0, 1,2,3 };
    int arr5[size5] = { 4,5 };

    size_t outsize = 0;
    int* ans = new int[outsize];
    ans = obedenenie(arr4, size4, arr5, size5, outsize);
    print_array(ans, outsize);
    std::cout << "------------" << std::endl;
    const size_t size6 = 4;
    const size_t size7 = 4;
    int arr6[size6] = { 0, 1,2,3 };
    int arr7[size7] = { 4,5, 1, 2 };

    delete[] ans;
    outsize = 0;
    ans = new int[outsize];
    ans = trey(arr6, size6, arr7, size7, outsize);
    print_array(ans, outsize);
    std::cout << "------------" << std::endl;
    const size_t size8 = 4;
    const size_t size9 = 4;
    int arr8[size6] = { 0, 1,2,3 };
    int arr9[size7] = { 4,5, 1, 2 };

    delete[] ans;
    outsize = 0;
    ans = new int[outsize];
    ans = peresech(arr8, size8, arr9, size9, outsize);
    print_array(ans, outsize);
    std::cout << "------------" << std::endl;

    comb(arr8, size8);
}
