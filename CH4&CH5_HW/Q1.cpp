//Convert 24hour to 12hour
#include <iostream>
using namespace std;

//輸入小時,分鐘
void input_time(int&, int&);
//從24小時制轉換成12小時制
void convert_time(int&, int&, char&);
//印出結果
void output_time(int, int, char);

int main()
{
	//定義變數
	char decision = 'y';              //判斷是否要重複
	char current_time = 'A';          //判斷AM PM
	int time_hour = 0, time_min = 0;  //小時,時間

	//當decision不等n 重複執行
	while (decision != 'n')
	{
		input_time(time_hour, time_min);
		convert_time(time_hour, time_min,current_time);
		output_time(time_hour, time_min, current_time);

		cout << "Would you like to enter the time again?\n"
			<< "y to continue,n to end.\n";

		//輸入decision
		cin >> decision;
	}
	return 0;
}


void input_time(int& hour, int& min)
{
	//輸入小時,分鐘
	cout << "Please enter time, separte hour and minute with space.(XX XX)\n";
	cin >> hour >> min;
}
void convert_time(int& hour, int& min, char& time)
{
	//使超出範圍的數迴歸
	while (min >=60)
	{
		hour += 1;
		min -=60;
	}
	while (hour >=24)
	{
		hour -= 24;
	}
	//判斷AM PM
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
	//輸出AM PM
	if (time == 'A')
	{
		cout << "The current time now is " << hour << ":" << min << " AM\n";
	}
	else if (time == 'P')
	{
		cout << "The current time now is " << hour << ":" << min << " PM\n";
	}
}