#include <iostream>
#include<cmath>
#include<string>
#include "big.h"
using namespace std;

//运算符号处理
string result;
big::big(string b_number1, char b_ch, string b_number2)
{

	
	switch (b_ch)
	{
	case'+':
		result = ADD(b_number1, b_number2); break;
	case'-':
		result = SUB(b_number1, b_number2); break;
	case'*':
		result = MUL(b_number1, b_number2); break;
	case'/':
		result = DIV(b_number1, b_number2); break;
	default:
		break;
	}

}

string big::get()
{
	return result; 
}


//比较函数，可以比较两数实际大小


inline int big::compare(string number1, string number2) //相等返回0，大于返回1，小于返回-1
{
	if (number1.size() > number2.size())
		return 1;
	else if (number1.size() < number2.size())
		return -1;
	else return number1.compare(number2);     //若长度相等，则从头到尾按位比较
}

//加法运算
string big::ADD(string number1, string number2)         //高精度加法
{
	int sign = 1;//sign为符号为
	string num;//结果
	if (number1[0] == '-')
	{
		if (number2[0] == '-')       //负负
		{
			sign = -1;
			num = ADD(number1.erase(0, 1), number2.erase(0, 1));//erase(first,last);删除从first到last之间的字符
		}
		else             //负正
		{
			num = SUB(number2, number1.erase(0, 1));
		}
	}
	else
	{
		if (number2[0] == '-')        //正负
		{
			num = SUB(number1, number2.erase(0, 1));
		}
		else                    //正正，把两个整数对齐，短整数前面加0补齐
		{
			string::size_type L1, L2;  //string::size_type抽象意义是尺寸单位类型
			int i;
			L1 = number1.size();
			L2 = number2.size();
			if (L1 < L2)
			{
				for (i = 0; i < L2 - L1; i++)
					number1 = "0" + number1;
			}
			else
			{
				for (i = 0; i < L1 - L2; i++)
					number2 = "0" + number2;
			}
			int int1 = 0, int2 = 0; //int2记录进位
			for (i = number1.size() - 1; i >= 0; i--)
			{
				int1 = (int(number1[i]) - '0' + int(number2[i]) - '0' + int2) % 10;
				int2 = (int(number1[i]) - '0' + int(number2[i]) - '0' + int2) / 10;
				num = char(int1 + '0') + num;
			}
			if (int2 != 0)num = char(int2 + '0') + num;
		}

	}
	//运算符处理符号
	if ((sign == -1) && (num[0] != '0'))num = "-" + num;
	return num;

}

string big::SUB(string number1, string number2)  //减法
{
	int sign = 1; //sign为符号位
	string str;
	int i, j;
	if (number2[0] == '-')
	{
		str = ADD(number1, number2.erase(0, 1));
	}
	else
	{
		int res = compare(number1, number2);
		if (res == 0)return "0";
		if (res < 0)
		{
			sign = -1;
			string temp = number1;
			number1 = number2;
			number2 = temp;
		}
		string::size_type tempint;
		tempint = number1.size() - number2.size();
		for (i = number2.size() - 1; i >= 0; i--)
		{
			if (number1[i + tempint] < number2[i])          //借位
			{
				j = 1;
				while (1)
				{
					if (number1[tempint - j + i] == '0')
					{
						number1[i + tempint - j] = '9';
						j++;
					}
					else
					{
						number1[i + tempint - j] = char(int(number1[i + tempint - j]) - 1);
						break;
					}
				}
				str = char(number1[i + tempint] - number2[i] + ':') + str;
			}
			else
			{
				str = char(number1[i + tempint] - number2[i] + '0') + str;
			}
		}
		for (i = tempint - 1; i >= 0; i--)
			str = number1[i] + str;
	}
	//去出结果中多余的前导0
	str.erase(0, str.find_first_not_of('0'));
	if (str.empty())str = "0";
	if ((sign == -1) && (str[0] != '0'))str = "-" + str;
	return str;
}

string big::MUL(string number1, string number2)     //乘法 
{
	return 0;
}

string big::DIV(string number1, string number2) //除法
{
	
		return 0;
}
