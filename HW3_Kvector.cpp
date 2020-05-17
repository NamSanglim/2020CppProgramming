//�ǽ�: ���� �ǽ����� ������ Kvector class �� ���Ͽ� main() �Լ��� 
//������ ���� �����ϸ� compile error �� �߻��Ѵ�.
//(1) compile error �� ������ �ʵ��� class ��� �Լ����� �����϶�.
//(2) ���α׷��� ����Ǵ� ���� �����Ǵ� Kvector ��ü�鿡 �����
//m �迭�� ���� �������� ������ �����ϴ� static member ���� total_len �� �����ϰ� 
//�����ڿ� �Ҹ��ڸ� �����϶�.

#include <iostream>

using namespace std;

class Kvector {
private:
	int* m;
	int len;
public:
	static int total_len;
	Kvector(int sz = 0, int value = 0);
	Kvector(const Kvector& v);
	~Kvector();
	void print();
	void print() const;
	void clear();
	int size();
};

Kvector::Kvector(int sz, int value) {
	total_len += sz;
	if (sz == 0) m = NULL;
	else {
		this->len = sz;
		m = new int[sz];
		for (int i = 0; i < sizeof(m); i++) m[i] = value;
	}
	cout << this << " : Kvector(int, int) \n";
}
Kvector::Kvector(const Kvector& v) {
	total_len += v.len;
	this->len = v.len;
	m = new int[len];
	for (int i = 0; i < len; i++) m[i] = v.m[i];
	cout << this << " : Kvector(Kvector&) \n";
}
Kvector::~Kvector() {
	total_len -= this->len;
	cout << this << " : ~Kvector() \n";
	delete[] m;
}
int Kvector::total_len = 0;

void Kvector::print() {
	for (int i = 0; i < len; i++) cout << m[i] << " ";
	cout << '\n';
}
void Kvector::print() const {
	for (int i = 0; i < len; i++) cout << m[i] << " ";
	cout << '\n';
}

void Kvector::clear() {
	delete[] m;
	m = NULL;
	len = 0;
}
int Kvector::size() { return len; }

int main() {
	Kvector v1(3); v1.print();
	const Kvector v2(2, 9); v2.print();
	Kvector v3(v2); v3.print();

	cout << "total length = " << Kvector::total_len << endl;
	v2.print();
	v3.print();
	cout << "total length = " << Kvector::total_len << endl;
	return 0;
}