/* GFG Problem: Add 1 to a Linked List Number */

/*
    Company Tags                : Amazon 
    GFG Link                    : https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
*/

class Solution {
    public:
    Node* reverse(Node* head){
        Node *prev=NULL,*cur=head,*next=NULL;
        while(cur){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
        
    }
    Node* addOne(Node* head) {
        
        head=reverse(head);
        int carry=1;
        Node* temp=head;
        Node* tail=NULL;
        while(temp && carry){
            if(temp->data==9) temp->data=0;
            else{
                temp->data=temp->data+1;
                carry=0;
            }
            tail=temp;
            temp=temp->next;
        }
        if(carry) tail->next=new Node(1);
        head=reverse(head);
        return head;
    }
};