#include <iostream>
#include<string>
using namespace std;

class big
{
public:
	big() {}
	big(string b_number1, char b_ch, string b_number2); //运算符号
	inline int compare(string number1, string number2);	//比大小
	string ADD(string number1, string number2);			//加法
	string SUB(string number1, string number2);			//减法
	string MUL(string number1, string number2);			//乘法 
	string DIV(string number1, string number2);		//除法
	string big::get();
	~big() {};   
};

