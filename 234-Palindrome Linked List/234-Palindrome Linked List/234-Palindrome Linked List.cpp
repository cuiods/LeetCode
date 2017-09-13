// 234-Palindrome Linked List.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
		if (head == NULL || head->next == NULL) return true;
		ListNode *slow = head;
		ListNode *fast = head;
		while(fast!=NULL && fast->next!=NULL) {
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode* second = reverseList(slow);
		ListNode* first = head;
		while(second!=NULL && first!=NULL) {
			if (second->val != first->val) return false;
			second = second->next;
			first = first->next;
		}
		return true;
    }

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
	ListNode first(1);
	ListNode second(1);
	first.next = &second;
	Solution().isPalindrome(&first);
	return 0;
}

