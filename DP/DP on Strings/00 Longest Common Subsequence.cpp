/* Leetcode Problem No.: 1143. Longest Common Subsequence  */

/*
    Company Tags                : Microsoft, Amazon, FactSet, Hike, Citrix, MakeMyTrip, Paytm, VMWare
    Leetcode Link               : https://leetcode.com/problems/longest-common-subsequence/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Recursion ) - TLE - 17 / 47 testcases passed
// T.C : O(2^(m+n))
// S.C : O(m+n)
class Solution {
public:  
    int m, n;

    int solve(string & s1, string & s2, int i, int j) {
        if (i >= m || j >= n) {
            return 0;
        }
        
        if (s1[i] == s2[j]) {
            return 1 + solve(s1, s2, i + 1, j + 1);
        }

        return max(solve(s1, s2, i+1, j), solve(s1, s2, i, j+1));
    }

    int longestCommonSubsequence(string s1, string s2) {
        m = s1.length();
        n = s2.length();
        
        return solve(s1, s2, 0, 0);
    }
};


// Approach-2 (Recursion + Memoization)
// T.C : O(m*n)
// S.C : O(m*n)
class Solution {
public:
    int m, n;
    int t[1001][1001];   // 2 dimensional dp array

    int solve(string & s1, string & s2, int i, int j) {
        if (i >= m || j >= n) {
            return 0;
        }

        if(t[i][j] != -1) {
            return t[i][j];
        }
        
        if (s1[i] == s2[j]) {
            return t[i][j] = 1 + solve(s1, s2, i + 1, j + 1);
        }

        return t[i][j] = max(solve(s1, s2, i+1, j), solve(s1, s2, i, j+1));
    }

    int longestCommonSubsequence(string s1, string s2) {
        m = s1.length();
        n = s2.length();
        memset(t, -1, sizeof(t));
        return solve(s1, s2, 0, 0);
    }
};

// or below to top 
class Solution {
public:
    int t[1001][1001];
    int LCS(string& s1, string& s2, int m, int n) {
        if(m == 0 || n == 0)
            return t[m][n] = 0;
        
        if(t[m][n] != -1)
            return t[m][n];
        
        if(s1[m-1] == s2[n-1])
            return t[m][n] = 1 + LCS(s1, s2, m-1, n-1);
        
        return t[m][n] = max(LCS(s1, s2, m, n-1), LCS(s1, s2, m-1, n));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        memset(t, -1, sizeof(t));
        
        return LCS(text1, text2, m, n);
    }
};


// Approach-3 (Bottom Up)
// T.C : O(m*n)
// S.C : O(m*n)
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> t(m+1, vector<int>(n+1));

        // first row and first col will be zero always
        for (int row = 0; row < m+1; row++) {
            t[row][0] = 0;
        }
        for (int col = 0; col < n+1; col++) {
            t[0][col] = 0;
        }

        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (s1[i-1] == s2[j - 1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                } else {
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }

        return t[m][n];

    }
};


// or
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        vector<vector<int>> t(m+1, vector<int>(n+1));
        
        for(int i = 0; i<m+1; i++) {
            for(int j = 0; j<n+1; j++) {
                if(i == 0 || j == 0)
                    t[i][j] = 0;
                else if(text1[i-1] == text2[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                else
                    t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
        
        return t[m][n];
    }
};

//Approach-4 (Bottom Up space optmized)
/*
Since, in bottm up approach, we are using results of only two rows, t[i] and t[i-1]. So, we can take only two rows.
*/
//T.C : O(m*n)
//S.C : O(n)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        vector<vector<int>> t(2, vector<int>(n+1));
        
        for(int i = 0; i<m+1; i++) {
            for(int j = 0; j<n+1; j++) {
                if(i == 0 || j == 0)
                    t[i%2][j] = 0;
                else if(text1[i-1] == text2[j-1])
                    t[i%2][j] = 1 + t[(i+1)%2][j-1];
                else
                    t[i%2][j] = max(t[i%2][j-1], t[(i+1)%2][j]);
            }
        }
        
        return t[m%2][n];
    }
};




/**************************************************************** JAVA ****************************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(m*n)
//S.C : O(m*n)
public class Solution {
    private int[][] t;

    public int LCS(String s1, String s2, int m, int n) {
        if (m == 0 || n == 0)
            return t[m][n] = 0;

        if (t[m][n] != -1)
            return t[m][n];

        if (s1.charAt(m - 1) == s2.charAt(n - 1))
            return t[m][n] = 1 + LCS(s1, s2, m - 1, n - 1);

        return t[m][n] = Math.max(LCS(s1, s2, m, n - 1), LCS(s1, s2, m - 1, n));
    }

    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length();
        int n = text2.length();

        t = new int[m + 1][n + 1];
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }

        return LCS(text1, text2, m, n);
    }
}


//Approach-2 (Bottom Up)
//T.C : O(m*n)
//S.C : O(m*n)
public class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length();
        int n = text2.length();
        
        int[][] t = new int[m + 1][n + 1];
        
        for (int i = 0; i < m + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                if (i == 0 || j == 0) {
                    t[i][j] = 0;
                } else if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    t[i][j] = 1 + t[i - 1][j - 1];
                } else {
                    t[i][j] = Math.max(t[i][j - 1], t[i - 1][j]);
                }
            }
        }
        
        return t[m][n];
    }
}



//Approach-3 (Bottom Up space optmized)
/*
Since, in bottm up approach, we are using results of only two rows, t[i] and t[i-1]. So, we can take only two rows.
*/
//T.C : O(m*n)
//S.C : O(n)
public class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length();
        int n = text2.length();
        
        int[][] t = new int[2][n+1];
        
        for (int i = 0; i < m + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                if (i == 0 || j == 0) {
                    t[i % 2][j] = 0;
                } else if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    t[i % 2][j] = 1 + t[(i + 1) % 2][j - 1];
                } else {
                    t[i % 2][j] = Math.max(t[i % 2][j - 1], t[(i + 1) % 2][j]);
                }
            }
        }
        
        return t[m % 2][n];
    }
}