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
    friend	ostream& operator << (ostream & os,const MyString& ms);
	MyString operator+(MyString& ms1);
	MyString operator-(MyString& ms1);

	MyString& operator=(const MyString& ms1);

	MyString operator+=(const double);
	MyString operator-=(const int);
	MyString operator-=(string);

	char* subString(int m, int n);
	int  find(MyString);
	int toInt();
	double tofloat();

};
MyString::MyString(void)
{
	lenth_my_string = 0;
	my_string_pointer = NULL;
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
	length_double++;
	int length = length_int + length_double + 1;
	my_string_pointer = new char[length+1];
	lenth_my_string = length;



	temp_int = int(double_construct);
	temp_double = double_construct - temp_int+0.001;//取double小数部分

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
MyString MyString::operator-(MyString& ms1)
{
	if (this->my_string_pointer == NULL)
	{
		return *this;
	}
	for (int i = 0; i < ms1.lenth_my_string; i++)
	{
		if (ms1.my_string_pointer[ms1.lenth_my_string - 1 - i] != this->my_string_pointer[this->lenth_my_string - 1 - i])
			return *this;
	}
	int lenth = this->lenth_my_string - ms1.lenth_my_string;
	this->my_string_pointer[this->lenth_my_string - ms1.lenth_my_string] = '\0';
	this->lenth_my_string = lenth;
	return *this;
}



MyString MyString::operator+=(const double add_double)
{
	MyString ms1(add_double);
	*this = *this + ms1;
	return *this;

}
MyString MyString::operator-=(const int sub_int)//如果原尾部相同，则相减
{
	if (this->my_string_pointer == NULL)
	{
		return *this;
	}
	MyString ms1(sub_int);
	for (int i = 0; i < ms1.lenth_my_string; i++)
	{
		if (ms1.my_string_pointer[ms1.lenth_my_string - 1 - i] != this->my_string_pointer[this->lenth_my_string - 1 - i])
			return *this;
	}
	int lenth = this->lenth_my_string - ms1.lenth_my_string;
	this->my_string_pointer[this->lenth_my_string - ms1.lenth_my_string] = '\0';
	this->lenth_my_string = lenth;
	return *this;

}
MyString MyString::operator-=(string sub_string)
{
	
	for (int i = 0; i < sub_string.length(); i++)
	{
		if (sub_string[sub_string.length() - 1 - i] != this->my_string_pointer[this->lenth_my_string - 1 - i])
			return *this;
	}
	int lenth = this->lenth_my_string - sub_string.length();
	this->my_string_pointer[this->lenth_my_string - sub_string.length()] = '\0';
	this->lenth_my_string = lenth;
	return *this;

}

ostream& operator << (ostream &os,const MyString& ms)
{
	//输出s的代码
	cout << "lenth:\t" << ms.lenth_my_string << endl;
	cout << "string:\t";
	if (ms.my_string_pointer != NULL)
	{
		 cout<< ms.my_string_pointer << endl;
	}
	return os;
}



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



char* MyString::subString(int m, int n)
{
	char* substring = new char[n + 1];
	int i = 0;
	for (i=0; i < n && m + i < this->lenth_my_string; i++)
	{
		substring[i] = this->my_string_pointer[m +i];
	}
	substring[i + 1] = '\0';
	return substring;
}
int MyString::find(MyString ms)
{
	if (ms.lenth_my_string > this->lenth_my_string)
	{
		return -2;
	}
	for (int i = 0; i < this->lenth_my_string; i++)
	{
		if (ms.my_string_pointer[0] == this->my_string_pointer[i])
		{
			for (int j = 1; j < ms.lenth_my_string && j + i < this->lenth_my_string; j++)
			{
				if (ms.my_string_pointer[j] != this->my_string_pointer[i + j])
				{
					return -2;
				}
				
			}
			return i;
		}
	}
	return -2;
}

int MyString::toInt()
{
	int int_ms = 0;
	int temp = 1;
	for (int i = lenth_my_string-1; i >=0; i--)
	{
		if (this->my_string_pointer[i] < '0' || this->my_string_pointer[i]>'9')
		{
			return -2;
		}
		int_ms += (int(this->my_string_pointer[i]) - 48) * temp;
		temp = temp * 10;
	}
	return int_ms;
}
double MyString::tofloat()
{
	double double_ms = 0;
	int dot_position = -1;//小数点位置
	for (int i = 0; i < this->lenth_my_string; i++)
	{
		if (this->my_string_pointer[i] == '.')
		{ 
			dot_position = i;
			break;
		}
		
	}
	if (dot_position == -1)
	{
		return -2;
	}
	int temp = 1;
	for (int j = dot_position - 1; j >= 0; j--)
	{
		if (this->my_string_pointer[j] < '0' || this->my_string_pointer[j]>'9')
		{
			return -2;
		}
		double_ms += (int(this->my_string_pointer[j]) - 48) * temp;
		temp = temp * 10;
	}
	if (this->my_string_pointer[dot_position + 1] < '0' || this->my_string_pointer[dot_position + 1]>'9')
	{
		return -2;
	}
	else double_ms += 0.1 * (int(this->my_string_pointer[dot_position+1]) - 48);//默认留一位小数
	return double_ms;
}


void test_constructor();//构造函数的测试
void test_int_constructor();
void test_double_constructor();
void test_buffer_constructor();
void test_copy_constructor();
void test_add();
void test_sub();
void test_stream();
void test_sub_string();
void test_subString();
void test_find();
void test_toInt();
void test_tofloat();

int main()
{
	MyString ms(123456789);
	cout << "ms:\n" << ms << endl;
	char* p;
	p = ms.subString(1, 100);
	cout << p << endl;
	MyString ms2(34);
	cout << ms.find(ms2) << endl;
	MyString ms3(25);
	cout << ms.find(ms3) << endl;

	cout << ms.toInt() << endl;
	cout << ms.tofloat() << endl;
	return 0;
}


void test_constructor()//构造函数的测试
{
	/*char* cp = new char;
	MyString ms1;
	MyString ms2(137);
	MyString ms3(cp);
	MyString ms4(ms1);
	delete cp;*/


	MyString ms;
	cout << ms << endl;

	MyString ms1(123);
	cout << ms1 << endl;

	MyString ms2(123.241);
	cout << ms2 << endl;

	MyString ms3(ms1);
	cout << ms3 << endl;

	char abc[] = "abc";
	MyString ms4(abc);
	cout << ms4 << endl;

	MyString ms5(1.09);
	cout << ms5 << endl;

	MyString ms6(1234);
	MyString ms7(34);
	MyString ms8;
	ms8 = ms6 - ms7;
	cout << "----------\n";
	cout << ms8 << endl;
	//cout<<
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
	MyString ms4(89);
	//ms3 = ms2+ms1;
	////ms3 = (ms1 + ms2);
	ms3 = ms1 + ms2+ms4;
	cout << ms3.my_string_pointer << endl;
	
}

void test_sub()
{
	MyString ms1(123);
	MyString ms2(567);
	ms1 -= 3;
	cout << ms1.my_string_pointer << endl;
	cout << ms1.lenth_my_string << endl;
}
void test_sub_string()
{
	MyString ms1(123);
	ms1 -= "23";
	cout << ms1 << endl;
}
void test_stream()
{
	MyString ms1(123);
	MyString ms2(456);
	cout << ms1 << ms2;
}
void test_subString()
{
	MyString ms1(123);
	ms1.subString(1, 10);
}
void test_find()
{
	MyString ms1(1234);
	MyString ms2(213);
	ms1.find(ms2);
}
void test_toInt()
{
	MyString ms(123);
	ms.toInt();
	char a[] = "hahaha";
	MyString ms1(a);
	ms1.toInt();
	MyString ms2(12.1);
	cout << ms2;
	double db = 12.0;
	cout << db << endl;
}
void test_tofloat()
{
	MyString ms(12.0);
	cout << ms.my_string_pointer << endl;
	ms.tofloat();
}