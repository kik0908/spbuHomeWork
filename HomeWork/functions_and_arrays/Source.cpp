#include <iostream>

int* aa() {
	int* a = new int[5];
	a[7] = *a;
	return a;
}

void bb(int* a) {
	delete[] a;
}


int main() {
	int* a = aa();
	a[7] = 1;
	bb(a);
}