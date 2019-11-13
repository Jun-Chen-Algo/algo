/*将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode * temp1, *temp2, *head, *tail, *newst;
	int val1, val2;
	
	temp1 = l1;
	temp2 = l2;
	head = tail = NULL;
	while(1){
		if (!temp1 && !temp2)
			return head;
		if (temp1){
			val1 = temp1->val;
		}
		if (temp2){
			val2 = temp2->val;
		}
		//printf("@@%d - %d\n", val1, val2);
		newst = (struct ListNode*)malloc(sizeof(struct ListNode));
		if (!newst){
			return head;
		}
		if (!temp1){
			newst->val = val2;
			temp2 = temp2->next;
		}else if(!temp2){
			newst->val= val1;
			temp1 = temp1->next;
		}else if (val1<=val2){
			newst->val = val1;
			temp1 = temp1->next;
		}else {
			newst->val= val2;
			temp2 = temp2->next;
		}
		newst->next = NULL;
		if (!head){
			head = newst;
			tail = newst;
		}else{
			tail->next= newst;
			tail = newst;
		}
		
			
	} 
}