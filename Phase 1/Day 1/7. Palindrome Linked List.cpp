// LeetCode: https://leetcode.com/problems/palindrome-linked-list/description/

// My Code:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        ListNode* value=head;
             stack <int> st;
        while(value!=NULL){
            st.push(value->val);
            value=value->next;
        } 
     while(!st.empty()){
        if(st.top()!=temp->val){
            return false;
        }
        st.pop();
        temp=temp->next;
     }
     return true;
    }
};
