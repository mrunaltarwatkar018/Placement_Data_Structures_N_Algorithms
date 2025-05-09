/* GFG Problem: Maximum Difference */

/*
    Company Tags                : 
    GFG Link                    : https://www.geeksforgeeks.org/problems/maximum-difference-1587115620/1
*/


class Solution {
    public:
    
    int findMaxDiff(vector<int> &arr) {

        stack<int>s1,s2;
        vector<int> v1(arr.size()),v2(arr.size());
        s1.push(0);
        s2.push(0);
        for(int i=0;i<arr.size();i++){
            while(!s1.empty() && s1.top()>= arr[i]){
                s1.pop();
            }
            v1[i]=s1.top();
            s1.push(arr[i]);
        }
        for(int i=arr.size()-1;i>=0;i--){
            while(!s2.empty() && s2.top()>= arr[i]){
                s2.pop();
            }
            v2[i]=s2.top();
            s2.push(arr[i]);
        }
        int ans=INT_MIN;
        for(int i=0;i<arr.size();i++){
            ans=max(ans,abs(v1[i] - v2[i]));
        }
        return ans;
    }
};