#include <iostream>
using namespace std;

template <class T>
class MyMatrix {
public:
	int row;//matrix����
	int column;//matrix����
	T* matrix_pointer;//ָ�������ָ��
	MyMatrix <T>();
	MyMatrix <T>(int m,int n);
	MyMatrix <T>(MyMatrix &mm);
	MyMatrix <T>(char* buffer, int m, int n);


};


template <class T>
MyMatrix<T>::MyMatrix()
{
	cout << "void" << endl;
	this->column = 0;
	this->row = 0;
	this->matrix_pointer = NULL;
}
int main()
{
	MyMatrix<int> ms;
}