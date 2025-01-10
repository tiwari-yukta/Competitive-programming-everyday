// LeetCode : https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

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
    
    void solve(TreeNode* root, priority_queue<int, vector<int>, greater<int>>& pq) {
        if(root==NULL)return ;
        if (root->left) {
            pq.push(root->left->val);
            solve(root->left,pq );
        }
        if (root->right) {
            pq.push(root->right->val);
            solve(root->right,pq);
        }
    }
    int kthSmallest(TreeNode* root, int k) {

        if (root == NULL) {
            return 0;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(root->val);
        solve(root,pq);
       while(k!=1){
        pq.pop();
        k--;
       }
       return pq.top();
    }
};
