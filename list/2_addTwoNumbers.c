
/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

/*这个算法不断开辟内存消耗大量时间，虽然通过了，需要修改*/
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    
	struct ListNode *p1, *p2;
	struct ListNode *rlHead = NULL;
	struct ListNode *ptmp = NULL;
    struct ListNode *ptail = NULL;
	int bit = 0;
	
	p1 = l1;
	p2 = l2;
	
	while(p1 || p2){
		ptmp = (struct ListNode *)malloc(sizeof(struct ListNode));
		ptmp->val = (p1?p1->val:0)+(p2?p2->val:0);
		ptmp->val = (bit == 1)?(ptmp->val+1):ptmp->val;
        //printf("1:%d\n", ptmp->val);
		bit = (ptmp->val>=10)?1:0;
		ptmp->val= (ptmp->val>=10)?(ptmp->val-10):ptmp->val;
        printf("%d\n", ptmp->val);
        ptmp->next = NULL;
		if (rlHead == NULL){
			rlHead = ptmp;
			ptail = ptmp;
		}else{
			ptail->next = ptmp;
			ptail = ptmp;
		}
        p1 = (p1 != NULL)?(p1->next):NULL;
		p2 = (p2 != NULL)?(p2->next):NULL;
        
	}
	if (bit == 1){
		ptmp = (struct ListNode *)malloc(sizeof(struct ListNode));
		ptmp->val= 1;
        ptmp->next = NULL;
        ptail->next = ptmp;
	 
	}
        
	return rlHead;

}
