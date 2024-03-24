#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//�w�q�`��
const int SIZE1 = 5;
const int SIZE2 = 10;
//�w�q�禡
void random(int[], int);                              //�H����
void printPIN(int);                                   //�NPIN���L�X
void printArray(int[], int);                          //�N�}�C�L�X(randomized)
bool test(const int[], const int[], int, int, int);   //������(���S��������)

int main()
{
	//�]�w�H����
	srand(time(NULL));
	//�w�q�ܼ�
	int original[SIZE1] = { 1,2,3,4,5 };  //���]�K�X�O12345
	int randomized[SIZE2];                //NUM
	int code;                             //������code
	//�Nrandomized���C�ӭȳ]��1~3���H����
	random(randomized, SIZE2);
	//�N�榡�C�X
	printPIN(SIZE2);
	printArray(randomized,SIZE2);
	//��Jcode
	cout << "Enter 5 digits of password >  ";
	cin >> code;
	//���զ��S��������
	bool result = test(randomized, original, SIZE1, SIZE2, code);
	//�L�X���G
	cout << (result ? "Matched." : "Failed.") << endl;
	return 0;
}

void random(int array[], int size)
{
	//�C�@���]��1~3�H����
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 3 + 1;
	}
}
void printPIN(int size)
{
	cout << "PIN:  ";
	for (int i = 0; i < size; i++)
	{
		cout << i << " ";
	}
	cout << endl;
}
void printArray(int array[], int size)
{
	cout << "NUM:  ";
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
bool test(const int randomized[], const int original[], int size1, int size2, int code)
{
	//�w�q�ܼ�
	int userCode[SIZE1];  
	int temp = code;
	//�Ncode�ܬ��@�Ӥ@�Ӫ���
	for (int i = SIZE1 - 1; i >= 0; i--)
	{
		userCode[i] = temp % 10;
		temp /= 10;
	}
	//�P�_��J��NUM�|���|������K�X
	for (int i = 0; i < SIZE1; i++)
	{
		if (randomized[original[i]] != userCode[i])
		{
			return false;
		}
	}

	return true;
}
