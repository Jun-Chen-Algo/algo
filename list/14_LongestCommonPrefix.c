/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
*/
/*
解题思路：如果数组长度为0，则返回“”
			如果数组长度为1， 则返回strs[0]
			先遍历找出最小长度的元素，记录len
			依次遍历每个元素的每个字符，如果有不一样的就退出
*/

char * longestCommonPrefix(char ** strs, int strsSize)
{
	int i, j;
	int min_len = 0;
	char tmp = 0;
	static char rs[1000] = {0};
	
    memset(rs, 0, 1000);
	if (strsSize == 0){
		return "";
	}
	if (strsSize == 1){
		return (*strs);
	}
	/*find min len string */
	min_len = strlen(strs[0]);
	for (i = 0; i<strsSize; i++){
		if (strlen(strs[i])<min_len){
			min_len = strlen(strs[i]);
		}
	}
	if (min_len == 0)
		return "";
	
	for (i = 0; i<min_len; i++){
		tmp = strs[0][i];
		for (j = 1; j<strsSize; j++){
			if (strs[j][i] != tmp){
				goto END;
			}
		}	
	}
END:
	strncpy(rs, strs[0], i);
	return rs;
}