/* **************************
Problem : ���ڷ� �ﰢ�� ����ϱ�
20191584 ����
****************************/

#include <iostream>

using namespace std;

int main() {
	int times;
	int num;

	cin >> times;
	for (int i = 0; i < times; i++) {
		cin >> num;
		for (int row = num; row >= 0; row--) {
			for (int col = row + 1; col <= num; col++) {
				cout << col;
			}
			cout << endl;
		}
		
	}
}