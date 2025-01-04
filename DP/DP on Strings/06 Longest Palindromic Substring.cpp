/* Leetcode Problem No.: 5. Longest Palindromic Substring  */

/*
    Company Tags             : Accolite, Amazon, Groupon, MakeMyTrip, Microsoft, Qualcomm, Samsung, Visa, Walmart, Zoho
    Leetcode Link            : https://leetcode.com/problems/longest-palindromic-substring/
*/

/****************************************** C++ ******************************************/
// Approach 1 - Recursion
// T.C : O(n^3)
// S.C : O(n^2)
class Solution {
public:

    bool solve(string &s, int i, int j) {
        if (i >= j) {
            return true;
        }

        if (s[i] == s[j]) {
            return solve(s, i+1, j - 1);
        }
        return false;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        int maxlen = INT_MIN;
        int startingIndex = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                
                if(solve(s, i, j)) {
                    if(j-i+1 > maxlen){
                        maxlen = j-i+1;
                        startingIndex = i;
                    }
                }
                
            }
        }

        return s.substr(startingIndex, maxlen);
    }
};

// or  (Just to make it more readable)
class Solution {
public:
    bool solve(string &s, int l, int r){
        if(l >= r) 
            return 1;

        if(s[l] == s[r]) {
            return solve(s, l+1, r-1);
        }

        return false;
    }
    
    string longestPalindrome(string s) {
        int n = s.length();
        
        int maxlen = INT_MIN;
        int startingIndex = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                
                if(solve(s, i, j)) {
                    if(j-i+1 > maxlen){
                        startingIndex = i;
                        maxlen = j-i+1;
                    }
                }
                
            }
        }

        return s.substr(startingIndex, maxlen);
    }
};


// Approach 2 - Recursion + Memoization
// Memoization will help reduce time complexity for cases like - "aaaaaaaaa"
// T.C : O(n^2) - Because the AMortized Time Complexity of solve() will become 1 due to memoization.
// S.C : O(n^2)
class Solution {
public:
    int t[1001][1001];
    bool solve(string &s, int i, int j) {
        if (i >= j) {
            return 1; // 1 = true;
        }

        if (t[i][j] != -1) {
            return t[i][j];
        }

        if (s[i] == s[j]) {
            return t[i][j] = solve(s, i+1, j - 1);
        }
        return t[i][j] = 0; // 0 = false
    }

    string longestPalindrome(string s) {
        int n = s.length();
        int maxlen = INT_MIN;
        int startingIndex = 0;
        memset(t, -1, sizeof(t));

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                
                if(solve(s, i, j)) {
                    if(j-i+1 > maxlen){
                        maxlen = j-i+1;
                        startingIndex = i;
                    }
                }
                
            }
        }

        return s.substr(startingIndex, maxlen);
    }
};

// or
class Solution {
public:
    int t[1001][1001];
    
    bool solve(string &s, int l, int r){
        if(l >= r) 
            return 1;

        if(t[l][r] != -1){
            return t[l][r];
        }

        if(s[l] == s[r]) {
            return t[l][r] = solve(s, l+1, r-1);
        }

        return t[l][r] = false;
    }
    
    string longestPalindrome(string s) {
        int n = s.length();
        
        int maxlen = INT_MIN;
        int startingIndex = 0;
        memset(t, -1, sizeof(t));

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                
                if(solve(s, i, j)) {
                    if(j-i+1 > maxlen){
                        startingIndex = i;
                        maxlen = j-i+1;
                    }
                }
                
            }
        }

        return s.substr(startingIndex, maxlen);
    }
};


//Approach 3 - Looping simply in solve()
//T.C : O(n^3)
class Solution {
public:
    bool solve(string &s, int l, int r){
        
        while(l <= r) {
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        
        return true;
    }
    
    string longestPalindrome(string s) {
        int n = s.length();
        
        int maxlen = INT_MIN;
        int startingIndex = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                
                if(solve(s, i, j)) {
                    if(j-i+1 > maxlen){
                        startingIndex = i;
                        maxlen = j-i+1;
                    }
                }
                
            }
        }

        return s.substr(startingIndex, maxlen);
    }
};

// Approach 3 - Using Bottom Up (Elaborated for simplicity) - My favourite BluePrint for solving palindromic DP problems
// T.C : O(n^2)
// S.C : O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxL = 0;
        int index = 0;
        vector<vector<bool>> t(n, vector<bool>(n)); // O(n*n)
        // state defination : t[i][j] = true if s[i:j] is palindrome, false if s[i:j] is not a palindrome

        // t[0][0] = true, t[1][1] = true and so on for all diagonal elements
        for (int i = 0; i < n; i++) {
            t[i][i] = true;
            maxL = 1;
        }

        // overall time complexity : O(n^2)
        for (int L = 2; L <= n; L++) { // O(L) i.e., O(n)
            for (int i = 0; i < n - L + 1; i++) { // O(L) i.e., O(n)
                int j = i + L - 1;

                if (s[i] == s[j] && L == 2) {
                    t[i][j] = true;
                    maxL = 2;
                    index = i;
                } else if (s[i] == s[j] && t[i+1][j-1] == true) {
                    t[i][j] = true;
                    if(j-i+1 > maxL) {
                        maxL = j-i+1;
                        index = i;
                    }
                } else {
                    t[i][j] = false; // not a palindrome
                }
            }
        }
        return s.substr(index, maxL); // T.C. : O(n)
    }
};

// or (Just to make it more readable)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        
        int maxL  = 0;
        int index = 0;
        
        vector<vector<bool>> t(n, vector<bool>(n));
        //t[i][j] = lps in s[i...j]
        
        maxL = 1; //every letter is a substring and pallindrome as well
        for(int i = 0; i<n; i++) {
            t[i][i] = true;
            /*
                s[0..0] = pallindrome
                s[1..1] = pallindrome
                s[2..2] = pallindrome
                .
                .
                .
            */
        }
        
        for(int L = 2; L<=n; L++) {
            for(int i = 0; i<n-L+1; i++) {
                int j = i + L - 1;
                
                if(s[i] == s[j] && L == 2) {
                    t[i][j] = true;
                    maxL = 2;
                    index = i;
                } else if (s[i] == s[j] && t[i+1][j-1] == true) {
                    t[i][j] = true;
                    if(j-i+1 > maxL) {
                        maxL = j-i+1;
                        index = i;
                    }
                } else {
                    t[i][j] = false;
                }
                
            }    
        }
        
        
        return s.substr(index, maxL);
    }
};


//Approach 4 :  (Simplifiying Approach-3 above)
//Simplified solution
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n, false));
        int maxL = 1;
        int start = 0;
        
        for(int i = 0; i<n; i++)
            t[i][i] = true;

        
        for(int L = 2; L<=n; L++) {
            for(int i = 0; i<n-L+1; i++) {
                int j = i + L - 1;
                
                if(s[i] == s[j] && (t[i+1][j-1] || L == 2)) {
                    t[i][j] = true;
                    if(L > maxL) {
                        maxL = L;
                        start = i;
                    }
                }
            }
        }
        
        return s.substr(start, maxL);
    }
};


//Approach-5 (O(n) Approach) - Coming Soooon.


/****************************************** JAVA ******************************************/
//Approach 1 - Recursion + Memoization
//T.C : O(n^2) - Because the AMortized Time Complexity of solve() will become 1 due to memoization.
//S.C : O(n^2)
public class Solution {
    private int[][] t;

    public String longestPalindrome(String s) {
        int n = s.length();
        int maxlen = Integer.MIN_VALUE;
        int startingIndex = 0;
        t = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(t[i], -1);
        }

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(s, i, j) && j - i + 1 > maxlen) {
                    startingIndex = i;
                    maxlen = j - i + 1;
                }
            }
        }

        return s.substring(startingIndex, startingIndex + maxlen);
    }

    private boolean solve(String s, int l, int r) {
        if (l >= r) {
            return true;
        }

        if (t[l][r] != -1) {
            return t[l][r] == 1;
        }

        if (s.charAt(l) == s.charAt(r)) {
            t[l][r] = solve(s, l + 1, r - 1) ? 1 : 0;
        } else {
            t[l][r] = 0;
        }

        return t[l][r] == 1;
    }
}


//Approach 2 - Looping simply in solve()
//T.C : O(n^3)
public class Solution {
    private boolean solve(String s, int l, int r) {
        while (l <= r) {
            if (s.charAt(l) != s.charAt(r))
                return false;
            l++;
            r--;
        }
        return true;
    }

    public String longestPalindrome(String s) {
        int n = s.length();
        int maxlen = Integer.MIN_VALUE;
        int startingIndex = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(s, i, j)) {
                    if (j - i + 1 > maxlen) {
                        startingIndex = i;
                        maxlen = j - i + 1;
                    }
                }
            }
        }

        return s.substring(startingIndex, startingIndex + maxlen);
    }
}


//Approach 3 - Using Bottom Up (Elaborated for simplicity)
//T.C : O(n^2)
//S.C : O(n^2)
public class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        int maxL = 0;
        int index = 0;

        boolean[][] t = new boolean[n][n];

        // Every single character is a palindrome
        for (int i = 0; i < n; i++) {
            t[i][i] = true;
            maxL = 1;
            index = i;
        }

        // Check for palindromes of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s.charAt(i) == s.charAt(i + 1)) {
                t[i][i + 1] = true;
                maxL = 2;
                index = i;
            }
        }

        // Check for palindromes of length 3 or more
        for (int L = 3; L <= n; L++) {
            for (int i = 0; i < n - L + 1; i++) {
                int j = i + L - 1;

                if (s.charAt(i) == s.charAt(j) && t[i + 1][j - 1]) {
                    t[i][j] = true;
                    if (j - i + 1 > maxL) {
                        maxL = j - i + 1;
                        index = i;
                    }
                }
            }
        }

        return s.substring(index, index + maxL);
    }
}


//Approach 4 :  (Simplifiying Approach-2 above)
//Simplified solution
public class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        boolean[][] t = new boolean[n][n];
        int maxL = 1;
        int start = 0;

        for (int i = 0; i < n; i++) {
            t[i][i] = true;
        }

        for (int L = 2; L <= n; L++) {
            for (int i = 0; i < n - L + 1; i++) {
                int j = i + L - 1;

                if (s.charAt(i) == s.charAt(j) && (t[i + 1][j - 1] || L == 2)) {
                    t[i][j] = true;
                    if (L > maxL) {
                        maxL = L;
                        start = i;
                    }
                }
            }
        }

        return s.substring(start, start + maxL);
    }
}


//Approach-5 (O(n) Approach) - Coming Soooon.