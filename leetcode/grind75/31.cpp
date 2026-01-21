#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};
vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;

    queue<pair<TreeNode*, int>> q;
    if(!root) return res;
    q.push({root, 0});

    while(!q.empty()) {
        auto [r, l] = q.front();
        q.pop();

        if(l >= res.size()) {
            res.push_back(vector<int>());
        }
        res[l].push_back(r->val);

        if(r->left) q.push({r->left, l + 1});
        if(r->right) q.push({r->right, l + 1});
    }

    return res;
}