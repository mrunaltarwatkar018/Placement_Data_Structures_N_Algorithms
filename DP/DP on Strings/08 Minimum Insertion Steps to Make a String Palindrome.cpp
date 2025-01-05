/* Leetcode Problem No.: 1312. Minimum Insertion Steps to Make a String Palindrome  */

/*
    Company Tags                : Google, Amazon, Microsoft, Airtel
    Leetcode Link               : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
*/

/*
    Approaches Summary :
        Initialization:

        Initialize a 2D vector dp where dp[i][j] represents the minimum number of insertions 
        required to make the substring s[i..j] a palindrome. Initialize all values to 0.

        Base Cases:

            If the substring length L is 2 or more, iterate over all possible substring lengths L from 2 to n.
            For each substring starting index i, calculate the end index j as i + L - 1.
            Palindrome Check:

            If s[i] equals s[j], then s[i..j] is already a palindrome and no insertions are needed beyond what's 
            already considered for s[i+1..j-1]. Therefore, set dp[i][j] = dp[i + 1][j - 1].

        Insertion Calculation:

            If s[i] does not equal s[j], then to make s[i..j] a palindrome, calculate the minimum 
            insertions required. This involves either:
            Inserting the character at j before i (i.e., making s[i..j-1] a palindrome), or
            Inserting the character at i after j (i.e., making s[i+1..j] a palindrome).
            Update dp[i][j] to 1 + min(dp[i + 1][j], dp[i][j - 1]), representing the minimum of the 
            two insertion scenarios plus one.

        Result:
            The result for the entire string s is stored in dp[0][n - 1], where n is the length of s. 
            This represents the minimum number of insertions needed to make the entire string s a palindrome.

        Time Complexity:
            The nested loops iterate over all substrings of s, resulting in a time complexity of O(n^2), where n is 
            the length of the string s.
            Each substring length is processed in constant time operations, ensuring efficient computation.

        Space Complexity:
        The space complexity is also O(n^2) due to the use of the 2D vector dp to store results for all substrings of s.
*/

/************************************************************ C++ ************************************************************/
// Approach-1 (Recur Using Straight Forward Pallindromic Property) - TLE for large testcases 12 / 58 testcases passed
// T.C : O(2^n)
// S.C : O(2^n)
class Solution {
public:
    int n;
    int solve(string &s, int i, int j) {
        if (i >= j) {
            return 0;
        }

        if (s[i] == s[j]) {
            return solve(s, i + 1, j - 1);
        } 
        return 1 + min(solve(s, i, j - 1), solve(s, i + 1, j));  
    }
    
    int minInsertions(string s) {
        n = s.length();
        return solve(s, 0, n-1);
    }
};

// or
class Solution {
    public:
    int solve(string &s, int l, int r) {
        if(l >= r)
            return 0;
        if(s[l] == s[r])
            return solve(s, l+1, r-1);
        return 1 + min(solve(s, l+1, r), solve(s, l, r-1));
    }
    int minInsertions(string s) {
        int n = s.size();
        return solve(s, 0, n-1);
    }
};


// Approach-2 (Recur + Memo - Using Straight Forward Palindromic  Property)
// T.C : O(n*n)
// S.C : O(n*n)
class Solution {
public:
    int n;
    int t[501][501];
    int solve(string &s, int i, int j) {
        if (i >= j) {
            return 0;
        }

        if (t[i][j] != -1) {
            return t[i][j];
        }

        if (s[i] == s[j]) {
            return t[i][j] = solve(s, i + 1, j - 1);
        } 
        return t[i][j] = 1 + min(solve(s, i, j - 1), solve(s, i + 1, j));  
    }
    
    int minInsertions(string s) {
        n = s.length();
        memset(t, -1, sizeof(t));
        return solve(s, 0, n-1);
    }
};

// or
class Solution {
public:
    int t[501][501];
    int solve(int i, int j, string &s) {

        if(i >= j)
            return 0;
        
        if(t[i][j] != -1)
            return t[i][j];
        
        if(s[i] == s[j])
            return t[i][j] = solve(i+1, j-1, s);
        
        return t[i][j] = 1 + min(solve(i, j-1, s), solve(i+1, j, s));
        
    }
    
    int minInsertions(string s) {
        int n = s.length();
        
        memset(t, -1, sizeof(t));
        
        return solve(0, n-1, s);
    }
};


// Approach-3 (Bottom Up - Using my favourite Palindrome Blue Print)
// T.C : O(n*n)
// S.C : O(n*n)

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> t(n, vector<int> (n, 0));
        //State : t[i][j] = min insertion to make s[i..j] a palindrome

        // t[0][0], t[1][1], ............., t[n-1][n-1] = 0
        // for (int i = 0; i < n; i++) {
        //     t[i][i] = 0;
        // }

        // but by default in 2d dp vector array filled by 0 in all cells

        for (int L = 2; L <= n; L++) {
            for (int i = 0; i < n - L + 1; i++) {
                int j = i + L - 1;
                if (s[i] == s[j]) { // no need to insert any character
                    t[i][j] = t[i+1][j-1];
                } else { 
                    t[i][j] = 1 + min(t[i][j-1], t[i+1][j]);
                }
            }
        }
        
        return t[0][n-1]; // t[i][j] =  s[i .... j] i.e., s[0 .... n - 1]
    }
};

// or
class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        //State : dp[i][j] = min insertion to make s[i..j] a palindrome
        
        for (int L = 2; L <= n; L++) {
            for (int i = 0; i < n - L + 1; i++) {
                int j = i + L - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[0][n - 1];
    }
};

//Approach-4 (Using LCS)
//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
public:
    int t[501][501];
    
    int LCS(string& s1, string& s2, int m, int n) {
        if(m == 0 || n == 0)
            return t[m][n] = 0;
        
        if(t[m][n] != -1)
            return t[m][n];
        
        if(s1[m-1] == s2[n-1])
            return t[m][n] = 1 + LCS(s1, s2, m-1, n-1);
        
        return t[m][n] = max(LCS(s1, s2, m, n-1), LCS(s1, s2, m-1, n));
    }
    
    int minInsertions(string s) {
        int m = s.length();
        
        memset(t, -1, sizeof(t));
        string temp = s;
        reverse(begin(temp), end(temp));
        
        int lcs_length = LCS(s, temp, m, m);
        
        return m - lcs_length;
    }
};





/************************************************************ JAVA ************************************************************/
//Approach-1 (Recur + Memo - Using Straight Forward Pallindromic Property)
//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
    private int[][] t;

    private int solve(int i, int j, String s) {
        if (i >= j)
            return 0;

        if (t[i][j] != -1)
            return t[i][j];

        if (s.charAt(i) == s.charAt(j))
            return t[i][j] = solve(i + 1, j - 1, s);

        return t[i][j] = 1 + Math.min(solve(i, j - 1, s), solve(i + 1, j, s));
    }

    public int minInsertions(String s) {
        int n = s.length();
        t = new int[n][n];

        for (int[] row : t)
            Arrays.fill(row, -1);

        return solve(0, n - 1, s);
    }
}




//Approach-2 (Bottom Up - Using my favourite Palindrome Blue Print)
//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
    public int minInsertions(String s) {
        int n = s.length();
        int[][] dp = new int[n][n];
        // State: dp[i][j] = min insertion to make s[i..j] a palindrome
        
        for (int L = 2; L <= n; L++) {
            for (int i = 0; i < n - L + 1; i++) {
                int j = i + L - 1;
                if (s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = 1 + Math.min(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[0][n - 1];
    }
}




//Approach-3 (Using LCS)
//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
    private int[][] t;

    private int LCS(String s1, String s2, int m, int n) {
        if (m == 0 || n == 0) {
            return t[m][n] = 0;
        }

        if (t[m][n] != -1) {
            return t[m][n];
        }

        if (s1.charAt(m - 1) == s2.charAt(n - 1)) {
            return t[m][n] = 1 + LCS(s1, s2, m - 1, n - 1);
        }

        return t[m][n] = Math.max(LCS(s1, s2, m, n - 1), LCS(s1, s2, m - 1, n));
    }

    public int minInsertions(String s) {
        int m = s.length();
        t = new int[m + 1][m + 1];
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }

        String temp = new StringBuilder(s).reverse().toString();
        int lcs_length = LCS(s, temp, m, m);

        return m - lcs_length;
    }
}