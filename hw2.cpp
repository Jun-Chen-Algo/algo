/*COMPANY:HW
*某个打印机根据打印队列执行打印任务。
*打印任务分为九个优先级，分别采用数字1~9表示，数字越大优先级越高。
*打印机每次从队列头部取出第一个任务A，然后检查队列余下任务中有没有比A优先级更高的任务，如果有比A优先级高的任务，则将任务A放到队列尾部，否则执行任务A的打印。
*请编写一个程序，根据输入的打印队列，输出实际打印顺序。
*函数原型：void printOrder(const int input[], int len, int output[])
*参数input表示打印队列，为1~9（优先级）组成的数组，数组索引0代表头部。对于C/C++参数len代表input数组长度，假定参数合法有效；
*Author:chenjun
*Date:2018/7/19
*/ 

#include <stdio.h>
#include <string.h>

void printOrder(const int input[], int len, int output[])
{
	int a[32] = {0}, b[32] = {0};
	int i,j,tmp;
	
	/*复制排序数组*/
	for (i = 0; i<len; i++){
		a[i] = input[i];
		b[i] = input[i];
	}
	/*冒泡排序，降序*/
	for (i = 0; i<len; i++){	
		for (j = len-1; j>=i+1; j--){
			if (a[j]>a[j-1]){
				tmp = a[j-1];
				a[j-1] = a[j];
				a[j] = tmp;
			}
		}
	}
	/*出队列索引*/ 
	for(i = 0; i<len; i++){
		for (j = 0; j<len; j++){
			if (a[i] == b[j] && b[j] != 0xff){
				output[i] = j;
				b[j] = 0xff;
				break;	/*当选到符合条件的第一个，break，否则会覆盖索引*/
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

