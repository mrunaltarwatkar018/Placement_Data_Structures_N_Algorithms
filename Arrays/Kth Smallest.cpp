/* GFG Problem: Kth Smallest */

/*
    Company Tags                : VMWare, Accolite, Amazon, Microsoft, Snapdeal, Hike, Adobe, Google, ABCO, Cisco
    GFG Link                    : https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1
*/

// User function template for C++
class Solution {
    public:
    
    int kthSmallest(vector<int> &arr, int k) {
        // arr : given array
        // k : find kth smallest element and return using this function
        map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(auto i:mp){
            k--;
            if(k==0) return i.first;
        }
        return 0;
    }
};