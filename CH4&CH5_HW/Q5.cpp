#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//定義常數
const int SIZE1 = 5;
const int SIZE2 = 10;
//定義函式
void random(int[], int);                              //隨機數
void printPIN(int);                                   //將PIN號印出
void printArray(int[], int);                          //將陣列印出(randomized)
bool test(const int[], const int[], int, int, int);   //做測試(有沒有對應到)

int main()
{
	//設定隨機數
	srand(time(NULL));
	//定義變數
	int original[SIZE1] = { 1,2,3,4,5 };  //假設密碼是12345
	int randomized[SIZE2];                //NUM
	int code;                             //對應的code
	//將randomized的每個值設為1~3的隨機數
	random(randomized, SIZE2);
	//將格式列出
	printPIN(SIZE2);
	printArray(randomized,SIZE2);
	//輸入code
	cout << "Enter 5 digits of password >  ";
	cin >> code;
	//測試有沒有對應到
	bool result = test(randomized, original, SIZE1, SIZE2, code);
	//印出結果
	cout << (result ? "Matched." : "Failed.") << endl;
	return 0;
}

void random(int array[], int size)
{
	//每一項設為1~3隨機數
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
	//定義變數
	int userCode[SIZE1];  
	int temp = code;
	//將code變為一個一個的數
	for (int i = SIZE1 - 1; i >= 0; i--)
	{
		userCode[i] = temp % 10;
		temp /= 10;
	}
	//判斷輸入的NUM會不會對應到密碼
	for (int i = 0; i < SIZE1; i++)
	{
		if (randomized[original[i]] != userCode[i])
		{
			return false;
		}
	}

	return true;
}
