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

int heightOf(TreeNode* root) {
	if (root == nullptr) return 0;

	return 1 + max(heightOf(root->left), heightOf(root->right));
}

int diameterOfBinaryTree(TreeNode* root) {
	if (root == nullptr) return 0;
	int maxIfPathIsInThis = heightOf(root->left) + heightOf(root->right);
    
	int maxDiameterOfChild = max(diameterOfBinaryTree(root->left),
								 diameterOfBinaryTree(root->right));

	return max(maxIfPathIsInThis, maxDiameterOfChild);
}
