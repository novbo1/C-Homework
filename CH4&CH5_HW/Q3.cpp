#include <iostream>
using namespace std;
//﹚竡盽计
const int MAXSIZE = 6;
//﹚竡ㄧΑ
void enterArray(int[], int);            //块Θ罿
int searchArray(const int[], int, int); //琩高Θ罿

int main()
{
	//﹚竡跑计
	int grade[MAXSIZE];              //Θ罿array
	int target = 0, sum = 0, i = 0;  //﹍て跑计

	//块Θ罿
	enterArray(grade, MAXSIZE);

	//琩高–target(0,1...5)
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
	//盢–兜常禲筁Ω(0,1...5)
	for (int i = 0; i < size; i++)
	{
		cin >> grade[i];
	}
}

int searchArray(const int grade[], int size , int target)
{
	int sum = 0;
	//盢–兜常琩高Ω
	for (int i = 0; i < size; i++)
	{
		if (target == grade[i])
		{
			sum++;
		}
	}

	return sum;
}