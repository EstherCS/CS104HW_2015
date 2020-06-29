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

	cout << "Enter the number of items in Set: ";  // 輸入有幾個數字
	cin >> ValueCt;

	cout << "Enter " << ValueCt << " items:";
	for (i = 0; i< ValueCt; i++)   
	{
		cin >> Value[i];                           // 輸入數字
	}

	cout << "Enter the bin size: ";                // 輸入箱子大小
	cin >> MAX_IN_BOX;

	BoxIdx = 0;                                    // 計算使用幾個箱子
	int num = ValueCt;

	while (ValueCt)                                // 利用 ValueCt 當作判斷依據
	{
		cout << "******************************************\n";
		MaxSum = 0;                                // 設定最大值
		for (i = 1; i <= num; i++)
		{
			cout << "\nN = " << num << ", M = " << i << endl; // 計算組合
			Combination(num, i, i);
		}

		for (i = 0; i < MaxM; i++)
		{
			Value[MaxCombinationIndex[i]] = MAX_IN_BOX + 1;  // 去掉組合
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

// n 取 M ( Initial m = M ) 組合
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
			CombinationIndex[m - 1] = i;  // 設定索引號碼
			Combination(i, m - 1, M);     //  recursive 找組合
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
		Sum += Value[CombinationIndex[i]]; // 計算組合相加的值
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
				MaxCombinationIndex[i] = CombinationIndex[i]; // 放到準備更改值的陣列裡 ( 原本的值會變成 MAX_IN_BOX + 1 )
			}
			cout << " Find Max " << endl;
		}
	}
}