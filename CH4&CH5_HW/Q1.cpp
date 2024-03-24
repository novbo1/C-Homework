//Convert 24hour to 12hour
#include <iostream>
using namespace std;

//��J�p��,����
void input_time(int&, int&);
//�q24�p�ɨ��ഫ��12�p�ɨ�
void convert_time(int&, int&, char&);
//�L�X���G
void output_time(int, int, char);

int main()
{
	//�w�q�ܼ�
	char decision = 'y';              //�P�_�O�_�n����
	char current_time = 'A';          //�P�_AM PM
	int time_hour = 0, time_min = 0;  //�p��,�ɶ�

	//��decision����n ���ư���
	while (decision != 'n')
	{
		input_time(time_hour, time_min);
		convert_time(time_hour, time_min,current_time);
		output_time(time_hour, time_min, current_time);

		cout << "Would you like to enter the time again?\n"
			<< "y to continue,n to end.\n";

		//��Jdecision
		cin >> decision;
	}
	return 0;
}


void input_time(int& hour, int& min)
{
	//��J�p��,����
	cout << "Please enter time, separte hour and minute with space.(XX XX)\n";
	cin >> hour >> min;
}
void convert_time(int& hour, int& min, char& time)
{
	//�϶W�X�d�򪺼ưj�k
	while (min >=60)
	{
		hour += 1;
		min -=60;
	}
	while (hour >=24)
	{
		hour -= 24;
	}
	//�P�_AM PM
	if (hour >= 12)
	{
		time = 'P';
		hour -= 12;
	}
	else
	{
		time = 'A';
	}

}

void output_time(int hour, int min, char time)
{
	//��XAM PM
	if (time == 'A')
	{
		cout << "The current time now is " << hour << ":" << min << " AM\n";
	}
	else if (time == 'P')
	{
		cout << "The current time now is " << hour << ":" << min << " PM\n";
	}
}