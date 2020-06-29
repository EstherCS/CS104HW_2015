#include <iostream>
using namespace std;

#define MAX_POINT  10               // �`�@��10���I

bool road[10][10] = { 0 };          // �s������Ӹ`�I
bool PassPoint[10];                 // �g�L���I
int  ExportLine[11];                // �]�X�Ӫ����u
int  count = 0;                     // ���u���ƥ�

void Hamilton(int n);               // ���� Hamilton

int main()
{
	// �s������Ӹ`�I�� true
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

	Hamilton(1);                                             // �I�s Hamilton

	cout << "�`�@��" << ::count << "�����u" << endl << endl; // �L�X���u�ƥ�

	system("pause");

	return 0;
}

void Hamilton(int j)                                         // Hamilton function
{
	int x, y;
	if (j == MAX_POINT)                                      // �w���L 10 ���I
	{
		x = ExportLine[MAX_POINT - 1];                       // x �]�� �̫�@�I ExportLine[10-1] = ExportLine[9]
		y = ExportLine[0];                                   // y = ExportLine[0] = 0
		if (road[x][y] == true)                              // �Y�̫�@�I�P�Ĥ@�I�۳s �h�L�X���� 
		{
			for (int i = 0; i <= 10; i++)
			{
				cout << ExportLine[i] << ((i == 10) ? "" : " �� ");    // ����u�L�X��
			}
			::count++;                                                 // ���u�ƥ� +1
			cout << endl << endl;
		}
		return;
	}
	else                                                   // �|������
	{
		x = ExportLine[j - 1];                             // �] x ���e�@�I, x = ExportLine[0] = 0 

		for (int y = 1; y < MAX_POINT; y++)
		{
			if (road[x][y] && !PassPoint[y])               // "xy �O�s�������I" �M "y �����L"
			{
				ExportLine[j] = y;                         // �] ExportLine[n] ���Ȭ� y ( ExportLine[1] = 1 )
				PassPoint[y] = true;                       // �] PassPoint[y] �� true �N��]�L�F ( PassPoint[1] = true )

				Hamilton(j + 1);                           // �A���I�s Hamilton function ( ���j���U�@�I )
				PassPoint[y] = false;                      // �] PassPoint[y] �� false ( PassPoint[1] = false )
			}
		}
	}
}
/*
�~�w�s�w�s�w�s�w�s�w�s�w�s�w�s�w�s�w�s�w��
�x0 �x 1�x 2�x 3�x 4�x 5�x 6�x 7�x 8�x 9�x                          ExportLine ���槹����
���s�r�s�r�s�r�s�r�s�r�s�r�s�r�s�r�s�r�s��                          ���U�ӥh���̫�@�檺�Ʀr��_���^�_�I ( 9 -> 0 )
  �x  �x  �x  �x  �x  �x  �x  �x  �x  �x                            �Y����N�f���^�h�@�� ( 8 )
  �x  �x  �x  �x  �x  �x  �x  �x  �x�~�r�s�w�s�w�s�w��              �����즹��D�_�I���������u��
  �x  �x  �x  �x  �x  �x  �x  �x    �x3 �x 4�x 5�x 8�x              �A�f���^�e�@�� ( 7 )
  �x  �x  �x  �x  �x  �x  �x        ���s�r�s�r�s�r�s��              �M��౵�^�_�I�����u ( 7 -> ? -> ? - > 0 )
  �x  �x  �x  �x  �x  �x              �x  �x  �x  �x                �̦�����
  �x  �x  �x  �x  �x                  �x  �x  �x
  �x  �x  �x  �x                      �x  �x
  �x  �x  �x                          �x
  �x  �x                            �~�r�s�w�s�w��
  �x {0, 2, 6, 7}                   �x2 �x 8�x 4�x
�~�r�s�w�s�w�s�w��                  ���s�r�s�r�s��
�x1 �x 4�x 5�x 6�x                    �x  �x  �x
���s�r�s�r�s�r�s��                    �x  �x
  �x  �x  �x  �x                      �x
  �x  �x  �x                        �~�r�s�w�s�w��
  �x  �x                            �x1 �x7 �x 8�x
  �x                                ���s�r�s�r�s��
  �x
�~�r�s�w�s�w��
�x2 �x 6�x 7�x
���s�r�s�r�s��
  �x  �x  �x
  �x  �x
  �x
�~�r�s�w�s�w��
�x3 �x7 �x 8�x
���s�r�s�r�s��
  �x  �x  �x
  �x  �x
  �x

*/