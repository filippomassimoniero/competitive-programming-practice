#include "bits/stdc++.h"

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
	public:
	bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> seen;

        while(head != nullptr) {
            seen.insert(head);
            if(seen.find(head->next) != seen.end()) {
                return false;
            }
            head = head->next;
        }
        return false;
    }
};