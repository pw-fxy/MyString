#include <iostream>
using namespace std;
class MyString
{
public:

	char* my_string_pointer;
	int lenth_my_string;

	MyString();
	MyString(int);
	MyString(double);
	MyString(char *);
	MyString(MyString &ms);
	~MyString();
	//friend	MyString operator+(const MyString& ms2, const MyString& ms1);
	MyString operator+(MyString& ms1);
	//MyString operator-(MyString& ms1);
	MyString& operator=(const MyString& ms1);

};
MyString::MyString(void)
{
	lenth_my_string = 0;
	my_string_pointer = NULL;
	cout << "void\n";
};
MyString::MyString(int int_construct)
{
	int temp_int = int_construct;
	int length = 1;//求解输入的长度
	while (temp_int / 10)
	{
		temp_int = temp_int / 10;
		length++;
	}

	temp_int = int_construct;
	my_string_pointer = new char[length+1];

	for (int i = 0; i < length; i++)
	{
		my_string_pointer[length - i - 1] = char(48 + temp_int%10);
		temp_int = temp_int / 10;
	}
	my_string_pointer[length] = '\0';//记录最后一位

	lenth_my_string = length;
	//cout << "length"<<length << endl;//打印长度
	
};
MyString::MyString(double double_construct)
{
	
	int temp_int = int(double_construct);//取double的整数部分
	double temp_double = double_construct - temp_int;//取double小数部分
	int length_int = 1;//整数长度
	while (temp_int / 10)
	{
		temp_int = temp_int / 10;
		length_int++;
	}
	int length_double = 0;//小数长度
	while (temp_double * 10.0 - int(temp_double * 10.0) > 0.00001)
	{
		temp_double=temp_double*10.0 - int(temp_double * 10.0);
		length_double++;
	}
	length_double++;//小数最后一位

	int length = length_int + length_double + 1;
	my_string_pointer = new char[length+1];
	lenth_my_string = length;



	temp_int = int(double_construct);
	temp_double = double_construct - temp_int;//取double小数部分

	for (int i = 0; i < length_double; i++)
	{
		temp_double = temp_double * 10.0;
		my_string_pointer[length_int+1+i] = char(48 + int(temp_double));
	}
	for (int i = 0; i < length_int; i++)
	{
		my_string_pointer[length_int - i - 1] = char(48 + temp_int % 10);
		temp_int = temp_int / 10;
	}
	my_string_pointer[length_int] = '.';
	my_string_pointer[length] = '\0';

};


MyString::MyString(char* buffer)
{
	char* temp_buffer = buffer;
	int length = 0;
	cout << "进入buffer\n";
	while (*temp_buffer != '\0')
	{
		length++;
		temp_buffer++;
	}
	my_string_pointer = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		my_string_pointer[i] = buffer[i];
	}
	my_string_pointer[length] = '\0';
	lenth_my_string = length;
	/*cout << "======\n";
	cout << "length of buffer\t" << length << endl;
	cout << "buffer\n";
	cout << "======\n";*/
};
MyString::MyString( MyString & my_string1)
{
	lenth_my_string = my_string1.lenth_my_string;
	my_string_pointer = new char[my_string1.lenth_my_string + 1];
	for (int i = 0;i<my_string1.lenth_my_string; i++)
	{
		my_string_pointer[i] = my_string1.my_string_pointer[i];
	}
	my_string_pointer[lenth_my_string] = '\0';
};
MyString::~MyString()
{
	//cout << "deconstructor\n";
	delete [] my_string_pointer;
}

MyString MyString::operator+(MyString& ms1)
{

	int lenth = ms1.lenth_my_string + this->lenth_my_string;
	MyString ms;
	ms.lenth_my_string = lenth;
	ms.my_string_pointer = new char[lenth + 1];
	for (int i = 0; i < this->lenth_my_string; i++)
	{
		ms.my_string_pointer[i] = this->my_string_pointer[i];
	}
	for (int j = this->lenth_my_string; j < this->lenth_my_string + ms1.lenth_my_string; j++)
	{
		ms.my_string_pointer[j] = ms1.my_string_pointer[j- this->lenth_my_string];
	}
	ms.my_string_pointer[lenth] = '\0';
	return ms;
}


/*
MyString operator+(const MyString& ms2, const MyString& ms1)
{
	int lenth = ms1.lenth_my_string + ms2.lenth_my_string;
	MyString ms;
	ms.lenth_my_string = lenth;
	ms.my_string_pointer = new char[lenth + 1];
	for (int i = 0; i < ms2.lenth_my_string; i++)
	{
		ms.my_string_pointer[i] = ms2.my_string_pointer[i];
	}
	for (int j = ms2.lenth_my_string; j < ms2.lenth_my_string + ms1.lenth_my_string; j++)
	{
		ms.my_string_pointer[j] = ms2.my_string_pointer[j - ms2.lenth_my_string];
	}
	ms.my_string_pointer[lenth] = '\0';
	return ms;
}*/



//MyString MyString::operator-(MyString& ms1)
//{
//
//}


MyString& MyString::operator=(const MyString& ms1)
{
	this->lenth_my_string = ms1.lenth_my_string;
	this->my_string_pointer = new char[ms1.lenth_my_string+1];
	for (int i = 0; i < ms1.lenth_my_string; i++)
	{
		this->my_string_pointer[i] = ms1.my_string_pointer[i];
	}
	this->my_string_pointer[ms1.lenth_my_string] = '\0';
	return *this;
}

/*
MyString operator=(MyString ms1,MyString ms2)
{
	ms1->lenth_my_string = ms2.lenth_my_string;
	this->my_string_pointer = new char[ms2.lenth_my_string + 1];
	for (int i = 0; i < ms2.lenth_my_string; i++)
	{
		this->my_string_pointer[i] = ms.my_string_pointer[i];
	}
	this->my_string_pointer[ms1.lenth_my_string] = '\0';
	return *this;
	}

	*/



void test_constructor();//构造函数的测试
void test_int_constructor();
void test_double_constructor();
void test_buffer_constructor();
void test_copy_constructor();
void test_add();
int main()
{
	test_add();
	return 0;
}


void test_constructor()//构造函数的测试
{
	char* cp = new char;
	MyString ms1;
	MyString ms2(137);
	MyString ms3(cp);
	MyString ms4(ms1);
	delete cp;
}

void test_int_constructor()
{
	//长度一定是比有效长度+1，因为最后还需要\0
	MyString ms1(123);
	cout << ms1.lenth_my_string <<"\t"<< ms1.my_string_pointer << endl;
}
void test_double_constructor()
{
	MyString ms1(12.0);
	cout << ms1.my_string_pointer << endl;

}

void test_buffer_constructor()
{
	MyString ms1(123);
	MyString ms2(ms1.my_string_pointer);
	cout <<"ms1\t"<< ms1.lenth_my_string << "\t" << ms1.my_string_pointer << endl;
	cout << "ms2\t"<<ms2.lenth_my_string << "\t" << ms2.my_string_pointer << endl;

	char test_array_char[10] = "123456789";
	MyString ms3(test_array_char);
	cout << ms3.lenth_my_string << "\t" << ms3.my_string_pointer << endl;

}

void test_copy_constructor()
{
	MyString ms1(123);
	cout << "ms1:" << ms1.my_string_pointer<<"\t"<<ms1.lenth_my_string << endl;
	MyString ms2(ms1);
	cout << "ms2:" << ms2.my_string_pointer << "\t" << ms2.lenth_my_string << endl;
}

void test_add()
{
	MyString ms1(123);
	MyString ms2(567);
	MyString ms3;
	ms3 = ms2+ms1;

	//ms3 = (ms1 + ms2);
	cout << ms3.my_string_pointer << endl;
	
}

//MyString ms2 = MyString(10);这是不合法的