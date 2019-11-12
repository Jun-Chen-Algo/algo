/*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。

解题思路：如果是负数，返回false
		  如果是正数，取出它的逆序数，
			如果逆序数溢出，则返回false，否则比较逆序是否和该整数相等，
				相等返回true
*/

bool isPalindrome(int x)
{
	unsigned long long rs = 0;
	int input = x;
	
	if (x<0)
		return false;
	for(;x;x/=10){
		rs = rs*10+x%10;
		//printf("@@@%llu\n", rs);
	}
	if (rs>0x7FFFFFFF)
		return false;
	if (rs == input)
		return true;
	return false;	
}
