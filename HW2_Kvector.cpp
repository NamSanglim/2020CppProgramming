//Kvector �����
//Kvector class �� ��� �Լ����� class �ܺο� �����϶�.
//(1) ������ Kvector(int sz, int value) : sz ���� ���� �迭�� m �� �Ҵ�޾� ��� ������ ���� value �� �ʱ�ȭ�Ѵ�.
//sz �� 0�� ���� m �� NULL �� �ȴ�.
//(2) ���� ���縦 �����ϴ� ���� ������

#include <iostream>

using namespace std;

class Kvector {
private :
	int* m;
	int len;
public :
	Kvector(int sz = 0, int value = 0);
	Kvector(Kvector& v);
	~Kvector();
	void print();
	void clear();
	int size();
};
Kvector::Kvector(int sz = 0, int value = 0) {
	len = sz;
	if (sz == 0) m = NULL;
	else if(sz>0){
		m = new int[sz];
		for (int i = 0; i < sizeof(m); i++) m[i] = value;
	}
	cout << this << " : Kvector(int) \n";
}
Kvector::Kvector(Kvector& v) {
	len = v.size();
	m = new int[len];
	for (int i = 0; i < sizeof(m); i++) m[i] = v.m[i];
	cout << this << " : Kvector(Kvector&) \n";
}
Kvector::~Kvector() {
	cout << this << " : ~Kvector() \n";
	delete[] m;
}
void Kvector::print() {
	for (int i = 0; i < len; i++) cout << m[i] << " ";
	cout << endl;
}
void Kvector::clear() {
	delete[] m;
	m = NULL;
	len = 0;
}
int Kvector::size() {
	return len;
}

int main() {
	Kvector v1(3); v1.print();
	Kvector v2(2, 9); v2.print();
	Kvector v3(v2); v3.print();

	v2.clear();
	v2.print();
	v3.print();
	return 0;
}