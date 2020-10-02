#include <iostream>
#include <ctime>


int random(int start, int end) {
	return start + rand() % (end - start + 1);
}


void task1() {
	const size_t size = 10;
	int arr[size];
	int buffer;

	for (size_t i = 0; i < size; ++i) {
		arr[i] = random(0, 20);
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';


	for (size_t i = 0; i < size / 2; ++i) {
		buffer = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = buffer;
	}

	for (size_t i = 0; i < size; ++i) {
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';

}

void task2() {
	char str[] = "aBcdeFgHr";

	for (size_t i = 0; i < strlen(str); ++i) {
		str[i] = str[i] ^ 1 << 5;
	}

	std::cout << str;

}


void task3() {
	const size_t size = 4;
	char str[size+1];
	bool flag = true;
	std::cin.getline(str, size+1);
	for (size_t i = 0; i < size; ++i) {
		if (str[i] != '0' and str[i] != '1') {
			flag = false;
			break;
		}
	}
	std::cout << ((flag == true) ? ("It is bin num") : ("It is not bin num"));
}


long long int power(int num, int p) {
	long long int ans = 1;
	for (size_t i = 0; i < p; ++i) {
		ans *= num;
	}
	return ans;
}


void task4() {
	const size_t size = 8;
	char str[size + 1];
	std::cin.getline(str, size + 1);
	size_t num = 0;

	for (size_t i = 0; i < size; ++i) {
		switch (str[i])
		{
		case '0':
			break;
		case '1':
			num += power(2, size-i-1);
		default:
			break;
		}
	}
	std::cout << num << std::endl;
	size_t b;
	size_t ind = 0;
	char str_num[4];
	while (num > 0) {
		b = num % 10;
		num /= 10;
		
		str_num[4 - (ind++) - 1] = b + '0';
		std::cout << "1\n";

	}
	std::cout << str_num;
}


void task7() {
	char str[] = "10100001000";
	size_t size = strlen(str);

	size_t len = 0, last_len = 0;
	size_t ind = 0, last_ind = 0;

	for (size_t i = 0; i < size; ++i) {
		if (str[i] == '0') {
			len++;
			if (str[i - 1] == '1') ind = i;
		}
		if (i==size-1 or str[i]=='1') {
			if (len > last_len) {
				last_len = len;
				last_ind = ind;
			}
			len = 0;
		}
	}
	std::cout << "len is " << last_len<< ", index is " << last_ind+1;
}


int main() {
	srand(time(NULL));

	task7();

	return 0;
}