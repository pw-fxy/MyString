#include <iostream>
using namespace std;
class MyString
{
public:

	char* my_string_pointer;
	int lenth_my_string;

	MyString();
	MyString(int);
	MyString(char *);
	MyString(MyString &ms);
	~MyString();



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
	char* my_string_pointer = new char[length];

	for (int i = 0; i < length; i++)
	{
		my_string_pointer[length - i] = char(48 + temp_int / (10 * length - i));
	}
	cout << "length"<<length << endl;//打印长度
	
};
MyString::MyString(char* buffer)
{
	cout << "buffer\n";
};
MyString::MyString( MyString & my_string1)
{
	cout << "my_string1\n";
};
MyString::~MyString()
{
	cout << "deconstructor\n";
}




void test_constructor();//构造函数的测试
int main()
{
	test_constructor();
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

//MyString ms2 = MyString(10);这是不合法的