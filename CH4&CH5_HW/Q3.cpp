#include <iostream>
using namespace std;
//�w�q�`��
const int MAXSIZE = 6;
//�w�q�禡
void enterArray(int[], int);            //��J���Z
int searchArray(const int[], int, int); //�d�ߦ��Z

int main()
{
	//�w�q�ܼ�
	int grade[MAXSIZE];              //���Zarray
	int target = 0, sum = 0, i = 0;  //��l���ܼ�

	//��J���Z
	enterArray(grade, MAXSIZE);

	//�d�ߨC�@��target(0,1...5)
	for (target; target < MAXSIZE; target++)
	{
		sum = searchArray(grade, MAXSIZE, target);
		cout << sum << " grade(s) of " << target << endl;
		sum = 0;
	}

	return 0;
}

void enterArray(int grade[], int size)
{
	cout << "Enter up to " << size << " grades > ";
	//�N�C�@�����]�L�@��(0,1...5)
	for (int i = 0; i < size; i++)
	{
		cin >> grade[i];
	}
}

int searchArray(const int grade[], int size , int target)
{
	int sum = 0;
	//�N�C�@�����d�ߤ@��
	for (int i = 0; i < size; i++)
	{
		if (target == grade[i])
		{
			sum++;
		}
	}

	return sum;
}