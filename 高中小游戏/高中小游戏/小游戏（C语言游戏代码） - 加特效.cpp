/*										           C����С��Ϸ����  		    		                 */
#pragma warning(disable:4996)
#include "time.h"
#include<string.h>
#include "stdio.h"//�����ҵ�������2004��12��19��
#include "conio.h"//�����exit���� 
#include "head/system1.h"//������ϵͳ 
#include "head/lyq1.h"//��������ճ��� 
#include "windows.h"//����Sleep()���� 
#include "stdlib.h"//����system()���� 
#define pr printf("��ϲ����̽���Թ����밴��������룺\n")
#define NUM 17//����������ѭ��
#define NUM1 17//����������ѭ��
#define LYQ FILE//����ϲ�� 
#define RW	'6'//���������ɫ
#define RW1 '8'//���������ɫ
#define S system1();//����system1.h�����system1()������ 
#define Visit(a) Sleep(a)//�����ٶ� ����Խ�������ٶ�Խ�� 
#define LIFE1 3//Ӣ������1������ֵ 
#define LIFE2 3//Ӣ������2������ֵ 
int djs = 0, life1 = LIFE1, life2 = LIFE2, map_end = 0, map2 = 0, cf = 1, x, y, x11, y11, if1 = 0, if2 = 0, v = 0, life_sign1 = 1, life_sign2 = 1;//���Ƹտ�ʼʱ�ĵ���ʱ������ֵ����ͼ������־��������һ��ͼ�ı�־�� 
char c[NUM][NUM1], o, t;//ȫ�ֶ�ά����
int move_yz(int* m, int* n, int* m1, int* n1)//����������������
{
	static int a = 1, b = 1; //�ø�������������*������ѭ�� 
	if (c[*m][*n + 1] != '#' && a)//��һ��*һֱ������ 
	{
		if (c[*m][*n + 1] == RW)//�ж�*�����ұ��Ƿ��ǽ�ɫ1
		{
			if (life1)life1 -= 1; if1 = 1;//������*�����ý�ɫʱlife1������ֵ��1�������0�Ͳ����ˣ�if1Ϊ*ײ����һ����ɫʱ�ı�־��Ϊ������ж���ǰ�� 
		}
		if (c[*m][*n + 1] == RW1)//�ж�*�����ұ��Ƿ��ǽ�ɫ2
		{
			if (life2)life2 -= 1; if2 = 1;//������*�����ý�ɫʱlife2������ֵ��1�������0�Ͳ����ˣ�if2Ϊ*ײ���ڶ�����ɫʱ�ı�־��Ϊ������ж���ǰ�� 
		}
		if (life1 > 0 && if1)//����ɫ1�������������Ӧλ�ý��� 
		{
			if (map2 == 1) //���map2��ֵ��2��˵���Ѿ����뵽�ڶ�����ͼ�� ������ɫ1������Ӧ��λ�ñ任 
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else//���map2��ֵ����2��˵�����ǵ�һ����ͼ�� ����ɫ1������Ӧ��λ�ñ任 
			{
				t = c[x][y];
				c[x][y] = c[5][3];
				c[5][3] = t;
			}
			if1 = 0;//��if1��ֵΪ0�������´�ѭ������ʱ��Ͳ���ִ�����ˣ�ֻ�е�*���ұ��ǽ�ɫ1ʱ�Ż���뵽������ 
			putchar('\a');//ײ���ý�ɫ��һ�£�Ч���õ㡣 
		}
		if (life2 > 0 && if2)//����ɫ2���������Ƶ���Ӧλ��
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[5][3];
				c[5][3] = t;
			}
			if2 = 0;//��if2��ֵΪ0�������´�����ѭ������ʱ��Ͳ���ִ�����ˣ�ֻ�е�*���ұ��ǽ�ɫ2ʱ�Ż���뵽������
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)//����ɫ1������ֵΪ0ʱ����������life_sign1��Ϊ������һ��if���ִֻ��һ�Σ����ú����������͵�If����ִ�С� 
		{
			if (c[1][1] == RW1)//���c[1][1]��λ���ǽ�ɫ2���Ͳ����������ɫ2�������ý�ɫ2��c[1][2]����λ��������һλ�����ý�ɫ1��c[1][1]����λ�� 
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;//ִ���������if���������������ֻ��ִ��һ�� 
			putchar('\a');
		}
		if (life2 == 0 && life_sign2)//����ɫ2������ֵΪ0ʱ����������life_sign2��Ϊ������һ��if���ִֻ��һ�Σ����ú����������͵�If����ִ�С� 
		{
			if (c[15][15] == RW)//���c[15][15]��λ���ǽ�ɫ1���Ͳ����������ɫ1�������ý�ɫ1��c[15][15]����λ��������һλ�����ý�ɫ2��c[15][15]����λ�� 
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
			putchar('\a');
		}
		t = c[*m][*n + 1];//*��λ�������ƶ� 
		c[*m][*n + 1] = c[*m][*n];
		c[*m][*n] = t;
		*n += 1;
	}
	else //��һ��*һֱ������ 
	{
		if (c[*m][*n - 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m][*n - 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//�����������Ƶ���Ӧλ��	
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[5][3];
				c[5][3] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//����������������������ƣ��ҾͲ�һһ˵���� 
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[5][3];
				c[5][3] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
			putchar('\a');
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
			putchar('\a');
		}
		t = c[*m][*n - 1];
		c[*m][*n - 1] = c[*m][*n];
		c[*m][*n] = t;
		*n -= 1;
	}

	if (c[*m1][*n1 - 1] != '#' && b)//�ڶ���*һֱ������
	{
		if (c[*m1][*n1 - 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m1][*n1 - 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//�����������Ƶ���Ӧλ��
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[11][13];
				c[11][13] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//�����������Ƶ���Ӧλ��
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[11][13];
				c[11][13] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
			putchar('\a');
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
			putchar('\a');
		}
		t = c[*m1][*n1 - 1];
		c[*m1][*n1 - 1] = c[*m1][*n1];
		c[*m1][*n1] = t;
		*n1 -= 1;
	}
	else //�ڶ���*һֱ������
	{
		if (c[*m1][*n1 + 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m1][*n1 + 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//�����������Ƶ���Ӧλ��	
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[11][13];
				c[11][13] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//�����������Ƶ���Ӧλ��
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[11][13];
				c[11][13] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			if2 = 0;
			life_sign2 = 0;
		}
		t = c[*m1][*n1 + 1];
		c[*m1][*n1 + 1] = c[*m1][*n1];
		c[*m1][*n1] = t;
		*n1 += 1;//���������Ϊ*n1++;�ͳ����� 
	}
	if (c[*m][*n + 1] == '#')a = 0;
	if (c[*m][*n - 1] == '#')a = 1;
	if (c[*m1][*n1 + 1] == '#')b = 1;
	if (c[*m1][*n1 - 1] == '#')b = 0;
	return 0;
}
int move_yz1(int* m, int* n, int* m1, int* n1)//���������������ƣ������Ϊ�˺���ĵ�ͼ2��* �������ƶ� 
{
	static int a = 1, b = 1;
	if (c[*m][*n + 1] != '#' && a)//��һ��*һֱ������ 
	{
		if (c[*m][*n + 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m][*n + 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//�����������Ƶ���Ӧλ��
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[5][3];
				c[5][3] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//�����������Ƶ���Ӧλ�� 
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[5][3];
				c[5][3] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
			putchar('\a');
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
			putchar('\a');
		}
		t = c[*m][*n + 1];
		c[*m][*n + 1] = c[*m][*n];
		c[*m][*n] = t;
		*n += 1;
	}
	else//��һ��*һֱ������ 
	{
		if (c[*m][*n - 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m][*n - 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//�����������Ƶ���Ӧλ�� 
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[5][3];
				c[5][3] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//�����������Ƶ���Ӧλ�� 
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[5][3];
				c[5][3] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
			putchar('\a');
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
			putchar('\a');
		}
		t = c[*m][*n - 1];
		c[*m][*n - 1] = c[*m][*n];
		c[*m][*n] = t;
		*n -= 1;
	}

	if (c[*m1][*n1 - 1] != '#' && b)//�ڶ���*һֱ������
	{
		if (c[*m1][*n1 - 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m1][*n1 - 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//�����������Ƶ���Ӧλ�� 
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[11][13];
				c[11][13] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//�����������Ƶ���Ӧλ�� 
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[11][13];
				c[11][13] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
			putchar('\a');
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
			putchar('\a');
		}
		t = c[*m1][*n1 - 1];
		c[*m1][*n1 - 1] = c[*m1][*n1];
		c[*m1][*n1] = t;
		*n1 -= 1;
	}
	else//�ڶ���*һֱ������
	{
		if (c[*m1][*n1 + 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m1][*n1 + 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//�����������Ƶ���Ӧλ�� 
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[11][13];
				c[11][13] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//�����������Ƶ���Ӧλ��	
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[11][13];
				c[11][13] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
		}
		t = c[*m1][*n1 + 1];
		c[*m1][*n1 + 1] = c[*m1][*n1];
		c[*m1][*n1] = t;
		*n1 += 1;
	}
	if (c[*m][*n + 1] == '#')a = 0;
	if (c[*m][*n - 1] == '#')a = 1;
	if (c[*m1][*n1 + 1] == '#')b = 1;
	if (c[*m1][*n1 - 1] == '#')b = 0;
	return 0;
}
int move_yz2(int* m, int* n, int* m1, int* n1)//���������������ƣ������Ϊ�˺���ĵ�ͼ2��* �������ƶ� 
{
	static int a = 1, b = 1;
	if (c[*m][*n + 1] != '#' && a)//��һ��*һֱ������ 
	{
		if (c[*m][*n + 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m][*n + 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//�����������Ƶ���Ӧλ��
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[5][3];
				c[5][3] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//�����������Ƶ���Ӧλ�� 
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[5][3];
				c[5][3] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
			putchar('\a');
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
			putchar('\a');
		}
		t = c[*m][*n + 1];
		c[*m][*n + 1] = c[*m][*n];
		c[*m][*n] = t;
		*n += 1;
	}
	else//��һ��*һֱ������ 
	{
		if (c[*m][*n - 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m][*n - 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//�����������Ƶ���Ӧλ�� 
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[5][3];
				c[5][3] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//�����������Ƶ���Ӧλ�� 
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[5][3];
				c[5][3] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
			putchar('\a');
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
			putchar('\a');
		}
		t = c[*m][*n - 1];
		c[*m][*n - 1] = c[*m][*n];
		c[*m][*n] = t;
		*n -= 1;
	}

	if (c[*m1][*n1 - 1] != '#' && b)//�ڶ���*һֱ������
	{
		if (c[*m1][*n1 - 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m1][*n1 - 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//�����������Ƶ���Ӧλ�� 
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[11][13];
				c[11][13] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//�����������Ƶ���Ӧλ�� 
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[11][13];
				c[11][13] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
			putchar('\a');
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
			putchar('\a');
		}
		t = c[*m1][*n1 - 1];
		c[*m1][*n1 - 1] = c[*m1][*n1];
		c[*m1][*n1] = t;
		*n1 -= 1;
	}
	else//�ڶ���*һֱ������
	{
		if (c[*m1][*n1 + 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m1][*n1 + 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//�����������Ƶ���Ӧλ�� 
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[11][13];
				c[11][13] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//�����������Ƶ���Ӧλ��	
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[11][13];
				c[11][13] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
		}
		t = c[*m1][*n1 + 1];
		c[*m1][*n1 + 1] = c[*m1][*n1];
		c[*m1][*n1] = t;
		*n1 += 1;
	}
	if (c[*m][*n + 1] == '#')a = 0;
	if (c[*m][*n - 1] == '#')a = 1;
	if (c[*m1][*n1 + 1] == '#')b = 1;
	if (c[*m1][*n1 - 1] == '#')b = 0;
	return 0;
}
int move_yz3(int* m, int* n, int* m1, int* n1)//���������������ƣ������Ϊ�˺���ĵ�ͼ2��* �������ƶ� 
{
	static int a = 1, b = 1;
	if (c[*m][*n + 1] != '#' && a)//��һ��*һֱ������ 
	{
		if (c[*m][*n + 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m][*n + 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//�����������Ƶ���Ӧλ��
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[5][3];
				c[5][3] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//�����������Ƶ���Ӧλ�� 
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[5][3];
				c[5][3] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
			putchar('\a');
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
			putchar('\a');
		}
		t = c[*m][*n + 1];
		c[*m][*n + 1] = c[*m][*n];
		c[*m][*n] = t;
		*n += 1;
	}
	else//��һ��*һֱ������ 
	{
		if (c[*m][*n - 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m][*n - 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//�����������Ƶ���Ӧλ�� 
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[5][3];
				c[5][3] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//�����������Ƶ���Ӧλ�� 
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[5][3];
				c[5][3] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
			putchar('\a');
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
			putchar('\a');
		}
		t = c[*m][*n - 1];
		c[*m][*n - 1] = c[*m][*n];
		c[*m][*n] = t;
		*n -= 1;
	}

	if (c[*m1][*n1 - 1] != '#' && b)//�ڶ���*һֱ������
	{
		if (c[*m1][*n1 - 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m1][*n1 - 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//�����������Ƶ���Ӧλ�� 
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[11][13];
				c[11][13] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//�����������Ƶ���Ӧλ�� 
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[11][13];
				c[11][13] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
			putchar('\a');
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
			putchar('\a');
		}
		t = c[*m1][*n1 - 1];
		c[*m1][*n1 - 1] = c[*m1][*n1];
		c[*m1][*n1] = t;
		*n1 -= 1;
	}
	else//�ڶ���*һֱ������
	{
		if (c[*m1][*n1 + 1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*m1][*n1 + 1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//�����������Ƶ���Ӧλ�� 
		{
			if (map2 == 1)
			{
				t = c[x][y];
				c[x][y] = c[3][11];
				c[3][11] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[11][13];
				c[11][13] = t;
			}
			if1 = 0;
			putchar('\a');
		}
		if (life2 > 0 && if2)//�����������Ƶ���Ӧλ��	
		{
			if (map2 == 1)
			{
				t = c[x11][y11];
				c[x11][y11] = c[13][5];
				c[13][5] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[11][13];
				c[11][13] = t;
			}
			if2 = 0;
			putchar('\a');
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
		}
		t = c[*m1][*n1 + 1];
		c[*m1][*n1 + 1] = c[*m1][*n1];
		c[*m1][*n1] = t;
		*n1 += 1;
	}
	if (c[*m][*n + 1] == '#')a = 0;
	if (c[*m][*n - 1] == '#')a = 1;
	if (c[*m1][*n1 + 1] == '#')b = 1;
	if (c[*m1][*n1 - 1] == '#')b = 0;
	return 0;
}
int move_sx(int* mm, int* nn, int* mm1, int* nn1)//����������������
{
	static int a1 = 1, b1 = 1;
	if (c[*mm - 1][*nn] != '#' && a1)//��һ��*һֱ������
	{
		if (c[*mm - 1][*nn] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*mm - 1][*nn] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//�����������Ƶ���Ӧλ��	 
		{
			if (x < 8)//���Ͻ�λ�� 
			{
				t = c[x][y];
				c[x][y] = c[5][3];
				c[5][3] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[12][3];
				c[12][3] = t;
			}
			if1 = 0;
		}
		if (life2 > 0 && if2)//�����������Ƶ���Ӧλ�� 
		{
			if (x11 < 8)//���Ͻ�λ�� 
			{
				t = c[x11][y11];
				c[x11][y11] = c[5][3];
				c[5][3] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[12][3];
				c[12][3] = t;
			}
			if2 = 0;
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
		}
		t = c[*mm - 1][*nn];
		c[*mm - 1][*nn] = c[*mm][*nn];
		c[*mm][*nn] = t;
		*mm -= 1;
	}
	else //��һ��*һֱ������
	{
		if (c[*mm + 1][*nn] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*mm + 1][*nn] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//�����������Ƶ���Ӧλ�� 
		{
			if (x < 8)//���Ͻ�λ�� 
			{
				t = c[x][y];
				c[x][y] = c[5][3];
				c[5][3] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[12][3];
				c[12][3] = t;
			}
			if1 = 0;
		}
		if (life2 > 0 && if2)//�����������Ƶ���Ӧλ�� 
		{
			if (x11 < 8)//���Ͻ�λ�� 
			{
				t = c[x11][y11];
				c[x11][y11] = c[5][3];
				c[5][3] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[12][3];
				c[12][3] = t;
			}
			if2 = 0;
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
		}
		t = c[*mm + 1][*nn];
		c[*mm + 1][*nn] = c[*mm][*nn];
		c[*mm][*nn] = t;
		*mm += 1;
	}

	if (c[*mm1 + 1][*nn1] != '#' && b1)//�ڶ���*һֱ������
	{
		if (c[*mm1 + 1][*nn1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*mm1 + 1][*nn1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//�����������Ƶ���Ӧλ��	4 13 12 3
		{
			if (x < 8)
			{
				t = c[x][y];
				c[x][y] = c[4][13];
				c[4][13] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[11][13];
				c[11][13] = t;
			}
			if1 = 0;
		}
		if (life2 > 0 && if2)//�����������Ƶ���Ӧλ�� 
		{
			if (x11 < 8)//���Ͻ�λ�� 
			{
				t = c[x11][y11];
				c[x11][y11] = c[5][3];
				c[5][3] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[12][3];
				c[12][3] = t;
			}
			if2 = 0;
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
		}
		t = c[*mm1 + 1][*nn1];
		c[*mm1 + 1][*nn1] = c[*mm1][*nn1];
		c[*mm1][*nn1] = t;
		*mm1 += 1;
	}
	else //�ڶ���*һֱ������
	{
		if (c[*mm1 - 1][*nn1] == RW)
		{
			if (life1)life1 -= 1; if1 = 1;
		}
		if (c[*mm1 - 1][*nn1] == RW1)
		{
			if (life2)life2 -= 1; if2 = 1;
		}
		if (life1 > 0 && if1)//�����������Ƶ���Ӧλ��	4 13 12 3
		{
			if (x < 8)
			{
				t = c[x][y];
				c[x][y] = c[4][13];
				c[4][13] = t;
			}
			else
			{
				t = c[x][y];
				c[x][y] = c[11][13];
				c[11][13] = t;
			}
			if1 = 0;
		}
		if (life2 > 0 && if2)//�����������Ƶ���Ӧλ��	4 13 12 3
		{
			if (x11 < 8)//���Ͻ�λ�� 
			{
				t = c[x11][y11];
				c[x11][y11] = c[5][3];
				c[5][3] = t;
			}
			else
			{
				t = c[x11][y11];
				c[x11][y11] = c[12][3];
				c[12][3] = t;
			}
			if2 = 0;
		}
		if (life1 == 0 && life_sign1)
		{
			if (c[1][1] == RW1)
			{
				t = c[1][2];
				c[1][2] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[1][1];
			c[1][1] = c[x][y];
			c[x][y] = t;
			life_sign1 = 0;
		}
		if (life2 == 0 && life_sign2)
		{
			if (c[15][15] == RW)
			{
				t = c[15][14];
				c[15][14] = c[x11][y11];
				c[x11][y11] = t;
			}
			t = c[15][15];
			c[15][15] = c[x11][y11];
			c[x11][y11] = t;
			life_sign2 = 0;
		}
		t = c[*mm1 - 1][*nn1];
		c[*mm1 - 1][*nn1] = c[*mm1][*nn1];
		c[*mm1][*nn1] = t;
		*mm1 -= 1;
	}
	if (c[*mm - 1][*nn] == '#')a1 = 0;
	if (c[*mm + 1][*nn] == '#')a1 = 1;
	if (c[*mm1 - 1][*nn1] == '#')b1 = 1;
	if (c[*mm1 + 1][*nn1] == '#')b1 = 0;
	return 0;
}
int weiyi = 0, host = 0;
LYQ* fp;
int  LYQ1()
{
	char hh, Z, Zt, cei = 0, h;
	char name[2], fat[5], c1[20] = "convert ", f1[20] = "format ", c2[10] = ": /fs:";
	char bgc[10] = "color ", bgc_size[4], bgc_d[] = "  ..";
	int m[10], n[10], ja = 0, ja1 = 0, prize = 3, i, j, s = 0, Tgua_sign = 0, die1 = 0, die2 = 0;
	static int speed = 100;
	static int shu = 1, cei_s = 0, a;
	if (map2) a = 8;//�������Ƹ�*���±������ 
	else 	 a = 4;
	if (cf--)//�´ξͲ����ٴ��ļ��� 
	{
		if (map2)//���map2��ֵΪ1˵��Ҫ�����ͼ2�� 
		{
			if (!(fp = fopen("��ͼ\\map2.txt", "r")))
			{
				system("cls");
				printf("��ͼ2���������ע���ļ�·���Ƿ���ȷ");
				exit(1);
			}
			map_end = 1;
		}
		else if (!(fp = fopen("��ͼ\\map1.txt", "r")))
		{
			system("cls");
			printf("��ͼ1���������ע���ļ�·���Ƿ���ȷ");
			exit(1);
		}
		for (i = 0; i < NUM; i++)
		{
			for (j = 0; j < NUM1; j++)
				c[i][j] = fgetc(fp);
			hh = fgetc(fp);//��ȡ�ı�����Ļ����ַ� 
		}
		fclose(fp);
	}
	while (1)
	{
		printf("\t     ��Ϸ����(�����յ�0���ɻ�ʤ��)\nӢ�۽�ɫ %c", RW);
		printf("(������Ƽ���w a s d)\t����ֵ%c", 3);
		printf("��%d  ��ǰλ�ã�%2d %2d  ", life1, x, y);//��һ������ 

		printf("\nӢ�۽�ɫ %c", RW1);
		printf("(������Ƽ���i j k l)\t����ֵ%c", 3);
		printf("��%d  ��ǰλ�ã�%2d %2d  ", life2, x11, y11);

		printf("\n\n�յ�(0)\t ǽ(#)\t�������(%%,$)\n���˵�С����(*)\t������(!)\n\n��ݼ����ߣ�\nR:��λ\tp:��ͣ\tz��m:���λ�λ\tv:������Ϸ�Ѷ�\tq:������Ϸ     y:�鿴Դ����\nc:��ʽ��U��\tu���ص�½ҳ��");
		printf("\tb:������ɫ\t\n\n");
		for (i = 0; i < NUM; i++)
		{
			printf("\t         ");
			for (j = 0; j < NUM1; j++)
			{
				printf("%c", c[i][j]);
				if (c[i][j] == RW)
				{
					x = i; y = j;//��ȡӢ�۽�ɫRW������x��y ������������� 
				}
				if (c[i][j] == RW1)
				{
					x11 = i; y11 = j;//��ȡӢ�۽�ɫRW1������x��y ������������� 
				}
				if (c[i][j] == '*' && a)
				{
					m[ja++] = i; n[ja1++] = j;//��ȡ*���޵�����x��y ������������� 
					a--;
				}
			}
			printf("\n");
		}
		if (die1)printf("(��Ϸ����%c������,Ŀǰ�޷��ƶ���)\n", RW);
		if (die2)printf("(��Ϸ����%c������,Ŀǰ�޷��ƶ���)\n", RW1);
		if (life1 == 0 && life2 == 0)
		{
			system("cls");
			printf("���ź�,��Ϸ����ʧ�ܣ�\n����Ҫ���¿�ʼ%c\n�밴�ո񣬷������������:\n", 3);
			life1 = LIFE1, life2 = LIFE2;//������Ϸ��ĳ�ʼֵ 
			life_sign1 = life_sign2 = 1;
			if1 = if2 = 0;
			if (getch() != ' ') exit(0);
			else return 1;
		}
	vi:
		Visit(v);
		if (kbhit())//�ж��Ƿ��˼��̣������˷���1�����򷵻�0
		{
			Z = getch();
			if (life1)
			{
				switch (Z)
				{
				case 'W':
				case 'w':if (c[x - 1][y] == '*' || c[x - 1][y] == '#' || c[x - 1][y] == RW || c[x - 1][y] == RW1 || c[x - 1][y] == '%' || c[x - 1][y] == '$')
				{
					if (c[x - 1][y] == '%')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); lyq258b(); getch(); system("color a9"); break;
					}
					break;
				}
						if (c[x - 1][y] == '$')
						{
							system("cls"); system("color 0b"); pr; getch(); system("cls"); S getch(); system("color a9"); break;
						}
						if (c[x - 1][y] == '0')
						{
							s = 1; Tgua_sign = 1; break;
						}
						if (c[x - 1][y] == '!')
						{
							if (x == 1 || x == 2)
							{
								if (c[15][15] == RW1)
								{
									t = c[14][15]; c[14][15] = c[x][y]; c[x][y] = t; break;
								}
								t = c[15][15]; c[15][15] = c[x][y]; c[x][y] = t; break;
							}
							t = c[1][1]; c[1][1] = c[x][y]; c[x][y] = t; break;
						}
						t = c[x - 1][y]; c[x - 1][y] = c[x][y]; c[x][y] = t; break;
				case 'A':
				case 'a':if (c[x][y - 1] == '*' || c[x][y - 1] == '#' || c[x][y - 1] == RW || c[x][y - 1] == RW1 || c[x][y - 1] == '%' || c[x][y - 1] == '$')
				{
					if (c[x][y - 1] == '%')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); lyq258b(); getch(); system("color a9"); break;
					}
					if (c[x][y - 1] == '$')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); S getch(); system("color a9"); break;
					}
					break;
				}
						if (c[x][y - 1] == '0')
						{
							s = 1; Tgua_sign = 1; break;
						}
						if (c[x][y - 1] == '!')
						{
							if (x == 1 || x == 2)
							{
								if (c[15][15] == RW1)
								{
									t = c[14][15]; c[14][15] = c[x][y]; c[x][y] = t; break;
								}
								t = c[15][15]; c[15][15] = c[x][y]; c[x][y] = t; break;
							}
							t = c[1][1]; c[1][1] = c[x][y]; c[x][y] = t; break;
						}
						t = c[x][y - 1]; c[x][y - 1] = c[x][y]; c[x][y] = t; break;

				case 'S':
				case 's':if (c[x + 1][y] == '*' || c[x + 1][y] == '#' || c[x + 1][y] == RW || c[x + 1][y] == RW1 || c[x + 1][y] == '%' || c[x + 1][y] == '$')
				{
					if (c[x + 1][y] == '%')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); lyq258b(); getch(); system("color a9"); break;
					}
					if (c[x + 1][y] == '$')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); S getch(); system("color a9"); break;
					}
					break;
				}
						if (c[x + 1][y] == '0')
						{
							s = 1; Tgua_sign = 1; break;
						}
						if (c[x + 1][y] == '!')
						{
							if (x == 1 || x == 2)
							{
								if (c[15][15] == RW1)
								{
									t = c[14][15]; c[14][15] = c[x][y]; c[x][y] = t; break;
								}
								t = c[15][15]; c[15][15] = c[x][y]; c[x][y] = t; break;
							}
							t = c[1][1]; c[1][1] = c[x][y]; c[x][y] = t; break;
						}
						t = c[x + 1][y]; c[x + 1][y] = c[x][y]; c[x][y] = t; break;
				case 'D':
				case 'd':if (c[x][y + 1] == '*' || c[x][y + 1] == '#' || c[x][y + 1] == RW || c[x][y + 1] == RW1 || c[x][y + 1] == '%' || c[x][y + 1] == '$')
				{
					if (c[x][y + 1] == '%')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); lyq258b(); getch(); system("color a9"); break;
					}
					if (c[x][y + 1] == '$')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); S getch(); system("color a9"); break;
					}
					break;
				}
						if (c[x][y + 1] == '0')
						{
							s = 1; Tgua_sign = 1; break;
						}
						if (c[x][y + 1] == '!')
						{
							if (x == 1 || x == 2)
							{
								if (c[15][15] == RW1)
								{
									t = c[14][15]; c[14][15] = c[x][y]; c[x][y] = t; break;
								}
								t = c[15][15]; c[15][15] = c[x][y]; c[x][y] = t; break;
							}
							t = c[1][1]; c[1][1] = c[x][y]; c[x][y] = t; break;
						}
						t = c[x][y + 1]; c[x][y + 1] = c[x][y]; c[x][y] = t; break;
				}
			}
			else die1 = 1;//������־ 
			if (life2)
			{
				switch (Z)
				{
				case 'I':
				case '8':
				case 'i':if (c[x11 - 1][y11] == '*' || c[x11 - 1][y11] == '#' || c[x11 - 1][y11] == RW || c[x11 - 1][y11] == RW1 || c[x11 - 1][y11] == '%' || c[x11 - 1][y11] == '$')
				{
					if (c[x11 - 1][y11] == '%')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); lyq258b(); getch(); system("color a9"); break;
					}
					if (c[x11 - 1][y11] == '$')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); S getch(); system("color a9"); break;
					}
					break;
				}
						if (c[x11 - 1][y11] == '0')
						{
							s = 1; Tgua_sign = 2; break;
						}
						if (c[x11 - 1][y11] == '!')
						{
							if (x11 == 1 || x11 == 2)
							{
								if (c[15][15] == RW)
								{
									t = c[14][15]; c[14][15] = c[x11][y11]; c[x11][y11] = t; break;
								}
								t = c[15][15]; c[15][15] = c[x11][y11]; c[x11][y11] = t; break;
							}
							if (c[1][1] == RW)
							{
								t = c[1][2]; c[1][2] = c[x11][y11]; c[x11][y11] = t; break;
							}
							t = c[1][1]; c[1][1] = c[x11][y11]; c[x11][y11] = t; break;
						}
						t = c[x11 - 1][y11]; c[x11 - 1][y11] = c[x11][y11]; c[x11][y11] = t; break;

				case 'J':
				case '4':
				case 'j':if (c[x11][y11 - 1] == '*' || c[x11][y11 - 1] == '#' || c[x11][y11 - 1] == RW || c[x11][y11 - 1] == RW1 || c[x11][y11 - 1] == '%' || c[x11][y11 - 1] == '$')
				{
					if (c[x11][y11 - 1] == '%')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); lyq258b(); getch(); system("color a9"); break;
					}
					if (c[x11][y11 - 1] == '$')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); S getch(); system("color a9"); break;
					}
					break;
				}
						if (c[x11][y11 - 1] == '0')
						{
							s = 1; Tgua_sign = 2; break;
						}
						if (c[x11][y11 - 1] == '!')
						{
							if (x11 == 1 || x11 == 2)
							{
								if (c[15][15] == RW)
								{
									t = c[14][15]; c[14][15] = c[x11][y11]; c[x11][y11] = t; break;
								}
								t = c[15][15]; c[15][15] = c[x11][y11]; c[x11][y11] = t; break;
							}
							if (c[1][1] == RW)
							{
								t = c[1][2]; c[1][2] = c[x11][y11]; c[x11][y11] = t; break;
							}
							t = c[1][1]; c[1][1] = c[x11][y11]; c[x11][y11] = t; break; t = c[1][1]; c[1][1] = c[x11][y11]; c[x11][y11] = t; break;
						}
						t = c[x11][y11 - 1]; c[x11][y11 - 1] = c[x11][y11]; c[x11][y11] = t; break;
				case 'K':
				case '5':
				case 'k':if (c[x11 + 1][y11] == '*' || c[x11 + 1][y11] == '#' || c[x11 + 1][y11] == RW || c[x11 + 1][y11] == RW1 || c[x11 + 1][y11] == '%' || c[x11 + 1][y11] == '$')
				{
					if (c[x11 + 1][y11] == '%')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); lyq258b(); getch(); system("color a9"); break;
					}
					if (c[x11 + 1][y11] == '$')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); S getch(); system("color a9"); break;
					}
					break;
				}
						if (c[x11 + 1][y11] == '0')
						{
							s = 1; Tgua_sign = 2; break;
						}
						if (c[x11 + 1][y11] == '!')
						{
							if (x11 == 1 || x11 == 2)
							{
								if (c[15][15] == RW)
								{
									t = c[14][15]; c[14][15] = c[x11][y11]; c[x11][y11] = t; break;
								}
								t = c[15][15]; c[15][15] = c[x11][y11]; c[x11][y11] = t; break;
							}
							if (c[1][1] == RW)
							{
								t = c[1][2]; c[1][2] = c[x11][y11]; c[x11][y11] = t; break;
							}
							t = c[1][1]; c[1][1] = c[x11][y11]; c[x11][y11] = t; break; t = c[1][1]; c[1][1] = c[x11][y11]; c[x11][y11] = t; break;
						}
						t = c[x11 + 1][y11]; c[x11 + 1][y11] = c[x11][y11]; c[x11][y11] = t; break;
				case 'L':
				case '6':
				case 'l':if (c[x11][y11 + 1] == '*' || c[x11][y11 + 1] == '#' || c[x11][y11 + 1] == RW || c[x11][y11 + 1] == RW1 || c[x11][y11 + 1] == '%' || c[x11][y11 + 1] == '$')
				{
					if (c[x11][y11 + 1] == '%')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); lyq258b(); getch(); system("color a9"); break;
					}
					if (c[x11][y11 + 1] == '$')
					{
						system("cls"); system("color 0c"); pr; getch(); system("cls"); S getch(); system("color a9"); break;
					}
					break;
				}
						if (c[x11][y11 + 1] == '0')
						{
							s = 1; Tgua_sign = 2; break;
						}
						if (c[x11][y11 + 1] == '!')
						{
							if (x11 == 1 || x11 == 2)
							{
								if (c[15][15] == RW)
								{
									t = c[14][15]; c[14][15] = c[x11][y11]; c[x11][y11] = t; break;
								}
								t = c[15][15]; c[15][15] = c[x11][y11]; c[x11][y11] = t; break;
							}
							if (c[1][1] == RW)
							{
								t = c[1][2]; c[1][2] = c[x11][y11]; c[x11][y11] = t; break;
							}
							t = c[1][1]; c[1][1] = c[x11][y11]; c[x11][y11] = t; break; t = c[1][1]; c[1][1] = c[x11][y11]; c[x11][y11] = t; break;
						}
						t = c[x11][y11 + 1]; c[x11][y11 + 1] = c[x11][y11]; c[x11][y11] = t; break;
				}
			}
			else die2 = 1;
			switch (Z)
			{
			case 'R':
			case 'r':weiyi = 1; return 1; break;
			case 'M':
			case 'm':
			case 'Z':
			case 'z':t = c[x][y]; c[x][y] = c[x11][y11]; c[x11][y11] = t; break;
			case 'P':
			case 'p':while (1)
			{
				Zt = getch();
				if (Zt == 'p' || Zt == 'P')break;
				else printf("�밴P��������\n");
			}
					break;
			case 'v':
			case 'V':
				system("cls");
				system("color 16");
				printf("������һ�������������������������ı�ѭ�����ٶȣ�ֵԽ���ٶ�Խ��,Ĭ��ֵ��0����   ");
				scanf("%d", &v);
				system("color a9");
				goto vi;
				break;
			case 'Q':
			case 'q':life_sign1 = life_sign2 = 1; life1 = LIFE1, life2 = LIFE2; x = y = 1; x11 = y11 = 15; if1 = if2 = 0; return 1;
			case 'y':
			case 'Y':
				system("cls");
				system("color 0a");
				srand(time(NULL));
				printf("��;��ͣ�밴�ո��,��������ٶ��밴���ּ�������Խ���ٶ�Խ��,��S����������ٶ�Ŷ��%c��\n", 2);
				system("pause");
				system("cls");
				if (!(fp = fopen("С��Ϸ��C������Ϸ���룩 - ����Ч.c", "r")))
				{
					printf("���ļ�λ��������ȷ���Ƿ���Dev����򿪣�\n");
					exit(0);
				}
				t = fgetc(fp);
				while (!feof(fp))//�ļ��򿪳ɹ�����1����֮0 
				{
					if (t == '\n') Sleep(speed);
					if (kbhit())
					{
						switch (getch())
						{
						case '9':speed = 850; break;
						case '8':speed = 750; break;
						case '7':speed = 650; break;
						case '6':speed = 550; break;
						case '5':speed = 450; break;
						case '4':speed = 350; break;
						case '3':speed = 250; break;
						case '2':speed = 150; break;
						case '1':speed = 50; break;
						case '0':speed = 0; break;
						case 'S':
						case 's':speed = rand() % 1000; printf("\n��ǰ�ٶȣ�%d", speed); break;
						case ' ':getch(); break;
						default:break;
						}
					}
					putchar(t);
					t = fgetc(fp);
				}
				fclose(fp);
				printf("\n\a�������ϣ�\n");
				getch();
				system("color a9");
				break;
			case 'c':
			case 'C':
			c:
				system("cls");
				system("color 0a");
				printf("���������ּ�������Ӧ�Ĺ��ܣ�\n");
				printf("�������֣�1��,���ܣ���format�����ʽ��U��(�ù��ܻ��U���ڵ�����ɾ��,��ע�ⱸ��)\n");
				printf("�������֣�2��,���ܣ��ø�convert�����ʽ��U��(�����U�̲���NTFS��ʽ,ʹ�ø�������Բ���\t\t    ɾ�����U������,ֱ�ӱ��ntfs��ʽ)\n\n");
				printf("�������֣�3�������ܣ������ֶ���ʽ��U�̣�\n");
				h = getch();
				if (h == '1')
				{
					system("cls");
					printf("��������Ҫѡ����̷���Ҫѡ����ļ�ϵͳ,ע���ÿո��������:c ntfs����\n");
					scanf("%s%s", name, fat);
					strcat(f1, name);
					strcat(c2, fat);
					getch();
					strcat(f1, c2);
					printf("���������ʽ��");
					puts(f1);
					system(f1);
					f1[7] = c2[6] = '\0';
					getch();
					system("color a9");
				}
				else if (h == '2')
				{
					system("cls");
					printf("��������Ҫѡ����̷���Ҫѡ����ļ�ϵͳ,ע���ÿո��������:c ntfs����\n");
					scanf("%s%s", name, fat);
					strcat(c1, name);
					strcat(c2, fat);
					strcat(c1, c2);
					printf("���������ʽ��");
					puts(c1);
					system(c1);
					c1[8] = c2[6] = '\0';
					getch();
					system("color a9");
				}
				else if (h == '3')
				{
					system("cls");
					system("diskpart");
				}
				else
				{
					system("cls");
					printf("��������������������룡\n");
					goto c;
				}
				break;
			case 'b':
			case 'B':
				system("cls");
			qm:
				printf("��������ı���ɫ(��ֵ������ʮ�����Ƶ������)\n����0A 0������ɫ,����������ɫ������鿴���࣬������1\n");
				gets_s(bgc_size);
				if (bgc_size[0] == '1')
				{
					strcat(bgc, bgc_d);
					system(bgc);
					bgc[6] = '\0';//��bgc�»�õ�ֵȥ�� 
					getch();
					if (1) goto qm;
				}
				else
				{
					strcat(bgc, bgc_size);
					system(bgc);
					bgc[6] = '\0';//��bgc�»�õ�ֵȥ�� 
				}

				break;
			case 'U':
			case 'u':
				host = 1;
				return 1;
				break;
			}//switch endx
			if (s == 1)goto loop1;
		}//kbhit end
		if (map2 == 1)
		{
			if (move_yz(&m[1], &n[1], &m[0], &n[0]))  return 1;//��Ҫ�ƶ���*��ַ����ȥ 
			if (move_yz1(&m[3], &n[3], &m[2], &n[2])) return 1;//��ֹ��һ��a,b��ֵ��ȷ�������˶��һ���ĺ��� 
			if (move_yz2(&m[5], &n[5], &m[4], &n[4])) return 1;
			if (move_yz3(&m[7], &n[7], &m[6], &n[6])) return 1;
		}
		else
		{
			if (move_yz(&m[0], &n[0], &m[3], &n[3])) return 1;//��Ҫ�ƶ���*��ַ����ȥ 
			if (move_sx(&m[2], &n[2], &m[1], &n[1])) return 1;//��Ҫ�ƶ���*��ַ����ȥ
		}
		system("cls");
	}//whileѭ�����˽��� 
loop1:
	system("cls");
	printf("��Ϸͨ�سɹ�\n\n");
	if (Tgua_sign == 1)
	{
		printf("��ϲ���ǵ�Ӣ��  %c\t��ʤ!%c\n", RW, 1);
		printf("�밴�������ȡ��Ʒ��\n");
		getch();
		while (prize)
		{
			system("cls");
			if (map2 == 1)
			{
				printf("���ս�Ʒ��������Ч!\n��Ʒ���ڷ����� %d\a\n\n��ϷС��ʾ����������������ǵð�������ر�����������Ŷ��\n\n��������а����ܼ�(F11)�ɽ���ȫ���ɻ�����Ч���ء�", prize, 14);
				Sleep(1000);
			}
			else
			{
				printf("��Ʒ���ǿ�����!\n��Ʒ���ڷ����� %d\a\n\n��ϷС��ʾ����������������ǵð�������ر�����������Ŷ��\n\n��������а����ܼ�(F11)�ɽ���ȫ���ɻ�����Ч���ء�", prize, 14);
				Sleep(1000);
			}
			prize--;
		}
		if (map2 == 1)
		{
			system("��ҳ�ļ�\\������Ч.html");
			system("cls");
			printf("��ȡ��ϣ�\n");
			while (shu)
			{
				printf("�밴�����������һ�ء�\n");
				getch();
				shu--;
				return 0;
			}
		}
		else
		{
			system("��ҳ�ļ�\\�ǿ�����.html");
			system("cls");
			printf("��ȡ��ϣ�\n");
			while (shu)
			{
				printf("�밴�����������һ�ء�\n");
				getch();
				shu--;
				return 0;
			}
		}
	}
	else if (Tgua_sign == 2)
	{
		printf("��ϲ���ǵ�Ӣ��  %c\t��ʤ!%c \n", RW1, 1);
		printf("�밴�������ȡ��Ʒ��\n");
		getch();
		while (prize)
		{
			system("cls");
			if (map2 == 1)
			{
				printf("���ս�Ʒ��������Ч!\n��Ʒ���ڷ����� %d\a\n\n��ϷС��ʾ����������������ǵð�������ر�����������Ŷ��\n��������а����ܼ�(F11)�ɽ���ȫ���ɻ�����Ч���ء�", prize, 14);
				Sleep(1000);
			}
			else
			{
				printf("��Ʒ��������!\n��Ʒ���ڷ����� %d\a\n\n��ϷС��ʾ����������������ǵð�������ر�����������Ŷ��\n��������а����ܼ�(F11)�ɽ���ȫ���ɻ�����Ч���ء�", prize, 14);
				Sleep(1000);
			}
			prize--;
		}
		if (map2 == 1)
		{
			system("��ҳ�ļ�\\������Ч.html");
			system("cls");
			printf("��ȡ��ϣ�\n");
			while (shu)
			{
				printf("�밴�����������һ�ء�\n");
				getch();
				shu--;
				return 0;
			}
		}
		else
		{
			system("��ҳ�ļ�\\������.html");
			system("cls");
			printf("��ȡ��ϣ�\n");
			while (shu)
			{
				printf("�밴�����������һ�ء�\n");
				getch();
				shu--;
				return 0;
			}
		}
	}
	else printf("Game over��");
	system("pause");
	return 0;//����0������������������ 
}
#define CD 20
struct user
{
	char name_zh[CD], name_pw[CD];
}stu, * p = &stu;
void C_game()
{
	int s = 1, a = 1, djs1 = 3, kg = 0, i = 0, j = 0, x = 0, y = 0, weiz = 0, m, across = 0, v = 0, s_r = 0;
	char name[50] = "title ��Ϸ��ʼ(���: ������)", ch, zhangH[CD], password[CD];
star:
	system("color 0C");
	system("Mode con cols=42 lines=6"); //���ƴ��ڴ�С��עcols����Сֵ��16�����ܵ��ڸ�ֵ 
	system("title C����С��Ϸ��258�ࣩ");//�޸Ĵ��ڵ����� 
	printf("��ӭ���������Ϸ����%c\n\n", 11);
	system("pause");
	system("cls");
	printf("��Ϸ�ѿ���\n\n�������ȵ�½����˺�,�����޷�������Ϸ\n\n�����ּ�1�����½ҳ�档\n");
log_on:
	if (getch() == '1')
	{
	host1:
	log_zh:
	fail:
	log:
		system("cls");
	qian:
		system("cls");
		system("Mode con cols=42 lines=9");
		printf("�˳���Ϸ������0\n\n");
		printf("�½��˺�������1\n\n");
		printf("��½�˺�������2\n\n");
		if (s_r && ch != '0' && ch != '1' && ch != '2')	printf("\n�����������������룡\n");
		ch = getch();
		if (ch == '1')//�½��˺�
		{
			system("cls");
			printf("����������˺ţ�\n");
			gets_s(stu.name_zh);
			printf("������������룺\n");
			gets_s(stu.name_pw);
			name[21] = '\0';
			strcat(name, stu.name_zh);
			strcat(name, ")");
			if (!(fp = fopen("��ͼ\\user.txt", "r+")))
			{
				printf("�ļ���ʧ�ܣ���ע���Ƿ���Dev�����!");
				exit(0);
			}
			ch = fgetc(fp);
			if (ch == EOF)//�жϵ�ǰ�ĵ��Ƿ�Ϊ�� ���Ϊ�������� 
			{
				fputs("��ɫ�˺�������: ", fp);
				fputs(stu.name_zh, fp);//��struct�ṹ������ȡ8����fpָ����ļ� 
				fputc(' ', fp);//���ո��fpָ����ļ�����־ 
				fputs(stu.name_pw, fp);
				fputc('\n', fp);
				fclose(fp);
			}
			else
			{
				fseek(fp, -0L, 2);// ���ǰ�ĵ��ǲ��ǿ� ����ָ��ָ��ָ��ĩβ
				fputs("��ɫ�˺�������: ", fp);
				fputs(stu.name_zh, fp);//��struct�ṹ������ȡ8����fpָ����ļ� 
				fputc(' ', fp);//���ո��fpָ����ļ�����־ 
				fputs(stu.name_pw, fp);
				fputc('\n', fp);
				fclose(fp);
			}
			printf("\n�����û��Ѵ����ɹ���\n��ǰ����½�û���½����˻�,лл����%c��\n", 2);
			system("pause");
			s_r = 0;
			goto log_zh;
		}
		else if (ch == '2')//��½�˺� 
		{
			system("cls");
			printf("����������˺ţ�\n");
			gets_s(zhangH);
			printf("����������˺����룺\n");
			gets_s(password);
			if (!(fp = fopen("��ͼ\\user.txt", "r+")))
			{
				printf("�ļ���ʧ�ܣ���ע���Ƿ���Dev�����!");
				exit(0);
			}
			ch = fgetc(fp);
			if (ch == EOF)//˵���ļ�Ϊ�գ����˻���½ 
			{
				system("Mode con cols=50 lines=6");
				system("cls");
				printf("�㻹δ�����û����봴���������˵�½��лл������%c\n����������ء�", 2);
				getch();
				goto log;
			}
			while (!feof(fp))//���ļ��򿪳ɹ������ѭ�� 
			{
				if (ch == ' ')//�����ո� 
				{
					if (weiz == 0) x = ftell(fp);//��¼��һ���ո��λ�� 
					else y = ftell(fp);//��¼�ڶ����ո��λ�� 
					weiz++;
					if (y)
					{
						fseek(fp, x, 0);//��ָ����ĵ���ͷ�Ƶ�ǰһ���ո���λ�� 
						for (i = 0; i < y - x - 1; i++)//��¼�˺� 
							stu.name_zh[i] = fgetc(fp);
						stu.name_zh[i] = '\0';//��������Ϊ������ 
						i = 0;
						ch = fgetc(fp);//������ĵڶ����ո���� ָ������ڶ����ո�� 
						while ((stu.name_pw[i] = fgetc(fp)) != '\n')i++;//��¼���� 
						stu.name_pw[i] = '\0';//����ȡ�Ļ��з�ȥ��
						weiz = 0;
						y = 0;
						if (!strcmp(zhangH, stu.name_zh) && !strcmp(password, stu.name_pw))
						{
							across = 1;//�˺ŷ��ϵı�־
							break;// 
						}
					}
				}
				ch = fgetc(fp);
			}
			fclose(fp);
			if (across) //�ж��Ƿ������˺ŷ��ŵ�½���� 
			{
				system("cls");
				printf("��½�ɹ���ף����Ϸ��죡%c\n", 2);
				name[21] = '\0';
				strcat(name, stu.name_zh);
				strcat(name, ")");
				Sleep(900);
				system("color 0b");
			}
			else //����ͷ��ص�¼ҳ�� 
			{
				system("cls");
				printf("��½ʧ�ܣ�\n\n��ע������˻������Ƿ�������ȷ\n���߻�δ�������û�\n\n");
				system("pause");
				goto fail;
			}
			s_r = 0;
		}
		else if (ch == '0')
		{
			system("cls");
			printf("��Ϸ��������ӭ�´ι��٣�\n");
			exit(0);
		}
		else
		{
			s_r = 1;
			goto qian;
		}
	}
	else
	{
		system("cls");
		printf("�㻹û�е�½����˻���������1���룡\n");
		goto log_on;
	}
	while (1)
	{
		if (host == 1)
		{
			host = 0;
			goto host1;
		}
		if ((weiyi--) == 1)goto weiyi1;// ����ˢ�� 
		if (djs) system("title С��Ϸ������");
		while (djs)//����ʱ 
		{
			system("cls");
			printf("��Ϸ��������ʱ%c��\a", 12);
			printf("%d", djs--);
			Sleep(1000);//ִ�й���һ��ʱ��,�ӳ�һ�� ����λ�Ǻ��� ��ע��sleep(Сд)�����ĵ�λ���� 
		}
		if (s--)
		{
			system("Mode con cols=36 lines=1");
			system("cls");
			printf("��Ϸ��ʼ!%c", 15);
			Sleep(1000);
			system(name);
			system("cls");
			printf("��һ�أ�������ת�أ�%c", 21);
			Sleep(1000);
		}
		system("color 0b");
	map2:
		system("Mode con cols=85 lines=30");
	weiyi1:
		if (!LYQ1())break;
	}
	while (djs1)
	{
		system("cls");
		printf("���ڽ�����һ��%d %c\a", djs1, 1);
		map2 = 1;//���ص�ͼ2�ı�־ 
		cf = 1;//�����ļ��Ĵ��� 
		Sleep(1000);
		djs1--;
	}
	if (map_end == 1) goto map2break;
	system("cls");
	printf("�ڶ��أ�ɽ���أ�%c", 22);
	Sleep(1000);
	system("cls");
	djs1 = 0;
	goto map2;
map2break:
	system("cls");
	printf("��Ϸͨ�أ�Game over!%c\n��ӭ�´ι��٣�", 1);
}
int main()
{
	C_game();
	system("pause");
	return 666;
}