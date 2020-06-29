#include <iostream>
#include <vector>
#include <string>
using namespace std;

string sixteen[1] = { "1" };
string eight[8] = { "0 2 2 2", "2 1 2 2", "1 2 2 2", "2 2 0 2", "2 2 2 1", "2 2 1 2", "2 2 2 0", "2 0 2 2" };
string four[24] = { "0 0 2 2", "0 1 2 2", "1 1 2 2", "1 0 2 2", "2 2 0 0", "2 2 0 1", "2 2 1 1", "2 2 1 0",
"0 2 0 2", "0 2 2 1", "0 2 1 2", "2 1 0 2", "2 1 2 1", "2 1 1 2", "1 2 0 2", "1 2 2 1", "1 2 1 2", "2 0 0 2",
"2 0 2 1", "2 0 1 2", "0 2 2 0", "2 1 2 0", "1 2 2 0", "2 0 2 0" };
string TWOandONE[4][4] = { "0 0 0 0", "0 0 0 1", "0 0 1 1", "0 0 1 0", "0 1 0 0", "0 1 0 1", "0 1 1 1", "0 1 1 0",
"1 1 0 0", "1 1 0 1", "1 1 1 1", "1 1 1 0", "1 0 0 0", "1 0 0 1", "1 0 1 1", "1 0 1 0" };

int main()
{
	int times = 1;
	int kmap[4][4] = {};        // 存 KMAP 的輸入
	int count[4][4] = {};       // 存取被圈了幾次
	int Kcase[32] = {};         // 判斷八個四個的是否存在
	int num;                    // 有幾個 KMAP
	bool all = false;
	cin >> num;
	while (num--)
	{
		vector<int> two;         // 存放兩個相鄰的
		vector<int> one;         // 存放單獨存在的
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				cin >> kmap[i][j];
		}

		int counter = 0;
		for (int i = 0; i < 4; i++)               // 十六格全部都是 1     
		{
			for (int j = 0; j < 4; j++)
			{
				if (kmap[i][j] != 0)
				{
					counter++;
				}
			}
		}
		if (counter == 16)
		{
			all = true;
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					count[i][j]++;
				}
			}
		}
		//////////////////////////////////////////// 十六個結束
		if (!all)
		{
			counter = 0;
			for (int i = 0; i < 2; i++)           // 一二行都有 8 個
			{
				for (int j = 0; j < 4; j++)
				{
					if (kmap[i][j] != 0)
					{
						counter++;
					}
				}
			}
			if (counter == 8)
			{
				Kcase[0]++;
				for (int i = 0; i < 2; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						count[i][j]++;
					}
				}
			}

			counter = 0;
			for (int i = 1; i < 3; i++)           // 二三行都有 8 個
			{
				for (int j = 0; j < 4; j++)
				{
					if (kmap[i][j] != 0)
					{
						counter++;
					}
				}
			}
			if (counter == 8)
			{
				Kcase[1]++;
				for (int i = 1; i < 3; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						count[i][j]++;
					}
				}
			}

			counter = 0;
			for (int i = 2; i < 4; i++)           // 三四行都有 8 個
			{
				for (int j = 0; j < 4; j++)
				{
					if (kmap[i][j] != 0)
					{
						counter++;
					}
				}
			}
			if (counter == 8)
			{
				Kcase[2]++;
				for (int i = 2; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						count[i][j]++;
					}
				}
			}

			counter = 0;
			for (int i = 0; i < 2; i++)           // 一二列都有 8 個
			{
				for (int j = 0; j < 4; j++)
				{
					if (kmap[j][i] != 0)
					{
						counter++;
					}
				}
			}
			if (counter == 8)
			{
				Kcase[3]++;
				for (int i = 0; i < 2; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						count[j][i]++;
					}
				}
			}

			counter = 0;
			for (int i = 1; i < 3; i++)           // 二三列都有 8 個
			{
				for (int j = 0; j < 4; j++)
				{
					if (kmap[j][i] != 0)
					{
						counter++;
					}
				}
			}
			if (counter == 8)
			{
				Kcase[4]++;
				for (int i = 1; i < 3; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						count[j][i]++;
					}
				}
			}

			counter = 0;
			for (int i = 2; i < 4; i++)           // 三四列都有 8 個
			{
				for (int j = 0; j < 4; j++)
				{
					if (kmap[j][i] != 0)
					{
						counter++;
					}
				}
			}
			if (counter == 8)
			{
				Kcase[5]++;
				for (int i = 2; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						count[j][i]++;
					}
				}
			}

			counter = 0;
			for (int i = 0; i < 4; i = i + 3)           // 一四列都有 8 個
			{
				for (int j = 0; j < 4; j++)
				{
					if (kmap[j][i] != 0)
					{
						counter++;
					}
				}
			}
			if (counter == 8)
			{
				Kcase[6]++;
				for (int i = 0; i < 4; i = i + 3)
				{
					for (int j = 0; j < 4; j++)
					{
						count[j][i]++;
					}
				}
			}

			counter = 0;
			for (int i = 0; i < 4; i = i + 3)           // 一四行都有 8 個
			{
				for (int j = 0; j < 4; j++)
				{
					if (kmap[i][j] != 0)
					{
						counter++;
					}
				}
			}
			if (counter == 8)
			{
				Kcase[7]++;
				for (int i = 0; i < 4; i = i + 3)
				{
					for (int j = 0; j < 4; j++)
					{
						count[i][j]++;
					}
				}
			}
			//////////////////////////////////////////// 八個結束
			bool check = false;
			for (int r = 0; r < 5 || check; r++)
			{
				// 左上 右上 左下 右下
				if (kmap[0][0] != 0 && kmap[3][0] != 0 && kmap[0][3] != 0 && kmap[3][3] != 0 && Kcase[31] == 0)
				{
					// 按照走過次數的的大小來圈，確保優先順序 
					if (count[0][0] + count[3][0] + count[0][3] + count[3][3] <= r)      
					{
						// 因為有 don't care 存在，因次判斷是否為 1 且沒走過
						if ((count[0][0] == 0 && kmap[0][0] == 1) || (count[3][0] == 0 && kmap[3][0] == 1) || (count[0][3] == 0 && kmap[0][3] == 1) || (count[3][3] == 0 && kmap[3][3] == 1))
						{
							Kcase[31]++;
							count[0][0]++;
							count[3][0]++;
							count[0][3]++;
							count[3][3]++;
						}
					}
				}
				// 第一橫排
				if (kmap[0][0] != 0 && kmap[0][1] != 0 && kmap[0][2] != 0 && kmap[0][3] != 0 && Kcase[8] == 0)
				{
					if (count[0][0] + count[0][1] + count[0][2] + count[0][3] <= r)
					{
						if ((count[0][0] == 0 && kmap[0][0] == 1) || (count[0][1] == 0 && kmap[0][1] == 1) || (count[0][2] == 0 && kmap[0][2] == 1) || (count[0][3] == 0 && kmap[0][3] == 1))
						{
							Kcase[8]++;
							count[0][0]++;
							count[0][1]++;
							count[0][2]++;
							count[0][3]++;
						}
					}
				}
				// 第二橫排
				if (kmap[1][0] != 0 && kmap[1][1] != 0 && kmap[1][2] != 0 && kmap[1][3] != 0 && Kcase[9] == 0)
				{
					if (count[1][0] + count[1][1] + count[1][2] + count[1][3] <= r)
					{
						if ((count[1][0] == 0 && kmap[1][0] == 1) || (count[1][1] == 0 && kmap[1][1] == 1) || (count[1][2] == 0 && kmap[1][2] == 1) || (count[1][3] == 0 && kmap[1][3] == 1))
						{
							Kcase[9]++;
							count[1][0]++;
							count[1][1]++;
							count[1][2]++;
							count[1][3]++;
						}
					}
				}
				// 第三橫排
				if (kmap[2][0] != 0 && kmap[2][1] != 0 && kmap[2][2] != 0 && kmap[2][3] != 0 && Kcase[10] == 0)
				{
					if (count[2][0] + count[2][1] + count[2][2] + count[2][3] <= r)
					{
						if ((count[2][0] == 0 && kmap[2][0] == 1) || (count[2][1] == 0 && kmap[2][1] == 1) || (count[2][2] == 0 && kmap[2][2] == 1) || (count[2][3] == 0 && kmap[2][3] == 1))
						{
							Kcase[10]++;
							count[2][0]++;
							count[2][1]++;
							count[2][2]++;
							count[2][3]++;
						}
					}
				}
				// 第四橫排
				if (kmap[3][0] != 0 && kmap[3][1] != 0 && kmap[3][2] != 0 && kmap[3][3] != 0 && Kcase[11] == 0)
				{
					if (count[3][0] + count[3][1] + count[3][2] + count[3][3] <= r)
					{
						if ((count[3][0] == 0 && kmap[3][0] == 1) || (count[3][1] == 0 && kmap[3][1] == 1) || (count[3][2] == 0 && kmap[3][2] == 1) || (count[3][3] == 0 && kmap[3][3] == 1))
						{
							Kcase[11]++;
							count[3][0]++;
							count[3][1]++;
							count[3][2]++;
							count[3][3]++;
						}
					}
				}
				// 第一直排
				if (kmap[0][0] != 0 && kmap[1][0] != 0 && kmap[2][0] != 0 && kmap[3][0] != 0 && Kcase[12] == 0)
				{
					if (count[0][0] + count[1][0] + count[2][0] + count[3][0] <= r)
					{
						if ((count[0][0] == 0 && kmap[0][0] == 1) || (count[1][0] == 0 && kmap[1][0] == 1) || (count[2][0] == 0 && kmap[2][0] == 1) || (count[3][0] == 0 && kmap[3][0] == 1))
						{
							Kcase[12]++;
							count[0][0]++;
							count[1][0]++;
							count[2][0]++;
							count[3][0]++;
						}
					}
				}
				// 第二直排
				if (kmap[0][1] != 0 && kmap[1][1] != 0 && kmap[2][1] != 0 && kmap[3][1] != 0 && Kcase[13] == 0)
				{
					if (count[0][1] + count[1][1] + count[2][1] + count[3][1] <= r)
					{
						if ((count[0][1] == 0 && kmap[0][1] == 1) || (count[1][1] == 0 && kmap[1][1] == 1) || (count[2][1] == 0 && kmap[2][1] == 1) || (count[3][1] == 0 && kmap[3][1] == 1))
						{
							Kcase[13]++;
							count[0][1]++;
							count[1][1]++;
							count[2][1]++;
							count[3][1]++;
						}
					}
				}
				// 第三直排
				if (kmap[0][2] != 0 && kmap[1][2] != 0 && kmap[2][2] != 0 && kmap[3][2] != 0 && Kcase[14] == 0)
				{
					if (count[0][2] + count[1][2] + count[2][2] + count[3][2] <= r)
					{
						if ((count[0][2] == 0 && kmap[0][2] == 1) || (count[1][2] == 0 && kmap[1][2] == 1) || (count[2][2] == 0 && kmap[2][2] == 1) || (count[3][2] == 0 && kmap[3][2] == 1))
						{
							Kcase[14]++;
							count[0][2]++;
							count[1][2]++;
							count[2][2]++;
							count[3][2]++;
						}
					}
				}
				// 第四直排
				if (kmap[0][3] != 0 && kmap[1][3] != 0 && kmap[2][3] != 0 && kmap[3][3] != 0 && Kcase[15] == 0)
				{
					if (count[0][3] + count[1][3] + count[2][3] + count[3][3] <= r)
					{
						if ((count[0][3] == 0 && kmap[0][3] == 1) || (count[1][3] == 0 && kmap[1][3] == 1) || (count[2][3] == 0 && kmap[2][3] == 1) || (count[3][3] == 0 && kmap[3][3] == 1))
						{
							Kcase[15]++;
							count[0][3]++;
							count[1][3]++;
							count[2][3]++;
							count[3][3]++;
						}
					}
				}
				// 左上四格
				if (kmap[0][0] != 0 && kmap[1][0] != 0 && kmap[0][1] != 0 && kmap[1][1] != 0 && Kcase[16] == 0)
				{
					if (count[0][0] + count[1][0] + count[0][1] + count[1][1] <= r)
					{
						if ((count[0][0] == 0 && kmap[0][0] == 1) || (count[1][0] == 0 && kmap[1][0] == 1) || (count[0][1] == 0 && kmap[0][1] == 1) || (count[1][1] == 0 && kmap[1][1] == 1))
						{
							Kcase[16]++;
							count[0][0]++;
							count[1][0]++;
							count[0][1]++;
							count[1][1]++;
						}
					}
				}
				// 中上四格
				if (kmap[0][1] != 0 && kmap[0][2] != 0 && kmap[1][1] != 0 && kmap[1][2] != 0 && Kcase[17] == 0)
				{
					if (count[0][1] + count[0][2] + count[1][1] + count[1][2] <= r)
					{
						if ((count[0][1] == 0 && kmap[0][1] == 1) || (count[0][2] == 0 && kmap[0][2] == 1) || (count[1][1] == 0 && kmap[1][1] == 1) || (count[1][2] == 0 && kmap[1][2] == 1))
						{
							Kcase[17]++;
							count[0][1]++;
							count[0][2]++;
							count[1][1]++;
							count[1][2]++;
						}
					}
				}
				// 右上四格
				if (kmap[0][2] != 0 && kmap[0][3] != 0 && kmap[1][2] != 0 && kmap[1][3] != 0 && Kcase[18] == 0)
				{
					if (count[0][2] + count[0][3] + count[1][2] + count[1][3] <= 0)
					{
						if ((count[0][2] == 0 && kmap[0][2] == 1) || (count[0][3] == 0 && kmap[0][3] == 1) || (count[1][2] == 0 && kmap[1][2] == 1) || (count[1][3] == 0 && kmap[1][3] == 1))
						{
							Kcase[18]++;
							count[0][2]++;
							count[0][3]++;
							count[1][2]++;
							count[1][3]++;
						}
					}
				}
				// 中左四格
				if (kmap[1][0] != 0 && kmap[1][1] != 0 && kmap[2][0] != 0 && kmap[2][1] != 0 && Kcase[19] == 0)
				{
					if (count[1][0] + count[1][1] + count[2][0] + count[2][1] <= r)
					{
						if ((count[1][0] == 0 && kmap[1][0] == 1) || (count[1][1] == 0 && kmap[1][1] == 1) || (count[2][0] == 0 && kmap[2][0] == 1) || (count[2][1] == 0 && kmap[2][1] == 1))
						{
							Kcase[19]++;
							count[1][0]++;
							count[1][1]++;
							count[2][0]++;
							count[2][1]++;
						}
					}
				}
				// 中中四格
				if (kmap[1][1] != 0 && kmap[1][2] != 0 && kmap[2][1] != 0 && kmap[2][2] != 0 && Kcase[20] == 0)
				{
					if (count[1][1] + count[1][2] + count[2][1] + count[2][2] <= r)
					{
						if ((count[1][1] == 0 && kmap[1][1] == 1) || (count[1][2] == 0 && kmap[1][2] == 1) || (count[2][1] == 0 && kmap[2][1] == 1) || (count[2][2] == 0 && kmap[2][2] == 1))
						{
							Kcase[20]++;
							count[1][1]++;
							count[1][2]++;
							count[2][1]++;
							count[2][2]++;
						}
					}
				}
				// 中右四格
				if (kmap[1][2] != 0 && kmap[1][3] != 0 && kmap[2][2] != 0 && kmap[2][3] != 0 && Kcase[21] == 0)
				{
					if (count[1][2] + count[1][3] + count[2][2] + count[2][3] <= r)
					{
						if ((count[1][2] == 0 && kmap[1][2] == 1) || (count[1][3] == 0 && kmap[1][3] == 1) || (count[2][2] == 0 && kmap[2][2] == 1) || (count[2][3] == 0 && kmap[2][3] == 1))
						{
							Kcase[21]++;
							count[1][2]++;
							count[1][3]++;
							count[2][2]++;
							count[2][3]++;
						}
					}
				}
				// 下左四格
				if (kmap[2][0] != 0 && kmap[2][1] != 0 && kmap[3][0] != 0 && kmap[3][1] != 0 && Kcase[22] == 0)
				{
					if (count[2][0] + count[2][1] + count[3][0] + count[3][1] <= r)
					{
						if ((count[2][0] == 0 && kmap[2][0] == 1) || (count[2][1] == 0 && kmap[2][1] == 1) || (count[3][0] == 0 && kmap[3][0] == 1) || (count[3][1] == 0 && kmap[3][1] == 1))
						{
							Kcase[22]++;
							count[2][0]++;
							count[2][1]++;
							count[3][0]++;
							count[3][1]++;
						}
					}
				}
				// 下中四格
				if (kmap[2][1] != 0 && kmap[2][2] != 0 && kmap[3][1] != 0 && kmap[3][2] != 0 && Kcase[23] == 0)
				{
					if (count[2][1] + count[2][2] + count[3][1] + count[3][2] <= r)
					{
						if ((count[2][1] == 0 && kmap[2][1] == 1) || (count[2][2] == 0 && kmap[2][2] == 1) || (count[3][1] == 0 && kmap[3][1] == 1) || (count[3][2] == 0 && kmap[3][2] == 1))
						{
							Kcase[23]++;
							count[2][1]++;
							count[2][2]++;
							count[3][1]++;
							count[3][2]++;
						}
					}
				}
				// 下右四格
				if (kmap[2][2] != 0 && kmap[2][3] != 0 && kmap[3][2] != 0 && kmap[3][3] != 0 && Kcase[24] == 0)
				{
					if (count[2][2] + count[2][3] + count[3][2] + count[3][3] <= r)
					{
						if ((count[2][2] == 0 && kmap[2][2] == 1) || (count[2][3] == 0 && kmap[2][3] == 1) || (count[3][2] == 0 && kmap[3][2] == 1) || (count[3][3] == 0 && kmap[3][3] == 1))
						{
							Kcase[24]++;
							count[2][2]++;
							count[2][3]++;
							count[3][2]++;
							count[3][3]++;
						}
					}
				}
				// 左上兩格 左下兩格 ( 橫 )
				if (kmap[0][0] != 0 && kmap[0][1] != 0 && kmap[3][0] != 0 && kmap[3][1] != 0 && Kcase[25] == 0)
				{
					if (count[0][0] + count[0][1] + count[3][0] + count[3][1] <= r)
					{
						if ((count[0][0] == 0 && kmap[0][0] == 1) || (count[0][1] == 0 && kmap[0][1] == 1) || (count[3][0] == 0 && kmap[3][0] == 1) || (count[3][1] == 0 && kmap[3][1] == 1))
						{
							Kcase[25]++;
							count[0][0]++;
							count[0][1]++;
							count[3][0]++;
							count[3][1]++;
						}
					}
				}
				// 中上兩格 中下兩格 ( 橫 )
				if (kmap[0][1] != 0 && kmap[0][2] != 0 && kmap[3][1] != 0 && kmap[3][2] != 0 && Kcase[26] == 0)
				{
					if (count[0][1] + count[0][2] + count[3][1] + count[3][2] <= r)
					{
						if ((count[0][1] == 0 && kmap[0][1] == 1) || (count[0][2] == 0 && kmap[0][2] == 1) || (count[3][1] == 0 && kmap[3][1] == 1) || (count[3][2] == 0 && kmap[3][2] == 1))
						{
							Kcase[26]++;
							count[0][1]++;
							count[0][2]++;
							count[3][1]++;
							count[3][2]++;
						}
					}
				}
				// 右上兩格 右下兩格 ( 橫 )
				if (kmap[0][2] != 0 && kmap[0][3] != 0 && kmap[3][2] != 0 && kmap[3][3] != 0 && Kcase[27] == 0)
				{
					if (count[0][2] + count[0][3] + count[3][2] + count[3][3] <= r)
					{
						if ((count[0][2] == 0 && kmap[0][2] == 1) || (count[0][3] == 0 && kmap[0][3] == 1) || (count[3][2] == 0 && kmap[3][2] == 1) || (count[3][3] == 0 && kmap[3][3] == 1))
						{
							Kcase[27]++;
							count[0][2]++;
							count[0][3]++;
							count[3][2]++;
							count[3][3]++;
						}
					}
				}
				// 左上兩格 右上兩格 ( 直 )
				if (kmap[0][0] != 0 && kmap[1][0] != 0 && kmap[0][3] != 0 && kmap[1][3] != 0 && Kcase[28] == 0)
				{
					if (count[0][0] + count[1][0] + count[0][3] + count[1][3] <= r)
					{
						if ((count[0][0] == 0 && kmap[0][0] == 1) || (count[1][0] == 0 && kmap[1][0] == 1) || (count[0][3] == 0 && kmap[0][3] == 1) || (count[1][3] == 0 && kmap[1][3] == 1))
						{
							Kcase[28]++;
							count[0][0]++;
							count[1][0]++;
							count[0][3]++;
							count[1][3]++;
						}
					}
				}
				// 左中兩格 右中兩格 ( 直 )
				if (kmap[1][0] != 0 && kmap[2][0] != 0 && kmap[1][3] != 0 && kmap[2][3] != 0 && Kcase[29] == 0)
				{
					if (count[1][0] + count[2][0] + count[1][3] + count[2][3] <= r)
					{
						if ((count[1][0] == 0 && kmap[1][0] == 1) || (count[2][0] == 0 && kmap[2][0] == 1) || (count[1][3] == 0 && kmap[1][3] == 1) || (count[2][3] == 0 && kmap[2][3] == 1))
						{
							Kcase[29]++;
							count[1][0]++;
							count[2][0]++;
							count[1][3]++;
							count[2][3]++;
						}
					}
				}
				// 左下兩格 右下兩格 ( 直 )
				if (kmap[2][0] != 0 && kmap[3][0] != 0 && kmap[2][3] != 0 && kmap[3][3] != 0 && Kcase[30] == 0)
				{
					if (count[2][0] + count[3][0] + count[2][3] + count[3][3] <= r)
					{
						if ((count[2][0] == 0 && kmap[2][0] == 1) || (count[3][0] == 0 && kmap[3][0] == 1) || (count[2][3] == 0 && kmap[2][3] == 1) || (count[3][3] == 0 && kmap[3][3] == 1))
						{
							Kcase[30]++;
							count[2][0]++;
							count[3][0]++;
							count[2][3]++;
							count[3][3]++;
						}
					}
				}
				check = false;
				if (r == 4)        // 因為周遭相加有可能超過 4 但還有沒走過的，因此最後一次則是檢查這種 case
				{
					check = true;
					r = 20;
				}
			}
			////////////////////////////////////////////////////////// 四個結束
			
			bool right = false;                                     // 確定有兩個
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)                         // 以此格為基準，輪流往上左下右找哪裡有可以圈的
				{                                                   // 四個八個前面已找完，因此這裡只會有兩個的存在
					if (kmap[i][j] == 1 && count[i][j] == 0)
					{
						if (i != 0 && kmap[i - 1][j] != 0)          // 上面
						{
							right = true;
							count[i - 1][j]++;
							two.push_back(i - 1);
							two.push_back(j);
						}
						else if (j != 0 && kmap[i][j - 1] != 0)     // 左邊
						{
							right = true;
							count[i][j - 1]++;
							two.push_back(i);
							two.push_back(j - 1);
						}
						else if (i + 1 < 4 && kmap[i + 1][j] != 0)  // 下面
						{
							right = true;
							count[i + 1][j]++;
							two.push_back(i + 1);
							two.push_back(j);
						}
						else if (j + 1 < 4 && kmap[i][j + 1] != 0)
						{
							right = true;
							count[i][j + 1]++;
							two.push_back(i);
							two.push_back(j + 1);
						}
						if (right)
						{
							count[i][j]++;
							two.push_back(i);
							two.push_back(j);
						}
					}
				}
			}
			//////////////////////////////////////// 兩個結束
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)       // 單獨一個存在的
				{
					if (kmap[i][j] == 1 && count[i][j] == 0)
					{
						one.push_back(i);
						one.push_back(j);
					}
				}
			}
			//////////////////////////////////////// 一個結束
		}
		
		//////////////////////////////////////////// 整理結果
		cout << "///////////////////" << endl;
		cout << "#" << times++ << endl;
		if (all)
			cout << sixteen[0] << endl;
		for (int x = 0; x < 32; x++)
		{
			if (Kcase[x])
			{
				if (x < 8)
				{
					cout << eight[x] << endl;
				}
				if (x > 7)
					cout << four[x - 8] << endl;
			}
			Kcase[x] = 0;                          // 初始化
		}
		for (int t = 0; t < two.size(); t++)
		{
			int p = two[t++];
			int q = two[t++];
			string pq = TWOandONE[p][q];
			int r = two[t++];
			int s = two[t];
			string rs = TWOandONE[r][s];
			for (int d = 0; d < 7; d = d + 2)       // 比較兩個的編號 ( KMAP 上的外框數字 ) 不一樣則代表可以消去
			{
				if (pq[d] == rs[d])
					cout << pq[d] << " ";
				else
					cout << "2 ";
			}
			cout << endl;
		}
		for (int u = 0; u < one.size(); u++)
		{
			int f = one[u++];
			int s = one[u];
			string fs = TWOandONE[f][s];
			cout << fs << endl;
		}
		for (int i = 0; i < 4; i++)                // 初始化
		{
			for (int j = 0; j < 4; j++)
			{
				count[i][j] = 0;
			}
		}
		for (int i = 0; i < two.size(); i++)
		{
			two.pop_back();
		}
		for (int i = 0; i < one.size(); i++)
		{
			one.pop_back();
		}
	}
	system("pause");
	return 0;
}