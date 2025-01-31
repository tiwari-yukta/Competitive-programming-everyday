// LeetCode: https://leetcode.com/problems/binary-tree-right-side-view/description/

// My Code:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public: 
  vector<int>ans;
   void lo(TreeNode* root){
    if(root==NULL){
        return ;
    }
   
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        int curr=0;
        for(int i=0;i<size;i++){
            TreeNode* temp=q.front();
            q.pop();
            
            if(temp->left){
                q.push(temp->left);
            }if(temp->right){
                q.push(temp->right);
            }
            curr=temp->val;
        }
        ans.push_back(curr);
    }
   }
    vector<int> rightSideView(TreeNode* root) {
      lo(root);
      return ans;  
    }
};
