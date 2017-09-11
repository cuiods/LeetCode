// 141-Linked List Cycle.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
		ListNode* first = head;
		ListNode* second = head;
		if (head == NULL || head->next==NULL || head->next->next==NULL) return false;
		while (second->next && second->next->next) {
			first = first->next;
			second = second->next->next;
			if (first == second) return true;
		}
		return false;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

