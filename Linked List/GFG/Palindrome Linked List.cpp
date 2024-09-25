/* GFG Problem: Palindrome Linked List */

/*
    Company Tags                : Accolite, Amazon, Microsoft, Snapdeal, MakeMyTrip, Adobe, Yodlee Infotech, KLA Tencor, Kritikal Solutions
    GFG Link                    : https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
*/


class Solution {
    public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        // Your code here
        //step 1 middle element
        Node* slow=head,*fast=head;
        while(fast && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        //slow=middle element
        //step2 reverse middle element ke baad;
        Node* prev=NULL,*curr=slow;
        while(curr){
            Node *NextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=NextNode;
        }
        //step 3 compare
        Node* first=head,*second=prev;
        while(second){
            if(first->data!=second->data) return false;
            first=first->next;
            second=second->next;
        }
        return true;
    }
};