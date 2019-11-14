/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

给定 nums = [0,0,1,1,1,2,2,3,3,4],

函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。

你不需要考虑数组中超出新长度后面的元素。

解题思路：线性遍历，利用快慢指针思想，跳过重复项
*/

#include <stdio.h>
#include <string.h>

int removeDuplicates(int* nums, int numsSize)
{
	int i, j = 0;//i是快指针，j是慢指针
	int now = nums[0];
	
    if (numsSize == 0)
        return 0;
	for (i = 0; i<numsSize; i++){
		if (nums[i] == now){
			continue;	
		}else{
			j++;
			nums[j] = nums[i];
			now = nums[i];
		}
	}
	return j+1;
	 
}
int main(int argc, char *argv[])
{
	int nums[] = {0,0,1,1,1,2,2,3,3,4,4,5,5,6,6,7,8,9};
	int len, i;
	
	len = removeDuplicates(nums, sizeof(nums)/sizeof(int));
	for(i = 0; i<len; i++){
		printf("%d ", nums[i]);
	}
	printf("\n");
	return 0;
}
