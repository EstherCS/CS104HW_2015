#include <iostream>
using namespace std;

#define MAX_POINT  10               // 總共有10個點

bool road[10][10] = { 0 };          // 連接的兩個節點
bool PassPoint[10];                 // 經過的點
int  ExportLine[11];                // 跑出來的路線
int  count = 0;                     // 路線的數目

void Hamilton(int n);               // 執行 Hamilton

int main()
{
	// 連接的兩個節點為 true
	road[0][1] = true;
	road[1][0] = true;
	road[2][1] = true;
	road[1][2] = true;
	road[2][3] = true;
	road[3][2] = true;
	road[3][4] = true;
	road[4][3] = true;
	road[0][4] = true;
	road[4][0] = true;
	road[5][0] = true;
	road[0][5] = true;
	road[6][0] = true;
	road[0][6] = true;
	road[6][5] = true;
	road[5][6] = true;
	road[1][6] = true;
	road[6][1] = true;
	road[1][7] = true;
	road[7][1] = true;
	road[6][7] = true;
	road[7][6] = true;
	road[2][7] = true;
	road[7][2] = true;
	road[2][8] = true;
	road[8][2] = true;
	road[3][8] = true;
	road[8][3] = true;
	road[9][4] = true;
	road[4][9] = true;
	road[5][4] = true;
	road[4][5] = true;
	road[8][7] = true;
	road[7][8] = true;
	road[8][9] = true;
	road[9][8] = true;
	road[3][9] = true;
	road[9][3] = true;
	road[5][9] = true;
	road[9][5] = true;



	PassPoint[0] = true;
	ExportLine[0] = 0;

	Hamilton(1);                                             // 呼叫 Hamilton

	cout << "總共有" << ::count << "條路線" << endl << endl; // 印出路線數目

	system("pause");

	return 0;
}

void Hamilton(int j)                                         // Hamilton function
{
	int x, y;
	if (j == MAX_POINT)                                      // 已走過 10 個點
	{
		x = ExportLine[MAX_POINT - 1];                       // x 設為 最後一點 ExportLine[10-1] = ExportLine[9]
		y = ExportLine[0];                                   // y = ExportLine[0] = 0
		if (road[x][y] == true)                              // 若最後一點與第一點相連 則印出答案 
		{
			for (int i = 0; i <= 10; i++)
			{
				cout << ExportLine[i] << ((i == 10) ? "" : " → ");    // 把路線印出來
			}
			::count++;                                                 // 路線數目 +1
			cout << endl << endl;
		}
		return;
	}
	else                                                   // 尚未走完
	{
		x = ExportLine[j - 1];                             // 設 x 為前一點, x = ExportLine[0] = 0 

		for (int y = 1; y < MAX_POINT; y++)
		{
			if (road[x][y] && !PassPoint[y])               // "xy 是連接的兩點" 和 "y 未走過"
			{
				ExportLine[j] = y;                         // 設 ExportLine[n] 的值為 y ( ExportLine[1] = 1 )
				PassPoint[y] = true;                       // 設 PassPoint[y] 為 true 代表跑過了 ( PassPoint[1] = true )

				Hamilton(j + 1);                           // 再次呼叫 Hamilton function ( 遞迴走下一點 )
				PassPoint[y] = false;                      // 設 PassPoint[y] 為 false ( PassPoint[1] = false )
			}
		}
	}
}
/*
╭─┬─┬─┬─┬─┬─┬─┬─┬─┬─╮
│0 │ 1│ 2│ 3│ 4│ 5│ 6│ 7│ 8│ 9│                          ExportLine 執行完的值
╰┬┴┬┴┬┴┬┴┬┴┬┴┬┴┬┴┬┴┬╯                          接下來去比對最後一格的數字能否接回起點 ( 9 -> 0 )
  │  │  │  │  │  │  │  │  │  │                            若不能就逆推回去一格 ( 8 )
  │  │  │  │  │  │  │  │  │╭┴┬─┬─┬─╮              直到找到此格道起點的全部路線後
  │  │  │  │  │  │  │  │    │3 │ 4│ 5│ 8│              再逆推回前一格 ( 7 )
  │  │  │  │  │  │  │        ╰┬┴┬┴┬┴┬╯              尋找能接回起點的路線 ( 7 -> ? -> ? - > 0 )
  │  │  │  │  │  │              │  │  │  │                依此類推
  │  │  │  │  │                  │  │  │
  │  │  │  │                      │  │
  │  │  │                          │
  │  │                            ╭┴┬─┬─╮
  │ {0, 2, 6, 7}                   │2 │ 8│ 4│
╭┴┬─┬─┬─╮                  ╰┬┴┬┴┬╯
│1 │ 4│ 5│ 6│                    │  │  │
╰┬┴┬┴┬┴┬╯                    │  │
  │  │  │  │                      │
  │  │  │                        ╭┴┬─┬─╮
  │  │                            │1 │7 │ 8│
  │                                ╰┬┴┬┴┬╯
  │
╭┴┬─┬─╮
│2 │ 6│ 7│
╰┬┴┬┴┬╯
  │  │  │
  │  │
  │
╭┴┬─┬─╮
│3 │7 │ 8│
╰┬┴┬┴┬╯
  │  │  │
  │  │
  │

*/