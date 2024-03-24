#include <iostream>
using namespace std;

double convertToMPH(int, int); //使用分鐘,秒 計算
double convertToMPH(double);   //使用KPH計算

int main()
{
	//定義變數
	int minute, second;         //分鐘,秒
	double KPH, MPH1, MPH2;     //KPH,MPH
	//輸入分鐘,秒
	cout << "Enter minute and seconds ";
	cin >> minute >> second;
	//輸入KPH
	cout << "Enter KPH ";
	cin >> KPH;
	//計算
	MPH1 = convertToMPH(minute, second);
	MPH2 = convertToMPH(KPH);
	
	cout << "The answer by using minute and second to caculate is > " << MPH1 << " MPH" << endl;
	cout << "The answer by using KPH to caculate is > " << MPH2 << " MPH" << endl;
	
	return 0;
}

double convertToMPH(int minute, int second)
{
	double totalTime;
	totalTime = minute * 60 + second;

	return 1/(totalTime / 3600.0);
}
double convertToMPH(double KPH)
{
	return (KPH / 1.61);
}