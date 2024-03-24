#include <iostream>
using namespace std;

double convertToMPH(int, int); //�ϥΤ���,�� �p��
double convertToMPH(double);   //�ϥ�KPH�p��

int main()
{
	//�w�q�ܼ�
	int minute, second;         //����,��
	double KPH, MPH1, MPH2;     //KPH,MPH
	//��J����,��
	cout << "Enter minute and seconds ";
	cin >> minute >> second;
	//��JKPH
	cout << "Enter KPH ";
	cin >> KPH;
	//�p��
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