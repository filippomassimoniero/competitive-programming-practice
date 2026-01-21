#include "bits/stdc++.h"

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
	public:
	bool findMinElement(ListNode* list1, ListNode* list2) {
		bool firstOrSecond =
			false;	// true if i take from first, false from second
		int x = INT_MAX;
		if (list1 != nullptr) {
			firstOrSecond = true;
			x = list1->val;
		}

		if (list2 != nullptr && list2->val < x) {
			x = list2->val;
			firstOrSecond = false;
		}

		return firstOrSecond;
	}
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode result(0);
		ListNode* prev = &result;

		while (list1 != nullptr && list2 != nullptr) {
			// Get smallest value
			bool firstOrSecond = findMinElement(list1, list2);

			if (firstOrSecond) {
				cout << "Moving first list" << endl;
                prev->next = list1;
				list1 = list1->next;

			} else {
				cout << "Moving second list" << endl;
                prev->next = list2;

				list2 = list2->next;
			}
            prev = prev->next;
        }

		if (list1 != nullptr) {
			prev->next = list1;
		} else if (list2 != nullptr) {
			prev->next = list2;
		}

		return result.next;
	}
};