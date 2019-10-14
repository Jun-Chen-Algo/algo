/*COMPANY:HW
*ĳ����ӡ�����ݴ�ӡ����ִ�д�ӡ����
*��ӡ�����Ϊ�Ÿ����ȼ����ֱ��������1~9��ʾ������Խ�����ȼ�Խ�ߡ�
*��ӡ��ÿ�δӶ���ͷ��ȡ����һ������A��Ȼ�������������������û�б�A���ȼ����ߵ���������б�A���ȼ��ߵ�����������A�ŵ�����β��������ִ������A�Ĵ�ӡ��
*���дһ�����򣬸�������Ĵ�ӡ���У����ʵ�ʴ�ӡ˳��
*����ԭ�ͣ�void printOrder(const int input[], int len, int output[])
*����input��ʾ��ӡ���У�Ϊ1~9�����ȼ�����ɵ����飬��������0����ͷ��������C/C++����len����input���鳤�ȣ��ٶ������Ϸ���Ч��
*Author:chenjun
*Date:2018/7/19
*/ 

#include <stdio.h>
#include <string.h>

void printOrder(const int input[], int len, int output[])
{
	int a[32] = {0}, b[32] = {0};
	int i,j,tmp;
	
	/*������������*/
	for (i = 0; i<len; i++){
		a[i] = input[i];
		b[i] = input[i];
	}
	/*ð�����򣬽���*/
	for (i = 0; i<len; i++){	
		for (j = len-1; j>=i+1; j--){
			if (a[j]>a[j-1]){
				tmp = a[j-1];
				a[j-1] = a[j];
				a[j] = tmp;
			}
		}
	}
	/*����������*/ 
	for(i = 0; i<len; i++){
		for (j = 0; j<len; j++){
			if (a[i] == b[j] && b[j] != 0xff){
				output[i] = j;
				b[j] = 0xff;
				break;	/*��ѡ�����������ĵ�һ����break������Ḳ������*/
			}
		}
	}
}
int main(void)
{
	int a[100] = {0};
	int b[100] = {0};
	int i = 0, j = 0, k = 0;

	while(true){
		do{
			scanf("%d",&a[i++]);
		}while(getchar()!='\n');

		printOrder(a, i, b);
		for (j = 0; j < i; j++){
			if (k!=0)
				printf(",");
			printf("%d", b[j]);
			k++;
		}
			
		printf("\n");
		i = 0;
		k = 0;
	}
	return 0;
}

