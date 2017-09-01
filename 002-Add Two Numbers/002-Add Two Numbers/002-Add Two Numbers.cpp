// 002-Add Two Numbers.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* result = NULL;
		ListNode* current = result;
        int carry = 0;
		while(l1!=NULL && l2!=NULL) {
			int temp = l1->val + l2->val + carry;
			int num = temp % 10;
			carry = temp / 10;
			if (result == NULL) {
				result = new ListNode(num);
				current = result;
			} else {
				current->next = new ListNode(num);
				current = current->next;
			}
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1 != NULL) {
			int temp = l1->val + carry;
			int num = temp % 10;
			carry = temp / 10;
			current->next = new ListNode(num);
			current = current->next;
			l1 = l1->next;
		}
		while (l2 != NULL) {
			int temp = l2->val + carry;
			int num = temp % 10;
			carry = temp / 10;
			current->next = new ListNode(num);
			current = current->next;
			l2 = l2->next;
		}
		if (carry != 0) {
			current->next = new ListNode(carry);
			current = current->next;
		}
		return result;
    }
};

int main() {
	ListNode l1_0(2);
	ListNode l1_1(4);
	ListNode l1_2(3);
	l1_0.next = &l1_1;
	l1_1.next = &l1_2;
	ListNode l2_0(5);
	ListNode l2_1(6);
	ListNode l2_2(4);
	l2_0.next = &l2_1;
	l2_1.next = &l2_2;
	ListNode* result = Solution().addTwoNumbers(&l1_0, &l2_0);
	while (result!=NULL) {
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;
	system("pause");
    return 0;
}

