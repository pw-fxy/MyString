#include <iostream>
#include <typeinfo>
using namespace std;

template <class T>
class MyMatrix {
public:
	int row;//matrix行数
	int column;//matrix列数
	T* matrix_pointer;//指向数组的指针
	MyMatrix <T>();
	MyMatrix <T>(int m,int n);
	MyMatrix <T>(MyMatrix &mm);
	MyMatrix <T>(T* buffer, int m, int n);
	MyMatrix<T>& operator=(const MyMatrix<T>& mm);
	MyMatrix<T> operator+(const MyMatrix<T>& mm);
	MyMatrix<T> operator-(const MyMatrix<T>& mm);

friend	ostream& operator << <T>(ostream& os, const MyMatrix<T>& mm);
};


template <class T>
MyMatrix<T>::MyMatrix()
{	
	cout << "空构造函数\n";
	this->column = 0;
	this->row = 0;
	this->matrix_pointer = NULL;
	T* p;
}

template <class T>
MyMatrix<T>::MyMatrix(int m,int n)
{
	cout << "m行n列全为0 构造函数\n";
	this->row = m;//行
	this->column = n;//列
	this->matrix_pointer = new T[m*n];
	for (int i = 0; i < m * n; i++)
	{
		this->matrix_pointer[i] = 0;
	}
}

template <class T>
MyMatrix<T>::MyMatrix(T*buffer,int m, int n)
{
	cout << "buffer构造函数\n";
	this->row = m;//行
	this->column = n;//列
	this->matrix_pointer = new T[m * n];
	for (int i = 0; i < m * n; i++)
	{
		this->matrix_pointer[i] = buffer[i];
	}
}

template <class T>
MyMatrix<T>::MyMatrix(MyMatrix<T>& mm)
{
	cout << "复制构造函数\n";
	this->row = mm.row;//行
	this->column = mm.column;//列
	this->matrix_pointer = new T[(this->row) * (this->column)];
	for (int i = 0; i < mm.column * mm.row; i++)
	{
		this->matrix_pointer[i] = mm.matrix_pointer[i];
	}
}


template <class T>
ostream& operator <<(ostream& os, const MyMatrix<T>& mm)
{
	if (mm.matrix_pointer == NULL)
	{
		cout << "空矩阵\n";
		return os;
	}
	else
	{
		for (int i = 0; i < mm.row; i++)
		{
			for (int j = 0; j < mm.column; j++)
			{
				cout << mm.matrix_pointer[i * (mm.column) + j] << "\t";
			}
			cout << "\n";
		}
	}
	return os;
}

template <class T>
MyMatrix<T>& MyMatrix<T>::operator=(const MyMatrix<T>& mm)
{
	cout << "复制构造函数\n";
	this->row = mm.row;//行
	this->column = mm.column;//列
	this->matrix_pointer = new T[(this->row) * (this->column)];
	for (int i = 0; i < mm.column * mm.row; i++)
	{
		this->matrix_pointer[i] = mm.matrix_pointer[i];
	}
	return *this;
}
template <class T>
MyMatrix<T> MyMatrix<T>::operator+(const MyMatrix<T>& mm)
{
	cout << "operator++\n";
	MyMatrix<T> mm2;
	if (this->column != mm.column || this->row != mm.row)
	{
		return mm2;
	}
	else
	{
		mm2.matrix_pointer = new T[this->row * this->column];
		mm2.column = this->column;
		mm2.row = this->row;
		for (int i = 0; i < this->row * this->column;i++)
		{
			mm2.matrix_pointer[i] = this->matrix_pointer[i] + mm.matrix_pointer[i];
		}
		return mm2;
	}
}

template <class T>
MyMatrix<T> MyMatrix<T>::operator-(const MyMatrix<T>& mm)
{
	cout << "operator++\n";
	MyMatrix<T> mm2;
	if (this->column != mm.column || this->row != mm.row)
	{
		return mm2;
	}
	else
	{
		mm2.matrix_pointer = new T[this->row * this->column];
		mm2.column = this->column;
		mm2.row = this->row;
		for (int i = 0; i < this->row * this->column; i++)
		{
			mm2.matrix_pointer[i] = this->matrix_pointer[i] - mm.matrix_pointer[i];
		}
		return mm2;
	}
}

void test_constructor();
void test_add_sub();

int main()
{
	return 0;
}
void test_add_sub()
{
	int* p = new int[10];
	for (int i = 0; i < 10; i++)
	{
		p[i] = i;
	}
	MyMatrix<int> ms(p, 3, 3);
	cout << ms << endl;
	MyMatrix<int> ms1;
	ms1 = ms;
	MyMatrix<int> ms2;
	ms2 = ms1 - ms;
	cout << ms2 << endl;
}
void test_constructor()
{
	//MyMatrix<char> ms;
	double* p = new double[10];
	for (int i = 0; i < 10; i++)
	{
		p[i] = i;
	}
	MyMatrix<double> ms2(p, 3, 3);
	cout << ms2 << endl;
	MyMatrix<double> ms3(ms2);
	cout << ms3 << endl;
	MyMatrix<double> ms4;
	ms4 = ms3;
	cout << ms4 << endl;
}