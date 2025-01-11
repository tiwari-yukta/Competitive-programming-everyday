// GFG : https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

// My Code:

class Solution {
  public:

    void removeLoop(Node* head) {

      if (head == NULL)
            return ;
        Node* slow = head;
        Node* fast = head;
        Node* detect=head;
        int ans=0;
        while (fast && fast->next ) {
             slow = slow->next;
            fast = fast->next->next;
           
            if (slow == fast) {
                while(detect!=slow){
                    detect=detect->next;
                    slow=slow->next;
                }
              Node* temp = detect;
            while (temp->next != detect) {
                temp = temp->next;
            }
            temp->next = NULL;
            break;
        }
}
    }
};
