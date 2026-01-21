#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right)
		: val(x), left(left), right(right) {}
};
class Solution {
	public:
	bool isValidBST(TreeNode* root) {
		if (!root) return true;
        bool isValid = true;
        if((root->left != nullptr))
            isValid = isValidBST(root->left) && root->val > getMax(root->left);
        if((root->right != nullptr))
            isValid = isValid && isValidBST(root->right) && root->val < getMin(root->right);
        
        return isValid;
    }

    int getMin(TreeNode* root) {
        if (!root) return INT_MAX;

        int minimum = root->val;
        
        minimum = min(minimum, getMin(root->left));
        minimum = min(minimum, getMin(root->right));
        return minimum;
    }

    int getMax(TreeNode* root) {
        if (!root) return INT_MIN;

        int maximum = root->val;

        maximum = max(maximum, getMax(root->left));
        maximum = max(maximum, getMax(root->right));
        return maximum;
    }
};