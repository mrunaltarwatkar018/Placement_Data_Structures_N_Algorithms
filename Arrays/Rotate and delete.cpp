/* GFG Problem: Rotate and delete */

/*
    Company Tags                : 
    GFG Link                    : https://www.geeksforgeeks.org/problems/rotate-and-delete-1587115621/1
*/


    class Solution {
        public:
        int rotateDelete(vector<int> &arr) {
            // Your code here
            int n=arr.size();
            int k=1;
            while(n>1){
                arr.insert(arr.begin(),arr.back());
                arr.pop_back();
                if(k>n) arr.erase(arr.begin());
                else arr.erase(arr.end()-k);
                n=arr.size();
                k++;
            }
            return arr[0];
        }
    };