#include <iostream>
#include<string>
using namespace std;

class big
{
private:
	string result;//���
	string remain;//����
public:
	
	big() {}
	big(string b_number1, char b_ch, string b_number2); //�������
	inline int compare(string number1, string number2);	//�ȴ�С
	string ADD(string number1, string number2);			//�ӷ�,
	string SUB(string number1, string number2);			//����
	string MUL(string number1, string number2);			//�˷� 
	void DIV(string number1, string number2, string &quotient, string &remainder);		//����
	string POWER(string number1, string number2);
	string big::getresult();
	string big::getremain();
	~big() {};   
};

