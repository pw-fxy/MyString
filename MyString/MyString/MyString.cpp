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
	cout << "my_string1\n";
};
MyString::~MyString()
{
	//cout << "deconstructor\n";
	delete[lenth_my_string+1] my_string_pointer;
}




void test_constructor();//构造函数的测试
void test_int_constructor();
void test_buffer_constructor();
int main()
{
	test_buffer_constructor();

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

//MyString ms2 = MyString(10);这是不合法的