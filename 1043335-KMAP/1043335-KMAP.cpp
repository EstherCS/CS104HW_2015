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
	int kmap[4][4] = {};        // �s KMAP ����J
	int count[4][4] = {};       // �s���Q��F�X��
	int Kcase[32] = {};         // �P�_�K�ӥ|�Ӫ��O�_�s�b
	int num;                    // ���X�� KMAP
	bool all = false;
	cin >> num;
	while (num--)
	{
		vector<int> two;         // �s���Ӭ۾F��
		vector<int> one;         // �s���W�s�b��
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				cin >> kmap[i][j];
		}

		int counter = 0;
		for (int i = 0; i < 4; i++)               // �Q����������O 1     
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
		//////////////////////////////////////////// �Q���ӵ���
		if (!all)
		{
			counter = 0;
			for (int i = 0; i < 2; i++)           // �@�G�泣�� 8 ��
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
			for (int i = 1; i < 3; i++)           // �G�T�泣�� 8 ��
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
			for (int i = 2; i < 4; i++)           // �T�|�泣�� 8 ��
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
			for (int i = 0; i < 2; i++)           // �@�G�C���� 8 ��
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
			for (int i = 1; i < 3; i++)           // �G�T�C���� 8 ��
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
			for (int i = 2; i < 4; i++)           // �T�|�C���� 8 ��
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
			for (int i = 0; i < 4; i = i + 3)           // �@�|�C���� 8 ��
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
			for (int i = 0; i < 4; i = i + 3)           // �@�|�泣�� 8 ��
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
			//////////////////////////////////////////// �K�ӵ���
			bool check = false;
			for (int r = 0; r < 5 || check; r++)
			{
				// ���W �k�W ���U �k�U
				if (kmap[0][0] != 0 && kmap[3][0] != 0 && kmap[0][3] != 0 && kmap[3][3] != 0 && Kcase[31] == 0)
				{
					// ���Ө��L���ƪ����j�p�Ӱ�A�T�O�u������ 
					if (count[0][0] + count[3][0] + count[0][3] + count[3][3] <= r)      
					{
						// �]���� don't care �s�b�A�]���P�_�O�_�� 1 �B�S���L
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
				// �Ĥ@���
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
				// �ĤG���
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
				// �ĤT���
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
				// �ĥ|���
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
				// �Ĥ@����
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
				// �ĤG����
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
				// �ĤT����
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
				// �ĥ|����
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
				// ���W�|��
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
				// ���W�|��
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
				// �k�W�|��
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
				// �����|��
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
				// �����|��
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
				// ���k�|��
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
				// �U���|��
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
				// �U���|��
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
				// �U�k�|��
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
				// ���W��� ���U��� ( �� )
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
				// ���W��� ���U��� ( �� )
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
				// �k�W��� �k�U��� ( �� )
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
				// ���W��� �k�W��� ( �� )
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
				// ������� �k����� ( �� )
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
				// ���U��� �k�U��� ( �� )
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
				if (r == 4)        // �]���P�D�ۥ[���i��W�L 4 ���٦��S���L���A�]���̫�@���h�O�ˬd�o�� case
				{
					check = true;
					r = 20;
				}
			}
			////////////////////////////////////////////////////////// �|�ӵ���
			
			bool right = false;                                     // �T�w�����
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)                         // �H���欰��ǡA���y���W���U�k����̦��i�H�骺
				{                                                   // �|�ӤK�ӫe���w�䧹�A�]���o�̥u�|����Ӫ��s�b
					if (kmap[i][j] == 1 && count[i][j] == 0)
					{
						if (i != 0 && kmap[i - 1][j] != 0)          // �W��
						{
							right = true;
							count[i - 1][j]++;
							two.push_back(i - 1);
							two.push_back(j);
						}
						else if (j != 0 && kmap[i][j - 1] != 0)     // ����
						{
							right = true;
							count[i][j - 1]++;
							two.push_back(i);
							two.push_back(j - 1);
						}
						else if (i + 1 < 4 && kmap[i + 1][j] != 0)  // �U��
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
			//////////////////////////////////////// ��ӵ���
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)       // ��W�@�Ӧs�b��
				{
					if (kmap[i][j] == 1 && count[i][j] == 0)
					{
						one.push_back(i);
						one.push_back(j);
					}
				}
			}
			//////////////////////////////////////// �@�ӵ���
		}
		
		//////////////////////////////////////////// ��z���G
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
			Kcase[x] = 0;                          // ��l��
		}
		for (int t = 0; t < two.size(); t++)
		{
			int p = two[t++];
			int q = two[t++];
			string pq = TWOandONE[p][q];
			int r = two[t++];
			int s = two[t];
			string rs = TWOandONE[r][s];
			for (int d = 0; d < 7; d = d + 2)       // �����Ӫ��s�� ( KMAP �W���~�ؼƦr ) ���@�˫h�N��i�H���h
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
		for (int i = 0; i < 4; i++)                // ��l��
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