// LeetCode: https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

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
    int solve(TreeNode* root, int curr) {

       if(!root) return 0;
       curr = curr * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            return curr;
        }
          
        int leftSum = solve(root->left, curr);
        int rightSum = solve(root->right, curr);

        return rightSum + leftSum;
    }
    int sumNumbers(TreeNode* root) {
        return solve(root,0);
    }
};
