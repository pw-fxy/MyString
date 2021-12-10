#include <iostream>
#include <typeinfo>
using namespace std;


template <class T>
class MyMatrix;
template <class T>
ostream& operator <<(ostream& os, const MyMatrix<T>& mm);


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
	~MyMatrix <T>();



	MyMatrix<T>& operator=(const MyMatrix<T>& mm);
	MyMatrix<T>& operator*=(const MyMatrix<T>& mm);
	MyMatrix<T> operator+(const MyMatrix<T>& mm);
	MyMatrix<T> operator-(const MyMatrix<T>& mm);
	MyMatrix<T> operator+(int num);
	MyMatrix<T> operator-(int num);
	MyMatrix<T> operator*(int number);
	MyMatrix<T> operator*(const MyMatrix<T>& mm);
	T operator()(int row,int column);


	friend	ostream& operator << <T>(ostream& os, const MyMatrix<T>& mm);
};


template <class T>
MyMatrix<T>::~MyMatrix()//析构函数
{
	cout << "析构函数\n";
	if (this->matrix_pointer != NULL)
	{
		delete[]this->matrix_pointer;
		cout << "析构free" << endl;
		matrix_pointer = NULL;
	}
	
}


template <class T>
MyMatrix<T>::MyMatrix()//构造函数
{	
	cout << "空构造函数\n";
	this->column = 0;
	this->row = 0;
	this->matrix_pointer = NULL;
	T* p;
}

template <class T>
MyMatrix<T>::MyMatrix(int m,int n)//m行n列全为0 构造函数
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
MyMatrix<T>::MyMatrix(T*buffer,int m, int n)//buffer构造函数
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
MyMatrix<T>::MyMatrix(MyMatrix<T>& mm)//复制构造函数
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
ostream& operator <<(ostream& os, const MyMatrix<T>& mm)//输出打印函数
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
MyMatrix<T>& MyMatrix<T>::operator=(const MyMatrix<T>& mm)//=重载
{
	cout << "复制函数\n";
	this->row = mm.row;//行
	this->column = mm.column;//列
	if (this->matrix_pointer != NULL)
	{
		delete [] this->matrix_pointer;
	}
	this->matrix_pointer = new T[(this->row) * (this->column)];
	for (int i = 0; i < mm.column * mm.row; i++)
	{
		this->matrix_pointer[i] = mm.matrix_pointer[i];
	}
	return *this;
}


template <class T>
MyMatrix<T>& MyMatrix<T>::operator*=(const MyMatrix<T>& mm)//=重载
{
	cout << "operator*matrix\n";
	if (this->matrix_pointer == NULL || mm.matrix_pointer == NULL || this->column != mm.row)//如果矩阵为空直接返回
	{
		cout << "相乘失败\n";
		return *this;
	}


	MyMatrix<T> mm2;
	mm2.matrix_pointer = new T[this->row * mm.column];
	mm2.row = this->row;
	mm2.column = mm.column;
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < mm.column; j++)
		{
			mm2.matrix_pointer[i * mm.column + j] = 0;
			for (int k = 0; k < this->column; k++)
			{
				mm2.matrix_pointer[i * mm.column + j] += this->matrix_pointer[i * this->column + k] * mm.matrix_pointer[k * mm.column + j];
			}
		}

	}
	
	/*if (this->matrix_pointer != NULL)
	{
		delete[] this->matrix_pointer;
		cout << "*=free\n";
		this->matrix_pointer = NULL;
	}
	else
	{
		cout << "matrix pointer is NULL\n";
	}*/
	*this = mm2;

	return *this;




	
}

template <class T>
MyMatrix<T> MyMatrix<T>::operator+(const MyMatrix<T>& mm)//+重载
{
	cout << "operator+\n";
	MyMatrix<T> mm2;
	if (this->column != mm.column || this->row != mm.row||this->matrix_pointer==NULL||mm.matrix_pointer==NULL)
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
MyMatrix<T> MyMatrix<T>::operator+(int num)//+重载
{
	cout << "operator+\n";
	MyMatrix<T> mm2;
	if (this->matrix_pointer==NULL)
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
			mm2.matrix_pointer[i] = this->matrix_pointer[i] + num;
		}
		return mm2;
	}
}

template <class T>
MyMatrix<T> MyMatrix<T>::operator-(const MyMatrix<T>& mm)//-重载
{
	cout << "operator-\n";
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


template <class T>
MyMatrix<T> MyMatrix<T>::operator-(int num)//+重载
{
	cout << "operator+\n";
	MyMatrix<T> mm2;
	if (this->matrix_pointer == NULL)
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
			mm2.matrix_pointer[i] = this->matrix_pointer[i] - num;
		}
		return mm2;
	}
}

template <class T>
MyMatrix<T> MyMatrix<T>::operator*(int num)//*重载
{
	cout << "operator*int\n";
	if (this->matrix_pointer == NULL)//如果矩阵为空直接返回
	{
		return *this;
	}


	MyMatrix<T> mm2;
	mm2.matrix_pointer = new T[this->row * this->column];
	mm2.column = this->column;
	mm2.row = this->row;
	for (int i = 0; i < this->row * this->column; i++)
	{
		mm2.matrix_pointer[i] = this->matrix_pointer[i]*num;
	}
	return mm2;
}



template <class T>
MyMatrix<T> MyMatrix<T>::operator*(const MyMatrix<T>& mm)//*重载
{
	cout << "operator*matrix\n";
	if (this->matrix_pointer == NULL || mm.matrix_pointer==NULL||this->column!=mm.row)//如果矩阵为空直接返回
	{
		cout << "相乘失败\n";
		return *this;
	}


	MyMatrix<T> mm2;
	mm2.matrix_pointer = new T[this->row * mm.column];
	mm2.row = this->row;
	mm2.column = mm.column;
	for (int i = 0; i < this->row ; i++)
	{
		for (int j = 0; j < mm.column; j++)
		{
			mm2.matrix_pointer[i*mm.column+j] = 0;
			for (int k = 0; k < this->column; k++)
			{
				mm2.matrix_pointer[i * mm.column + j] += this->matrix_pointer[i * this->column + k] * mm.matrix_pointer[k * mm.column + j];
			}
		}
		
	}
	return mm2;

}

template <class T>
T MyMatrix<T>::operator()(int row, int column)
{
	if (this->matrix_pointer == NULL || row >= this->row || column >= this->column)
	{
		cout << "查询失败\n";
		return 888;
	}

	else
	{
		return this->matrix_pointer[row * this->column + column];
	}
}

void test_constructor();
void test_add_sub();
void test_mult();

int main()
{
	
	test_mult();
  	//system("pause");


	return 0;
}

void test_mult()
{
	/*int* p = new int[10];
	for (int i = 0; i < 10; i++)
	{
		p[i] = i;
	}
	MyMatrix<int> ms(p, 3, 3);
	cout << ms << endl;
	MyMatrix<int> ms1;
	ms1 = ms * 4.5;
	cout << ms1 << endl;

	ms1 = ms * ms;
	cout << ms1 << endl;*/


	int* p1 = new int[6];
	for (int i = 0; i < 10; i++)
	{
		p1[i] = i;
	}
	MyMatrix<int> ms2(p1, 2, 3);
	MyMatrix<int> ms3(p1, 3, 2);
	ms2 *= ms3;
	cout << ms2 << endl;
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


	ms2 = ms1 + ms;
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