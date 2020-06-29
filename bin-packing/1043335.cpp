#include<iostream>
using namespace std;

#define MAX_VALUE      100

int CombinationIndex[MAX_VALUE];
int Value[MAX_VALUE];
int MaxSum = 0;
int MaxCombinationIndex[MAX_VALUE];
int Box[MAX_VALUE];
int MaxM;
int MAX_IN_BOX;

void Combination(int n, int m, int M);
void PrintResult(int M);


int main(int argc, char **argv)
{
	int i;
	int BoxIdx;
	int ValueCt;

	cout << "Enter the number of items in Set: ";  // ��J���X�ӼƦr
	cin >> ValueCt;

	cout << "Enter " << ValueCt << " items:";
	for (i = 0; i< ValueCt; i++)   
	{
		cin >> Value[i];                           // ��J�Ʀr
	}

	cout << "Enter the bin size: ";                // ��J�c�l�j�p
	cin >> MAX_IN_BOX;

	BoxIdx = 0;                                    // �p��ϥδX�ӽc�l
	int num = ValueCt;

	while (ValueCt)                                // �Q�� ValueCt ��@�P�_�̾�
	{
		cout << "******************************************\n";
		MaxSum = 0;                                // �]�w�̤j��
		for (i = 1; i <= num; i++)
		{
			cout << "\nN = " << num << ", M = " << i << endl; // �p��զX
			Combination(num, i, i);
		}

		for (i = 0; i < MaxM; i++)
		{
			Value[MaxCombinationIndex[i]] = MAX_IN_BOX + 1;  // �h���զX
			ValueCt--;
		}
		cout << "Box[ " << BoxIdx << " ] = " << MaxSum << endl;
		Box[BoxIdx] = MaxSum;
		BoxIdx++;
	}
	cout << "\n------------------------------------------\n";
	cout << "Toatl = " << BoxIdx << endl;

	system("pause");
}

// n �� M ( Initial m = M ) �զX
void Combination(int n, int m, int M)
{
	int i;

	if (m == 0)
	{
		PrintResult(M);
		return;
	}
	else
	{
		for (i = n - 1; i >= 0; i--)
		{
			CombinationIndex[m - 1] = i;  // �]�w���޸��X
			Combination(i, m - 1, M);     //  recursive ��զX
		} 
	}
}

void PrintResult(int M)
{
	int i;
	int Sum = 0;

	for (i = 0; i < M; i++)
	{
		cout << CombinationIndex[i];
		Sum += Value[CombinationIndex[i]]; // �p��զX�ۥ[����
	}
	cout << ", sum = " << Sum << endl;

	if (Sum <= MAX_IN_BOX)
	{
		if (Sum > MaxSum)
		{
			MaxSum = Sum;
			MaxM = M;
			for (i = 0; i < M; i++)
			{
				MaxCombinationIndex[i] = CombinationIndex[i]; // ���ǳƧ��Ȫ��}�C�� ( �쥻���ȷ|�ܦ� MAX_IN_BOX + 1 )
			}
			cout << " Find Max " << endl;
		}
	}
}