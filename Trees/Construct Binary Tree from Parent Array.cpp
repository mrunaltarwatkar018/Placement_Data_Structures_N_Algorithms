/*    GFG Problem: Construct Binary Tree from Parent Array    */

/*
    Company Tags                : Amazon, Microsoft, Snapdeal
    GFG Qn Link                 : https://www.geeksforgeeks.org/problems/construct-binary-tree-from-parent-array/1
*/

    class Solution {
    public:
        // Function to construct binary tree from parent array.
        Node *createTree(vector<int> parent) {
            
            int n=parent.size();
            Node* nodes[n], *root;
            for(int i=0;i<n;i++){
                nodes[i]=new Node(i);
            }
            for(int i=0;i<n;i++){
                if(parent[i]==-1){
                    root=nodes[i];
                }
                else{
                    if(nodes[parent[i]]-> left== NULL){
                        nodes[parent[i]]-> left=nodes[i];
                    }
                    else{
                        nodes[parent[i]]-> right=nodes[i];
                    }
                
            }
            }
            return root;
        }
    };