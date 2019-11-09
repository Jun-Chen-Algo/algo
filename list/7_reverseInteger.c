/*
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
解题思路：int->string,反序可以从str[0]开始计算倍数，
还是注意溢出问题，一个是计算值时注意溢出，最后检查一下带符号的溢出
			负值最大 INT_MIN = -2147483648
			正值最大 INT_MAX = 2147483647
*/
/*更新一个评论区的大神代码*/
int reverse(int x)
{
    int max = 0x7fffffff, min = 0x80000000;//int的最大值最小值
    long rs = 0;//用long类型判断溢出
    for(;x;x/=10){//逆序，正负通吃，不用单独考虑负值{
		rs = rs*10+x%10;
	}
    return rs>max||rs<min?0:rs;//超了最大值低于最小值就返回0
}

int reverse(int x)
{
	char a[32] = {0};
	int len = 0;
	int i = 0, j =0 , k = 0;
	unsigned int base = 0;
	unsigned int total = 0;
	int flag = 0;
	int ret = 0;
	int tmp;
	 
	sprintf(a, "%d", x);
	len = strlen(a);

	if (a[0] == '-'){
		i = 1;
		flag = 1;//负数
		if (len>11)
			return 0;
	}else{
		i = 0;
		if (len>10)
			return 0;
	}

	for (i; i<len; i++){
		if (k == 0){
			tmp = 1;
			base = 1;
			k++;
		}else{
			tmp = base*10;
			base = base*10;
		}
		if (i>8&&(base*(a[i]-'0')<tmp)){ //倍数溢出检查，因为倍数是越来越大
			return 0;
		} 
		total = total + base*(a[i]-'0');
		if (total < base*(a[i]-'0')){	//total溢出检查
			return 0;
		}
	}
	//带符号检查
	if ((flag == 1 && total>2147483648) ||
	(flag == 0 && total >2147483647))
		return 0;
		
	//上面会控制在-2147483648-2147483647之间，可以类型转换成int
	ret = (int)total;
	if (flag == 1)
		ret = ~ret+1;
		
	return ret;
}