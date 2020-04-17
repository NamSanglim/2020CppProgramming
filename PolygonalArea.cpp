/* **************************
Problem : �ٰ����� ����
20191584 ����
****************************/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int times, num;
	int x, y, D;
	int area = 0;
	int arrX[50] = {};
	int arrY[50] = {};

	cin >> times;
	for (int i = 0; i < times; i++) {
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> x >> y;
			arrX[j] = x;
			arrY[j] = y;
		}
		for (int a = 0; a < num-1 ; a++) {
			area += (arrX[a] + arrX[a + 1]) * (arrY[a + 1] - arrY[a]);	
		}
		area += (arrX[0] + arrX[num-1]) * (arrY[0] - arrY[num-1]);	
		D = (area > 0) ? 1 : -1;
		cout << abs(area) <<" " << D << endl;
	}
}