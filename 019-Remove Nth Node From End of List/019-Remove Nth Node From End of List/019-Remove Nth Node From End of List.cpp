// 019-Remove Nth Node From End of List.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* first = head;
		ListNode* second = head;
		for (int i = 0; i < n; i++) {
				second = second->next;
		}
		if (second == NULL) return head->next;
		while (second->next!=NULL) {
			second = second -> next;
			first = first -> next;
		}
		first->next = first->next->next;
		return head;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

