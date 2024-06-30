/* GFG Problem: Delete node in a Doubly Linked List */

/*
    Company Tags                : Amazon 
    GFG Link                    : https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1
*/


class Solution {
    public:
        Node* deleteNode(Node* head, int x) {
            
            struct Node *del=head;
            x=x-1;

            while(x--){
                del= del->next;
            }

            if(head== NULL || del==NULL){
                return NULL;
            }

            if(head==del){
                head=del->next;
            }

            if(del->next !=NULL){
                del->next->prev=del->prev;
            }

            if(del->prev !=NULL){
                del->prev->next=del->next;
            }

            free(del);

            return head;
        }
};

class Solution {
    public:
        Node* deleteNode(Node* head, int x) {
            if (head == NULL || x == 0) {
                return NULL;
            }

            if (x == 1) {
                Node* temp = head;
                head = head->next;
                if (head) {
                    head->prev = NULL;
                }
                free(temp);
                return head;
            }

            Node* del = head;
            x = x - 1;

            while (x-- && del->next) {
                del = del->next;
            }

            if (del->next == NULL) {
                return head;
            }

            if (del->next->next) {
                del->next = del->next->next;
                del->next->prev = del;
            } else {
                del->next = NULL;
            }

            free(del->next);
            return head;
        }
};
/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=U9bNULRjneU
*/