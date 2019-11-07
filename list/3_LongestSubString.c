#include <stdio.h>
#include <string.h>

/*
题目：无重复字符的最长子串

给定一个字符串，请你找出其中不含有重复字符的最长子串的长度。

示例?1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是?"wke"，所以其长度为 3。
?    请注意，你的答案必须是 子串 的长度，"pwke"?是一个子序列，不是子串。

*/

/*解题思想:
采用滑动窗口来解决本题可以控制时间复杂度为O(n),暴力破解法TIMEOUT
############################################################
当字符串长度大于2时，进行滑动窗口操作，左指针指向0，
右指针指向1，判断右指针所在的字符是否存在于s[left, right-1]，
	如果不存在: 右指针向右滑动一个位置，更新最大子串长度right-left+1
	如果存在:	找到存在的位置，右指针的字符替代存在的字符，
				左指针跳跃至exist+1，更新最大子串长度right-left+1，
				判断右指针是否可以继续滑动，可以则右指针继续滑动一个位置，
				否则到达右侧边界，返回最大子串长度

*/
int stringContainChar(char *s, int left, int right)
{
    int i;

    for(i = left; i<right; i++){
        if (s[i] == s[right]){
            return i;
        }
    }
    return -1;
}

int lengthOfLongestSubstring(char * s)
{
    int left, right;
    int strLen = strlen(s);
    int maxSubStrLen = 0;
    int exist = 0;

    if (strLen == 0){//字符串长度为0时直接返回0
        return 0;
    } 
    if (strLen == 1){//字符串长度为1时直接返回1 
        return 1;
    }

    left  = 0;//初始左指针都指向s[0]
    right = 1;//初始右指针都指向s[1]
    while(1){
        while(right<strLen){
            exist = stringContainChar(s, left, right);
            if (exist == -1){
                //前面不存在时，长度加1，右指针继续滑动
                maxSubStrLen = (right-left+1)>maxSubStrLen?(right-left+1):maxSubStrLen;
                right++;
                //如果指针到头了，则输出结果 
                if (right == strLen)
                    return maxSubStrLen; 
            }else{ 
                left = exist+1;
                maxSubStrLen = (right-left+1)>maxSubStrLen?(right-left+1):maxSubStrLen;
                //因为left一直小于等于right，因此只需要判断right是否越界 
                if (right == (strLen-1))
                    return maxSubStrLen;
                right++;
            }
        }
    }
    return maxSubStrLen;

}

int main(int argc, char *argv[])
{
    char a[32] = {0};
    
    strcpy(a, "");
    int b = lengthOfLongestSubstring(a);
    printf("%d\n", b);
    return 0;
}
