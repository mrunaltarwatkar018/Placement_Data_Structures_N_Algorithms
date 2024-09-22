/* GFG Problem: Longest Prefix Suffix */

/*
    Company Tags                : Accolite, Amazon, Microsof, tMakeMyTrip
    GFG Link                    : https://www.geeksforgeeks.org/problems/longest-prefix-suffix2527/1
*/



class Solution {
    public:
    int lps(string str) {
        // Your code goes here
        int n=str.length();
        int p=0,s=1,pos=1,count=0;
        while(p<n && s<n){
            if(str[p]==str[s]){
                p++;
                s++;
                count++;
            }
            else{
                p=0;
                pos++;
                s=pos;
                count=0;
            }
        }
        return count;
    }
};
