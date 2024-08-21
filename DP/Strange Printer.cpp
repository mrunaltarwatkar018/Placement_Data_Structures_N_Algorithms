/* Leetcode Problem No.: 664. Strange Printer  */

/*
    Company Tags                : NetEase
    Leetcode Link               : https://leetcode.com/problems/strange-printer/
*/



/**************************************************************** C++ ****************************************************************/

//Approach-1 (Recursion + Memoization)
class Solution {
public:
    int n;
    vector<vector<int>> t;
    
    int solve(int l, int r, string& s){
        if(l == r)
            return 1;
        
        else if(l > r)
            return 0;
        
        if(t[l][r] != -1)
            return t[l][r];


        int i = l+1;
        while(i <= r && s[i] == s[l])
            i++;

        if(i == r+1)
            return 1;

        int normal = 1 + solve(i,r,s);

        int aage_ka = INT_MAX;

        for(int j = i; j <= r; j++){
            if(s[l] == s[j]){
                
                int x = solve(i,j-1,s) + solve(j,r,s);
                
                aage_ka = min(aage_ka, x);
            }
        }

        return t[l][r] = min(aage_ka, normal);
    }

    int strangePrinter(string s) {
        n = s.length() ;
        
        t.resize(n,vector<int>(n+1, -1));
        
        return solve(0, n-1, s);
    }
};






/**************************************************************** JAVA ****************************************************************/
class Solution {
    int n;
    int[][] t;

    int solve(int l, int r, String s) {
        if (l == r)
            return 1;

        else if (l > r)
            return 0;

        if (t[l][r] != -1)
            return t[l][r];

        int i = l + 1;
        while (i <= r && s.charAt(i) == s.charAt(l))
            i++;

        if (i == r + 1)
            return 1;

        int normal = 1 + solve(i, r, s);

        int aage_ka = Integer.MAX_VALUE;

        for (int j = i; j <= r; j++) {
            if (s.charAt(l) == s.charAt(j)) {

                int x = solve(i, j - 1, s) + solve(j, r, s);

                aage_ka = Math.min(aage_ka, x);
            }
        }

        return t[l][r] = Math.min(aage_ka, normal);
    }

    public int strangePrinter(String s) {
        n = s.length();

        t = new int[n][n + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++) {
                t[i][j] = -1;
            }
        }

        return solve(0, n - 1, s);
    }
}


/**************************************************************** PYTHON ****************************************************************/
class Solution(object):
    def strangePrinter(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        t = [[-1]*(n+1) for _ in range(n)]
        
        def solve(l, r, s):
            if l == r:
                return 1
            elif l > r:
                return 0
            elif t[l][r] != -1:
                return t[l][r]
            
            i = l + 1
            while i <= r and s[i] == s[l]:
                i += 1
            
            if i == r + 1:
                return 1
            
            normal = 1 + solve(i, r, s)
            
            aage_ka = float('inf')
            
            for j in range(i, r+1):
                if s[l] == s[j]:
                    x = solve(i, j-1, s) + solve(j, r, s)
                    aage_ka = min(aage_ka, x)
            
            t[l][r] = min(aage_ka, normal)
            return t[l][r]
        
        return solve(0, n-1, s)



/**************************************************************** PYTHON 3 ****************************************************************/
class Solution:
    def strangePrinter(self, s: str) -> int:
        n = len(s)
        t = [[-1]*(n+1) for _ in range(n)]
        
        def solve(l, r, s):
            if l == r:
                return 1
            elif l > r:
                return 0
            elif t[l][r] != -1:
                return t[l][r]
            
            i = l + 1
            while i <= r and s[i] == s[l]:
                i += 1
            
            if i == r + 1:
                return 1
            
            normal = 1 + solve(i, r, s)
            
            aage_ka = float('inf')
            
            for j in range(i, r+1):
                if s[l] == s[j]:
                    x = solve(i, j-1, s) + solve(j, r, s)
                    aage_ka = min(aage_ka, x)
            
            t[l][r] = min(aage_ka, normal)
            return t[l][r]
        
        return solve(0, n-1, s)