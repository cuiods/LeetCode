// 160-Intersection of Two Linked Lists.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA==NULL || headB==NULL) return NULL;
		ListNode *a = headA;
		ListNode *b = headB;
		int count = 0;
		while (a != b && count < 3) {
			if (a->next==NULL) count++;
			if (b->next==NULL) count++;
			a = a->next==NULL? headB: a->next;
			b = b->next==NULL? headA: b->next;
		}
		if (count < 3) return a;
		else return NULL;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

