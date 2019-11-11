/*
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
请你实现这个将字符串进行指定行数变换的函数：
string convert(string s, int numRows);
示例 1:
输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
示例 2:
输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:
L     D     R
E   O E   I I
E C   I H   N
T     S     G
*/
/*
解题思路：本题思路很清晰，在遍历字符串s时，将其按照行的顺序进行存储，构建结构体ST，
利用两个for循环进行V字形分布。最后遍历数组，重组输出rs。
*/

typedef struct{
	int  rows;//Z字形的行号
	char ch;//存储字符
}ST;
#define ARRAY_LEN_MAX	1000
#define INVAILD		0XFF

char * convert(char * s, int numRows)
{
	static ST test[ARRAY_LEN_MAX];
	int i = 0, j = 0, k = 0;
	int len = strlen(s);
	static char rs[ARRAY_LEN_MAX] = {0};
	
    memset(rs, 0, ARRAY_LEN_MAX);
	//空字符串返回“”
	if (len == 0){
		return "";
	}
	//行数为1时，就是这个字符串
 	if (numRows == 1){
        memcpy(rs, s, strlen(s));
        return rs;
    }
	for (i = 0; i<ARRAY_LEN_MAX; i++){
		test[i].rows= INVAILD;
        test[i].ch = 0;
	}
	//初始i,j
	i = 0;
	j = 0;
	while(i<len){
		//递增
		for (; j<numRows && i<len; j++,i++){
			test[i].rows = j;
			test[i].ch= s[i];
		}
		//递减
		for (j = j-2; j>=0 && i<len; j--, i++){
			test[i].rows = j;
			test[i].ch= s[i];
		}
		j = 1;//第一个V之后，均从1开始，base 0
	}
	//输出字符串
	for (i = 0; i<numRows; i++){
		for (j = 0; j<ARRAY_LEN_MAX; j++){
			if (test[j].rows == i && test[j].ch != 0){
				rs[k] = test[j].ch;
				k++;
			}
		}
	}
	rs[k] = '\0';
	return rs;	
}
