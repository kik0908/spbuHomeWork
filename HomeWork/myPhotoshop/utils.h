#pragma once
template <typename Type>
Type max(Type& a, Type& b);

template <typename Type>
Type min(Type& a, Type& b);


template <typename Type>
void sort_by_choice(size_t size, Type* arr);

template <typename Type>
void sort_by_choice(size_t size, Type* arr, Type(*func)(Type));
