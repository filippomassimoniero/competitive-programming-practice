#include "bits/stdc++.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
    ListNode* copy = head;

    int l = 0;

    while(head != nullptr) {
        l++;
        head = head->next;
    }

    for (int i = 0; i < l/2; i++) {
        copy = copy->next;
    }
    return copy;
    
}