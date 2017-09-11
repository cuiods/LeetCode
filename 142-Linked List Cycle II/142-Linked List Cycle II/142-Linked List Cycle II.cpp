// 142-Linked List Cycle II.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
		if (head == NULL) return NULL;
		ListNode* first = head;
		ListNode* second = head;
		bool hasCircle = false;
		while(second->next && second->next->next) {
			first = first->next;
			second = second->next->next;
			if (first == second) {
				hasCircle = true;
				break;
			}
		}
		if (!hasCircle) return NULL;
		first = head;
		while(!(first==second)) {
			first = first->next;
			second = second->next;
		}
		return first;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

