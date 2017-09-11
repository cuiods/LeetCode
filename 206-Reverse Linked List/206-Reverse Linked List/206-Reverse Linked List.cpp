// 206-Reverse Linked List.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
		ListNode* first = head;
		ListNode* second = head->next;
		head->next = NULL;
		while(second!=NULL) {
			ListNode* temp = second->next;
			second->next = first;
			first = second;
			second = temp;
		}
		return first;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

