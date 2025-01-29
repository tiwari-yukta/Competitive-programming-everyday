// LeetCode: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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

   void rev(vector<vector<int>>&arr){
    int i=0;int j=arr.size()-1;
    while(i<=j){
        swap(arr[i++],arr[j--]);
    }
   }
    vector<vector<int>> ans;
    void lo(TreeNode* root) {
         if (root == NULL) {
            return;
        }
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left) {
                    q.push(temp->left);
                                     
                }
                if (temp->right) {
                    q.push(temp->right);
                                       
                }
                level.push_back(temp->val);
            }
            ans.push_back(level);
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        lo(root);
        rev(ans);
        return ans;
    }
};
