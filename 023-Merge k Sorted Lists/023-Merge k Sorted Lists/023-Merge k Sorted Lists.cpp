// 023-Merge k Sorted Lists.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <climits>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		if(lists.empty())   return nullptr;
		while (lists.size() > 1) {
			lists.push_back(mergeTwoLists(lists[0],lists[1]));
			lists.erase(lists.begin());
			lists.erase(lists.begin());
		}
		return lists.front();
    }

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode dummy(INT_MIN);
		ListNode *tail = &dummy;
		while(l1&&l2) {
			if (l1->val < l2->val) {
				tail->next = l1;
				l1 = l1->next;
			} else {
				tail->next = l2;
				l2 = l2->next;
			}
			tail = tail->next;
		}
		tail->next = l1? l1: l2;
		return dummy.next;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

