/* **************************
Problem : �־��� ������ �� ���ϱ�
20191584 ����
****************************/

#include <iostream>

using namespace std;

int main() {
	int times;
	int howmany, num; 
	int sum = 0;

	cin >> times;
	for (int i = 0; i < times; i++) {
		cin >> howmany;
		for (int j = 0; j < howmany; j++) {
			cin >> num;
			sum += num;
		}
		num = 0;
		cout << sum << endl;
		sum = 0;
	}
}