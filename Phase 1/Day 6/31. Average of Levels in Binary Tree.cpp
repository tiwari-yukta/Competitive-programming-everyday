// LeetCode: https://leetcode.com/problems/average-of-levels-in-binary-tree/

// My Code:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void lo(TreeNode* root, vector<double>& ans) {

        if (root == NULL) {
            return;
        }
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int n = q.size();
            double sum = 0;
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
                sum += temp->val;
            }
            ans.push_back(sum/n);
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        lo(root, ans);
        return ans;
    }
};
