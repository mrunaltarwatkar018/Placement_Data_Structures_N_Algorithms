/* GFG Problem: Mirror Tree */

/*
    Company Tags                : Paytm, VM Ware, Morgan Stanley, Accolite, Amazon, Microsoft, Samsung, Snapdeal, Ola Cabs, Walmart, Goldman Sachs, Adobe, Google, SAP Labs, Myntra, Belzabar, eBay. Prop Tiger 
    GFG Link                    : https://www.geeksforgeeks.org/problems/mirror-tree/1
*/

class Solution {
    public:
    void mirror(Node* node) {
        if(!node) return;
        swap(node->left,node->right);
        mirror(node->left);
        mirror(node->right);
    }
};