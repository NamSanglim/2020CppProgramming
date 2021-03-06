/* **************************
Problem : 해밍 코드
20191584 남상림
****************************/
//코드 중복 줄여서 수정한 코드 

#include <iostream>
#include <algorithm>

using namespace std;
int arr[32];
int cnt = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0;

void to_bin( int n) {
	for (int i = 31; i >= 0; i--) {
		if (i == 31 || i == 30 || i == 28 || i == 24 || i == 16) arr[i] = NULL;
		else {
			arr[i] = n % 2;
			n /= 2;
		}
	}
}

void to____bin( int n) {
	for (int i = 31; i >= 0; i--) {
		arr[i] = n % 2;
		n /= 2;
	}
}

void to_dec(int* arr) {
	int n = 1;
	unsigned int sum = 0;
	for (int i = 31; i >= 0; i--) {
		if (arr[i] == 1) sum += n;
		n *= 2;
	}
	cout << sum << endl;
}

void to____dec(int* arr) {
	int n = 1;
	unsigned int sum = 0;
	for (int i = 31; i >= 0; i--) {
		if (i == 31 || i == 30 || i == 28 || i == 24 || i == 16 || i == 0) continue;
		else {
			if (arr[i] == 1) {
				sum += n;
			}n *= 2;
		}
	}
	cout << sum << endl;
}
void bitCheck(int* arr) {
	for (int i = 29; i > 0; i -= 2) {
		if (arr[i] == 1)cnt += 1;
	}
	for (int i = 30; i >= 0; i -= 4) {
		if (arr[i] == 1)cnt2 += 1;
		if (arr[i - 1] == 1)cnt2 += 1;
	}
	if (arr[30] == 1)cnt2 -= 1;
	for (int i = 28; i > 0; i -= 8) {
		if (arr[i] == 1)cnt3 += 1;
		if (arr[i - 1] == 1)cnt3 += 1;
		if (arr[i - 2] == 1)cnt3 += 1;
		if (arr[i - 3] == 1)cnt3 += 1;
	}
	if (arr[28] == 1)cnt3 -= 1;
	for (int i = 23; i > 16; i--) {
		if (arr[i] == 1) cnt4 += 1;
	}
	for (int i = 8; i > 0; i--) {
		if (arr[i] == 1)cnt4 += 1;
	}
	for (int i = 15; i > 0; i--) {
		if (arr[i] == 1)cnt5 += 1;
	}
}

void getEncodedValue(int* arr) {
	if (cnt % 2 == 1) arr[31] = 1;
	if (cnt2 % 2 == 1) arr[30] = 1;
	if (cnt3 % 2 == 1) arr[28] = 1;
	if (cnt4 % 2 == 1) arr[24] = 1;
	if (cnt5 % 2 == 1) arr[16] = 1;
	to_dec(arr);
}
void getDecodedeValue(int* arr) {
	int sum = 32;
	if (cnt % 2 == 1) {
		if (arr[31] == 0) sum -= 1;
	}
	else
		if (arr[31] == 1) sum -= 1;
	if (cnt2 % 2 == 1) {
		if (arr[30] == 0) sum -= 2;
	}
	else
		if (arr[30] == 1) sum -= 2;
	if (cnt3 % 2 == 1) {
		if (arr[28] == 0) sum -= 4;
	}
	else
		if (arr[28] == 1) sum -= 4;
	if (cnt4 % 2 == 1) {
		if (arr[24] == 0) sum -= 8;
	}
	else
		if (arr[24] == 1) sum -= 8;
	if (cnt5 % 2 == 1) {
		if (arr[16] == 0) sum -= 16;
	}
	else
		if (arr[16] == 1) sum -= 16;
	arr[sum] = 1;

	for (int i = 31; i >= 0; i--) {
		if (i == 31 || i == 30 || i == 28 || i == 24 || i == 16) arr[i] = NULL;
	}
	to____dec(arr);
}

int main() {
	int times, k, num;
	cin >> times;
	for (int i = 0; i < times; i++) {
		fill(&arr[0], &arr[32], 0);
		cnt = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0;
		cin >> k >> num;

		if (k == 0) {
			to_bin(num);
			bitCheck(arr);
			getEncodedValue(arr);
		}
		else {
			to____bin(num);
			bitCheck(arr);
			getDecodedeValue(arr);
		}
	}
	return 0;
}
