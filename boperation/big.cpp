#include <iostream>
#include<cmath>
#include<string>
#include "big.h"
using namespace std;

//运算符号处理

big::big(string b_number1, char b_ch, string b_number2)
{

	string tresult;//临时结果
	string tremain;//临时余数
	switch (b_ch)
	{
	case'+':
		result = ADD(b_number1, b_number2); remain = "无"; break;
	case'-':
		result = SUB(b_number1, b_number2); remain = "无"; break;
	case'*':
		result = MUL(b_number1, b_number2); remain = "无"; break;
	case'^':
		result = MUL(b_number1, b_number1); remain = "无"; break;
	case'/':
		DIV(b_number1, b_number2, tresult, tremain); result = tresult; remain = "无"; break;
	case'%':
		DIV(b_number1, b_number2, tresult,tremain); result = tresult; remain = tremain; break;
	default:
		break;
	}

}

string big::getresult()
{
	return result; 
}
string big::getremain()
{
	return remain;
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
string big::ADD(string number1, string number2)         //加法
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
	int sign = 1;
	string str = "0";        //记录当前值
	if (number1[0] == '-')
	{
		sign *= -1;
		number1 = number1.erase(0, 1);
	}
	if (number2[0] == '-')
	{
		sign *= -1;
		number2 = number2.erase(0, 1);
	}
	int i, j;
	string::size_type L1, L2;
	L1 = number1.size();
	L2 = number2.size();
	for (i = L2 - 1; i >= 0; i--)              //模拟手工乘法竖式
	{
		string tempstr;
		int int1 = 0, int2 = 0, int3 = int(number2[i]) - '0';
		if (int3 != 0)
		{
			for (j = 1; j <= (int)(L2 - 1 - i); j++)
				tempstr = "0" + tempstr;
			for (j = L1 - 1; j >= 0; j--)
			{
				int1 = (int3*(int(number1[j]) - '0') + int2) % 10;
				int2 = (int3*(int(number1[j]) - '0') + int2) / 10;
				tempstr = char(int1 + '0') + tempstr;
			}
			if (int2 != 0)tempstr = char(int2 + '0') + tempstr;
		}
		str = ADD(str, tempstr);
	}
	//去除结果中的前导0
	str.erase(0, str.find_first_not_of("0"));
	if (str.empty())str = "0";
	if ((sign == -1) && (str[0] != '0'))str = "-" + str;
	return str;
}

void big::DIV(string number1,string number2, string &quotient, string &remainder) //除法
{
	int sign1 = 1, sign2 = 1;
	
	if (number2 == "0")   //判断除数是否为0
	{
		quotient = "ERROR!";
		remainder = "ERROR!";
		return;
	}
	if (number1 == "0")     //判断被除数是否为0
	{
		quotient = "0";
		remainder = "0";
		return;
	}
	if (number1[0] == '-')
	{
		number1 = number1.erase(0, 1);
		sign1 *= -1;
		sign2 = -1;
	}
	if (number2[0] == '-')
	{
		number2 = number2.erase(0, 1);
		sign1 *= -1;
	}
	int res = compare(number1, number2);
	if (res < 0)
	{
		quotient = "0";
		remainder = number1;
	}
	else if (res == 0)
	{
		quotient = "1";
		remainder = "0";
	}
	else
	{
		string::size_type L1, L2;
		L1 = number1.size();
		L2 = number2.size();
		string tempstr;
		tempstr.append(number1, 0, L2 - 1); //将str1中为值0到L2-1的字符串追加到tempstr
		for (int i = L2 - 1; i < L1; i++)  //模拟手工除法竖式
		{
			tempstr = tempstr + number1[i];
			tempstr.erase(0, tempstr.find_first_not_of('0')); //在字符串中查找第一个与'0'不匹配的字符，返回它的位置
			if (tempstr.empty())tempstr = "0";  //q.empty()，当队列空时，返回true
			for (char ch = '9'; ch >= '0'; ch--) //试商
			{
				string str;
				str = str + ch;
				if (compare(MUL(number2, str), tempstr) <= 0)
				{
					quotient = quotient + ch;
					tempstr = SUB(tempstr, MUL(number2, str));
					break;
				}
			}
		}
		remainder = tempstr;
	}
	//去除结果中的前导0
	quotient.erase(0, quotient.find_first_not_of("0"));
	if (quotient.empty())quotient = "0";
	if ((sign1 == -1) && (quotient[0] != '0'))quotient = "-" + quotient;
	if ((sign2 == -1) && (remainder[0] != '0'))remainder = "-" + remainder;
	
}

