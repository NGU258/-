#include "stdlib.h"
int cheng(int a,int b)
{
	int sum=1,i;
	for(i=1;i<=b;i++)
	 sum*=a;
	return sum;
}
void hua()
{
	int a; 
	printf("\t\t\t�м�ռ������������ȡ����֮����\n",1);
    printf("    �ó�����㷨�ǽ���ĳ������������,�밴��Ҫ����в���,лл���");
    printf("%c��\n\t\t\t����Ҫ�򿪼������밴���ּ� 1\n",3);
    printf("\t        �������������(����2022��ȥ���������һ���ֵ)\n\t\t\t\t    ");
}
void huaa()
{
	printf("\t\t\t�м�ռ������������ȡ����֮����\n",1);
    printf("    �ó�����㷨�ǽ���ĳ������������,�밴��Ҫ����в���,лл���");
    printf("%c��\n",3);
}
void hua1()
{
	printf("\t\t\t�õ�");
    printf("%c",3);
    printf("�����뿴������������%c:\n\n",1);
}
int by(int month[])
{
	int i,x=0,sum=0;
	for(i=4;i>=0;i--)
    {
    	sum+=month[i]*cheng(2,x);
    	x++;
    }
    return sum;
}
void hua2(int y,int s,int s1)
{
	 int i;
	 printf("\n\t   ����֪���������,����鿴���������Ϣ,����������666");
     printf("%c\n",1);
     loop:printf("\t\t\t\t       ");
     scanf("%d",&i);
     if(i==666)
     {
     printf("\n\t \t\t���ĳ�������: %d��%d��%d��",y,s,s1);
     printf("\n\n\t    �����򵽴�ִ�н���,лл����ʹ��,��ӭ�´�������");
     printf("%c\a\a",1);
     }
      else 
     {
     	printf("\t\t\t ����������666��лл��ϣ�");
     	printf("%c\n",3);
     	goto loop;
     }
}

void lyq258b()
{
    int A[5][16]={16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,
    			  8,9,10,11,12,13,14,15,24,25,26,27,28,29,30,31,
    			  4,5,6,7,12,13,14,15,20,21,22,23,28,29,30,31,
    			  2,3,6,7,10,11,14,15,18,19,22,23,26,27,30,31,
    			  1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31};
    int c=1,yr,i,j,sum=0,sum1=0,num,month[5],day[5],*x=month,*y=day,m=0,yy;
    y:
    system("cls");
    hua();
    scanf("%d",&yy);
    if(yy==1) 
	{	 
	 system("calc.exe");
	 goto y; 
	}
    else 
	{
	 yr=2022-yy; 
	}	
    hua1();
    for(i=0;i<5;i++)
    {   system("cls");
    	huaa();
    	//hua1();  	
    	printf("����������������������·���,������1,��û�г���,������0��\n    ��%d��\n",c++);
    		for(j=1;j<17;j++)
    	{
    	
    		printf("%3d",A[i][j-1]);
    		if(j%4==0&&j!=0)printf("\n");
    		
    	}
    	printf("\n");
    	scanf("%d",&num);
    	month[m++]=num;
    }
    
    c=1,m=0;
    for(i=0;i<5;i++)
   	 	{   system("cls");
   	 		huaa();
   	 		printf("\n\t\t\t  ע�⣬�뿴��������:\n");  	
   	 		printf("\n����������������������շ���,������1,��û�г���,������0��\n    ��%d��\n",c++);
    		for(j=1;j<17;j++)
    		{
    			printf("%3d",A[i][j-1]);
    			if(j%4==0&&j!=0)printf("\n");
    		}
    		printf("\n");
    		scanf("%d",&num);
    		day[m++]=num;
   		}	
  	    sum=by(x);
    	sum1=by(y);
   		hua2(yr,sum,sum1);
}
