/* Leetcode Problem No.: 647. Palindromic Substrings  */

/*
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/palindromic-substrings/description
*/

/*
    Approaches Summary : 

        Approach-1 (Simply check all substrings possible)
            Idea: Iterate through all possible substrings and check if each one is a palindrome.

            Time Complexity (T.C): O(n^3) - Check all substrings, and for each substring, check 
                                            if it's a palindrome in O(n) time.

            Space Complexity (S.C): O(1) - No additional space is used, only a constant amount.

        Approach-2 (Memoize the approach above)
            Idea: Use memoization to avoid redundant computations when checking if substrings are palindromes.

            Time Complexity (T.C): O(n^2) - Every subproblem is computed only once, and after that, it's reused.

            Space Complexity (S.C): O(n^2) - Memoization table to store intermediate results.

        Approach-3 (Bottom-Up - Blueprint for Palindrome Questions)
            Idea: Build a table of whether substrings are palindromes bottom-up, considering all possible lengths.

            Time Complexity (T.C): O(n^2) - Iterate through all substrings, and for each, compute the palindrome 
                                            table in O(1) time.

            Space Complexity (S.C): O(n^2) - Palindrome table to store results.

        Approach-4 (Smart Approach - Expanding from Center)
            Idea: For each character and pair of consecutive characters, expand outward to find palindromes.

            Time Complexity (T.C): O(n^2) - Expand around each character or pair of characters in O(n) time.

            Space Complexity (S.C): O(1) - No additional space is used, only a constant amount.

*/


/******************************************************************** C++ ********************************************************************/
// Approach-1 (Simply check all substrings possible)
// T.C : O(n^3)
// S.C : O(1)
class Solution {
public:
    bool checkPalindrome(string &s, int i, int j) {
        if (i > j) {
            return true;
        }

        if(s[i] == s[j]) {
            return checkPalindrome(s, i+1, j-1);
        }
        return false;
    }
    
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) { //check all possible substrings
                if (checkPalindrome(s, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};


// Approach-2 (Memoize the approach above)
// T.C : O(n^2) - Every subproblem is being computed only once and after that it's being reused
// S.C : O(n^2)
class Solution {
public:
    int t[1001][1001];
    bool checkPalindrome(string &s, int i, int j) {
        if (i > j) {
            return true;
        }

        if (t[i][j] != -1) {
            return t[i][j]; // 0 : Flase, 1 : True
        }

        if(s[i] == s[j]) {
            return t[i][j] = checkPalindrome(s, i+1, j-1);
        }
        return t[i][j] = false;
    }
    
    int countSubstrings(string s) {
        int n = s.length();
        memset(t, -1, sizeof(t));
        // t[i][j] = -1 : Not computed/solved yet
        // t[i][j] = 0  : Not a palindrome i.e, False
        // t[i][j] = 1  : Palindrome i.e, True
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) { //check all possible substrings
                if (checkPalindrome(s, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};


// Approach-3(Bottom Up - My Favorite Blue Print of Palindrome Qns)
// T.C : O(n^2)
// S.C : O(n^2)
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n, false));
        //t[i][j] = true : s[i:j] is a palindromic substring where i and j are inclusive indices
        int count = 0;

        for (int L = 1; L <= n; L++) {
            for (int i = 0; i + L - 1 < n; i++) {
                int j = i + L - 1;
                if(i == j) {
                    t[i][i] = true; //Single characters are palindrome
                } else if(i+1 == j) {
                    t[i][j] = (s[i] == s[j]); //Strings of 2 Length
                } else {
                    t[i][j] = ((s[i] == s[j]) && t[i+1][j-1]); // generic case, greater than string of length 2
                }

                if (t[i][j] == true) {
                    count++;
                }
            }
        }
        
        return count;
    }
};

// or
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n, false));
        //t[i][j] = true : s[i:j] is a substring where i and j are inclusive indices

        int count = 0;

        for(int L = 1; L <= n; L++) {
            for(int i = 0; i+L <= n; i++) {
                int j = i + L - 1;

                if(i == j) {
                    t[i][i] = true; //Single characters are palindrome
                } else if(i+1 == j) {
                    t[i][j] = (s[i] == s[j]); //Strings of 2 Length
                } else {
                    t[i][j] = ((s[i] == s[j]) && t[i+1][j-1] == true);
                }

                count += t[i][j];
            }
        }

        return count;
    }
};


// Approach-4 (Smart approach)
// T.C : O(n^2)
// S.C : o(1)
class Solution {
public:
    int count = 0;
    void chackPalindrome(string& s, int i, int j, int n) {
        
        while(i >= 0 && j < n && s[i] == s[j]) {
            count++;
            i--; //expanding from center
            j++; //expanding from center
        }
    }
    int countSubstrings(string s) {
        int n = s.length();
        count = 0;
        
        /*
            
    Every single character in the string is a center for possible odd-length palindromes: check(s, i, i);
    Every pair of consecutive characters in the string is a center for possible even-length palindromes: check(s, i, i+1);.

        */
        for(int i = 0; i<n; i++) {
            chackPalindrome(s, i, i, n);
            chackPalindrome(s, i, i+1, n);
        }
        return count;
    }
};

















/*
    Approaches Summary : 

        Approach-1 (Simply check all substrings possible)
            Idea: Iterate through all possible substrings and check if each one is a palindrome.

            Time Complexity (T.C): O(n^3) - Check all substrings, and for each substring, check 
                                            if it's a palindrome in O(n) time.

            Space Complexity (S.C): O(1) - No additional space is used, only a constant amount.

        Approach-2 (Memoize the approach above)
            Idea: Use memoization to avoid redundant computations when checking if substrings are palindromes.

            Time Complexity (T.C): O(n^2) - Every subproblem is computed only once, and after that, it's reused.

            Space Complexity (S.C): O(n^2) - Memoization table to store intermediate results.

        Approach-3 (Bottom-Up - Blueprint for Palindrome Questions)
            Idea: Build a table of whether substrings are palindromes bottom-up, considering all possible lengths.

            Time Complexity (T.C): O(n^2) - Iterate through all substrings, and for each, compute the palindrome 
                                            table in O(1) time.

            Space Complexity (S.C): O(n^2) - Palindrome table to store results.

        Approach-4 (Smart Approach - Expanding from Center)
            Idea: For each character and pair of consecutive characters, expand outward to find palindromes.

            Time Complexity (T.C): O(n^2) - Expand around each character or pair of characters in O(n) time.

            Space Complexity (S.C): O(1) - No additional space is used, only a constant amount.

*/

/******************************************************************** JAVA ********************************************************************/
// Approach-1 (Simply check all substrings possible)
// T.C : O(n^3)
// S.C : O(1)
class Solution1 {
    public boolean check(String s, int i, int j) {
        if (i >= j) {
            return true;
        }

        if (s.charAt(i) == s.charAt(j)) {
            return check(s, i + 1, j - 1);
        }

        return false;
    }

    public int countSubstrings(String s) {
        int n = s.length();

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) { // check all possible substrings
                if (check(s, i, j)) {
                    count++;
                }
            }
        }

        return count;
    }
}

// Approach-2 (Memoize the approach above)
// T.C : O(n^2) - Every subproblem is being computed only once and after that, it's being reused
// S.C : O(n^2)
class Solution {
    int[][] t;

    public boolean check(String s, int i, int j) {
        if (i >= j) {
            return true;
        }

        if (t[i][j] != -1) {
            return t[i][j] == 1;
        }

        if (s.charAt(i) == s.charAt(j)) {
            boolean val = check(s, i+1, j-1);
            if(val == true)
                t[i][j] = 1;
            else
                t[i][j] = 0;
            return val;
        }

        t[i][j] = 0;
        return false;
    }

    public int countSubstrings(String s) {
        int n = s.length();
        t = new int[n][n];
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) { // check all possible substrings
                if (check(s, i, j)) {
                    count++;
                }
            }
        }

        return count;
    }
}


// Approach-3 (Bottom Up - My Favourite Blueprint of Palindrome Questions)
// T.C : O(n^2)
// S.C : O(n^2)
class Solution3 {
    public int countSubstrings(String s) {
        int n = s.length();
        boolean[][] t = new boolean[n][n];

        int count = 0;

        for (int L = 1; L <= n; L++) {
            for (int i = 0; i + L <= n; i++) {
                int j = i + L - 1;

                if (i == j) {
                    t[i][i] = true; // Single characters are palindrome
                } else if (i + 1 == j) {
                    t[i][j] = (s.charAt(i) == s.charAt(j)); // Strings of 2 Length
                } else {
                    t[i][j] = (s.charAt(i) == s.charAt(j) && t[i + 1][j - 1]);
                }

                if (t[i][j]) {
                    count++;
                }
            }
        }

        return count;
    }
}


// Approach-4 (Smart approach)
// T.C : O(n^2)
// S.C : O(1)
class Solution4 {
    private int count = 0;

    private void check(String s, int i, int j, int n) {
        while (i >= 0 && j < n && s.charAt(i) == s.charAt(j)) {
            count++;
            i--; // expanding from center
            j++; // expanding from center
        }
    }

    public int countSubstrings(String s) {
        int n = s.length();
        count = 0;

        /*
         * Every single character in the string is a center for possible odd-length
         * palindromes: check(s, i, i); Every pair of consecutive characters in the
         * string is a center for possible even-length palindromes: check(s, i, i+1);
         */
        for (int i = 0; i < n; i++) {
            check(s, i, i, n);
            check(s, i, i + 1, n);
        }
        return count;
    }
}