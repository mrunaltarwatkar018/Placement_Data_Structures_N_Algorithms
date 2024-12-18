/* GFG Problem: Clone a linked list with next and random pointer */

/*
    Company Tags                : Flipkar, tMorgan Stanley, Amazon, Microsoft, OYO Rooms, Snapdeal, D-E-Shaw, MakeMyTrip, Ola Cabs, Walmart, Adobe, BankBazaar
    GFG Link                    : https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1
*/


class Solution {
    public:
    Node *copyList(Node *head) {
        // Write your code here
        //STEP 1 input list ki nodes ke beech me op list ki node hume rkhni hai mapping create
        if(head==NULL) return head;
        Node * temp=head;
        while(temp){
            Node *n=new Node(temp->data);
            n->next=temp->next;
            temp->next=n;
            temp=n->next;
        }
        //STEP 2 random pointer assing krde clone ll me
        temp=head;
        Node *head2=temp->next;
        while(temp!=NULL){
            if(temp->random==NULL){
                temp->next->random=NULL;
            }
            else
            temp->next->random=temp->random->next;
            temp=temp->next->next;
        }
        //STEP 3 op list return krde
        temp = head;
        while(temp!=NULL){
            Node * temp2=temp->next;
            temp->next=temp2->next;
            if(temp2->next)
            temp2->next=temp2->next->next;
            temp=temp->next;
        }
        return head2;
    }
};