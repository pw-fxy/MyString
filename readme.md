## 2021年11月4日

**问题：**构造函数是没有返回值的，因此不能使用MyString ms= MyString(10)匿名构造函数。

## 2021年11月5日

算法课程作业，要求在txt中。远程仓库以及本地仓库的建立日期，希望用这个来联系自己项目管理的能力，欢迎借鉴，敬请指正！

目前完成了int构造函数和char*(buffer)构造函数。眼下还有double以及运算符重载。

## 2021年11月7日

新增了copy_constructor 和float_constructor,需要解决的是浮点数的拷贝构造函数是没有办法准确表示12.3的，可能会表示为12.29999

我的想法是，通过12.3+0.0001表示12.3,这样可以尽量准确表示。

尝试重载=

debug



**问题：**运算符=重载时，需要const		MyString& MyString::operator=(const MyString& ms1)

[C++之error: cannot bind non-const lvalue reference of type ‘myString&’ to an rvalue of type ‘myString_digitalkee的博客-CSDN博客](https://blog.csdn.net/digitalkee/article/details/105092400)

## 2021年11月8日

