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

## 2021年11月9日

完成了+=的重载

完成了-=（int)的重载

完成了<<的重载

## 2021年11月10日

完成了-=(string)的重载

完成了temp.subString(m,n);

完成了find函数

完成了toInt函数

## 2021年11月12日

完成了tofloat函数

缩短了double构造的长度，只保留小数点后一位，向现实妥协。

接下来需要继续优化代码。

## 2021年11月13日

完成了减法重载。

完成了toint 和tofloat的返回值，而不是直接在函数内部输出。



## 2021年11月20日

复制构造函数必须是本类型的一个引用

## 2021年11月27日

写输出友元函数时遇到的问题，已经解决

[友元函数模板问题_行者无疆-CSDN博客](https://blog.csdn.net/dongzhongshu/article/details/6200466)

如何确定bufffer的长度

MyMatrix需要解决强制类型转换的问题。

在函数中的变量不能用引用的方式返回，还是得传值，不然再想用的时候会被清除。

完成了构造函数和+-重载



## 2021年12月10日

完成了要求的基础操作。

delete和new的内存泄露问题还没有解决。
