/* GFG Problem No.: Longest Common Substring   */

/*
    Company Tags                : Morgan Stanley, Amazon, Microsoft
    GFG Link                    : https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
*/

class Solution {
    public:
    int longestCommonSubstr(string str1, string str2) {
        
        int res=0;
        int n=str1.length(),m=str2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    if(res<dp[i][j]) res=dp[i][j];
                }
            }
        }
        return res;
    }
};

