#include "stdio.h"
int main()
{
	FILE *fp;
	char a;
	if(!(fp=fopen("1.txt","r")))
		    {
		    	system("cls");
		    	printf("��ͼ2���������ע���ļ�·���Ƿ���ȷ");
		    	exit(1);
		    }
	fseek(fp,2L,0);
	printf("%d\n",ftell(fp));
	printf("%c\n",fgetc(fp));
	printf("%d\n",ftell(fp));
	fseek(fp,2L,1);
	printf("%d\n",ftell(fp));
	printf("%c",fgetc(fp));
	fclose(fp);
	return 666;
}
