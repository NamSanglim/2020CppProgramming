/* **************************
Problem : �� ���� ������ ��� ������ �� ���ϱ�
20191584 ����
****************************/

#include <iostream>

using namespace std;

int main() {
	int times = 0;
	int min = 0, max = 999;
	int sum = 0;

	cin >> times ;
	for (int i = 0; i < times; i++) {
		cin >> min >> max;
		for (; min <= max; min++) {
			sum += min;
		}
		cout << sum << endl;
		sum = 0;
	}
}