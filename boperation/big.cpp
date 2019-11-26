#include <iostream>
#include<cmath>
#include<string>
#include "big.h"
using namespace std;

//������Ŵ���

big::big(string b_number1, char b_ch, string b_number2)
{

	string tresult;//��ʱ���
	string tremain;//��ʱ����
	switch (b_ch)
	{
	case'+':
		result = ADD(b_number1, b_number2); remain = "��"; break;
	case'-':
		result = SUB(b_number1, b_number2); remain = "��"; break;
	case'*':
		result = MUL(b_number1, b_number2); remain = "��"; break;
	case'^':
		result = MUL(b_number1, b_number1); remain = "��"; break;
	case'/':
		DIV(b_number1, b_number2, tresult, tremain); result = tresult; remain = "��"; break;
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


//�ȽϺ��������ԱȽ�����ʵ�ʴ�С
inline int big::compare(string number1, string number2) //��ȷ���0�����ڷ���1��С�ڷ���-1
{
	if (number1.size() > number2.size())
		return 1;
	else if (number1.size() < number2.size())
		return -1;
	else return number1.compare(number2);     //��������ȣ����ͷ��β��λ�Ƚ�
}

//�ӷ�����
string big::ADD(string number1, string number2)         //�ӷ�
{
	int sign = 1;//signΪ����Ϊ
	string num;//���
	if (number1[0] == '-')
	{
		if (number2[0] == '-')       //����
		{
			sign = -1;
			num = ADD(number1.erase(0, 1), number2.erase(0, 1));//erase(first,last);ɾ����first��last֮����ַ�
		}
		else             //����
		{
			num = SUB(number2, number1.erase(0, 1));
		}
	}
	else
	{
		if (number2[0] == '-')        //����
		{
			num = SUB(number1, number2.erase(0, 1));
		}
		else                    //�������������������룬������ǰ���0����
		{
			string::size_type L1, L2;  //string::size_type���������ǳߴ絥λ����
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
			int int1 = 0, int2 = 0; //int2��¼��λ
			for (i = number1.size() - 1; i >= 0; i--)
			{
				int1 = (int(number1[i]) - '0' + int(number2[i]) - '0' + int2) % 10;
				int2 = (int(number1[i]) - '0' + int(number2[i]) - '0' + int2) / 10;
				num = char(int1 + '0') + num;
			}
			if (int2 != 0)num = char(int2 + '0') + num;
		}

	}
	//������������
	if ((sign == -1) && (num[0] != '0'))num = "-" + num;
	return num;

}

string big::SUB(string number1, string number2)  //����
{
	int sign = 1; //signΪ����λ
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
			if (number1[i + tempint] < number2[i])          //��λ
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
	//ȥ������ж����ǰ��0
	str.erase(0, str.find_first_not_of('0'));
	if (str.empty())str = "0";
	if ((sign == -1) && (str[0] != '0'))str = "-" + str;
	return str;
}

string big::MUL(string number1, string number2)     //�˷� 
{
	int sign = 1;
	string str = "0";        //��¼��ǰֵ
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
	for (i = L2 - 1; i >= 0; i--)              //ģ���ֹ��˷���ʽ
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
	//ȥ������е�ǰ��0
	str.erase(0, str.find_first_not_of("0"));
	if (str.empty())str = "0";
	if ((sign == -1) && (str[0] != '0'))str = "-" + str;
	return str;
}

void big::DIV(string number1,string number2, string &quotient, string &remainder) //����
{
	int sign1 = 1, sign2 = 1;
	
	if (number2 == "0")   //�жϳ����Ƿ�Ϊ0
	{
		quotient = "ERROR!";
		remainder = "ERROR!";
		return;
	}
	if (number1 == "0")     //�жϱ������Ƿ�Ϊ0
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
		tempstr.append(number1, 0, L2 - 1); //��str1��Ϊֵ0��L2-1���ַ���׷�ӵ�tempstr
		for (int i = L2 - 1; i < L1; i++)  //ģ���ֹ�������ʽ
		{
			tempstr = tempstr + number1[i];
			tempstr.erase(0, tempstr.find_first_not_of('0')); //���ַ����в��ҵ�һ����'0'��ƥ����ַ�����������λ��
			if (tempstr.empty())tempstr = "0";  //q.empty()�������п�ʱ������true
			for (char ch = '9'; ch >= '0'; ch--) //����
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
	//ȥ������е�ǰ��0
	quotient.erase(0, quotient.find_first_not_of("0"));
	if (quotient.empty())quotient = "0";
	if ((sign1 == -1) && (quotient[0] != '0'))quotient = "-" + quotient;
	if ((sign2 == -1) && (remainder[0] != '0'))remainder = "-" + remainder;
	
}

