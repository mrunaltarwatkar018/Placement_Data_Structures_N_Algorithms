/* GFG Problem: Rotate a Linked List */

/*
    Company Tags                : Accolite, Amazon, Microsoft, MakeMyTrip
    GFG Link                    : https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1
*/


class Solution {
public:
    // Function to rotate a linked list.
    Node* rotate(Node* head, int k) {
        // Your code here
        
        if(!head) return NULL;
        
        Node *temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=head;
        while(--k)
        head=head->next;
        
        Node *newHead=head->next;
        head->next=NULL;
        
        return newHead;
    }
};


























/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=dh2Z-gj6KJU
*/