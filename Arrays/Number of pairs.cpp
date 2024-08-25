/* GFG Problem: Number of pairs */

/*
    Company Tags                : 
    GFG Link                    : https://www.geeksforgeeks.org/problems/number-of-pairs-1587115620/1
*/


class Solution {
public:
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        // Your Code goes here.
        long long ans=0;
        
        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());
        
        for(auto i:arr){
            if(i!=1){ // do not consider 1 in arr
                ans+=brr.end()-lower_bound(brr.begin(),brr.end(),i+1);
            } 
        }
        for(auto i:brr){
            if(i==1){ // consider all bigger elements in arr
                ans+=arr.end()-lower_bound(arr.begin(),arr.end(),i+1);
            } 
            else break;
        }
        //Special Cases
        ans+=count(arr.begin(),arr.end(),3)*count(brr.begin(),brr.end(),2);
        ans-=count(arr.begin(),arr.end(),2)*count(brr.begin(),brr.end(),3);
        ans-=count(arr.begin(),arr.end(),2)*count(brr.begin(),brr.end(),4);
        return ans;   
    }
};