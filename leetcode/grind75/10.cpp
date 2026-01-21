#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
	public:
    bool contains(TreeNode* root, TreeNode* target) {
        if(root == nullptr) return false;
        if(root == target) {
            return true;
        }
        bool foundInLeft = contains(root->left, target);
        bool foundInRight = contains(root->right, target);

        return foundInLeft || foundInRight;

    }
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        cout << "Calling LCA with " << root-> val << endl;
        // Testing with left
        if(root == p || root == q) return root;
        
        bool contains_p_left = contains(root->left, p); // If it is not in the left, it MUST be in the right
        bool contains_q_left = contains(root->left, q);

        cout << contains_p_left << contains_q_left << endl;

        // If both in the same part of the tree, then root is not the LCA
        if(contains_p_left && contains_q_left) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if(!contains_p_left && ! contains_q_left) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;

    }
};