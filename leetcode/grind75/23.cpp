#include "bits/stdc++.h"

using namespace std;

// should be the height of the tree, right?

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right)
		: val(x), left(left), right(right) {}
};

int maxDepth(TreeNode* root) {
	if (root == nullptr) return 0;

	return 1 + max(maxDepth(root->left), maxDepth(root->right));
}