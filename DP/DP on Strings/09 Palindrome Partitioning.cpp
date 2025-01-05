/* Leetcode Problem No.: 131. Palindrome Partitioning  */

/*
    Company Tags                : Google, Amazon, Microsoft, Meta
    Leetcode Link               : https://leetcode.com/problems/palindrome-partitioning/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1
*/

/******************************************************** C++ ********************************************************/
// Approach-1 (Using DP + Backtracking)
// T.C : O(2^n)
// S.C : O(n^2)

/*
    Approaches Summary :
        The approach uses a combination of dynamic programming and backtracking to find all possible palindromic partitions 
        of a given string. Here's a summary:

        Dynamic Programming (DP) Table Construction:
            A 2D boolean array t is used to store whether substrings s[i...j] are palindromes.
            Single-character substrings are always palindromes.
            For substrings of length 2 or more, the array is populated based on whether the characters 
            at the ends are the same and if the substring between them is also a palindrome.
            (The DP table is used to quickly check if a substring is a palindrome.)

        Backtracking:
            The solve method recursively explores all possible partitions of the string using the precomputed DP table.
            If a substring is identified as a palindrome, it is added to the current partition, and the method proceeds to partition the remainder of the string.
            Once the entire string is partitioned, the result is added to the list of results.

        Result Collection:
            The final list of palindromic partitions is returned after all possible partitions have been explored.
            This approach efficiently finds all palindromic partitions by leveraging the DP table for quick palindrome checks and backtracking to explore all partition possibilities.
*/


class Solution {
public:

    void solve(string &s, int i, vector<string>& currPartition, vector<vector<bool>>& t, vector<vector<string>>& result) {
        if(i == s.length()) { //I was able to successfully partition the entire string
            result.push_back(currPartition);
            return;
        }

        // Two options at every index = partition or not partition
        // T.C. : O(2^n)
        for(int j = i; j < s.length(); j++) { // i partition, not partition
            if(t[i][j] == true) { //palindrome // O(1)
                currPartition.push_back(s.substr(i, j-i+1));
                solve(s, j+1, currPartition, t, result);
                currPartition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n, false)); // S.C : O(n^2)

        // Initialize the DP table for palindromic substrings
        //t[i][j] = true -> s[i...j] is a palindrome
        
        for (int i = 0; i < n; ++i) {
            t[i][i] = true; //substring of single character is always a palindrome
        }
        
        // T.C. : O(n^2)
        for (int L = 2; L <= n; ++L) {
            for (int i = 0; i < n - L + 1; ++i) {
                int j = i + L - 1;
                if (s[i] == s[j]) {
                    if (L == 2) {
                        t[i][j] = true;
                    } else {
                        t[i][j] = t[i + 1][j - 1];
                    }
                }
            }
        }

        vector<vector<string>> result;
        vector<string> currPartition;
        solve(s, 0, currPartition, t, result); // O(2^n)

        return result;
    }
};



//Approach-2 (Using Bakctracking Khandani Template)
//Whenever a question asks for "Generating all possible" something, think about Backtracking once
//T.C : O(n * 2^n) - For a string of length n, there are 2^(𝑛 − 1) potential ways to partition it (since each position can either be a cut or not). and we also check palindrome O(n)
//S.C : O(n * 2^n) - Number of partitions * their length
class Solution {
public:
    int n;
    
    bool isPalindrome(string &s, int l, int r) {
        
        while(l < r) {
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        
        return true;
        
    }
    
    void backtrack(string &s, int idx, vector<string> curr, vector<vector<string>> &result) {
        
        if(idx == n) {
            result.push_back(curr);
            return;
        }
        
        
        for(int i = idx; i<n; i++) {
            
            if(isPalindrome(s, idx, i)) {
                
                curr.push_back(s.substr(idx, i-idx+1));
                
                backtrack(s, i+1, curr, result);
                
                curr.pop_back();
                
            }
            
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<vector<string>> result;
        vector<string> curr;
        
        backtrack(s, 0, curr, result);
        
        return result;
        
    }
};





/******************************************************** JAVA ********************************************************/
//Approach-1 (Using Bakctracking Khandani Template)
//Whenever a question asks for "Generating all possible" something, think about Backtracking once
//T.C : O(n * 2^n) - For a string of length n, there are 2^(𝑛 − 1) potential ways to partition it (since each position can either be a cut or not). and we also check palindrome O(n)
//S.C : O(n * 2^n) - Number of partitions * their length
class Solution {
    private int n;
    
    private boolean isPalindrome(String s, int l, int r) {
        while (l < r) {
            if (s.charAt(l) != s.charAt(r))
                return false;
            l++;
            r--;
        }
        return true;
    }
    
    private void backtrack(String s, int idx, List<String> curr, List<List<String>> result) {
        if (idx == n) {
            result.add(new ArrayList<>(curr));
            return;
        }
        
        for (int i = idx; i < n; i++) {
            if (isPalindrome(s, idx, i)) {
                curr.add(s.substring(idx, i + 1));
                backtrack(s, i + 1, curr, result);
                curr.remove(curr.size() - 1);
            }
        }
    }
    
    public List<List<String>> partition(String s) {
        n = s.length();
        List<List<String>> result = new ArrayList<>();
        List<String> curr = new ArrayList<>();
        
        backtrack(s, 0, curr, result);
        
        return result;
    }
}


//Approach-2 (Using DP + Backtracking)
//T.C : O(2^n)
//S.C : O(n^2)
class Solution {
    public void solve(String s, int i, List<String> currPartition, boolean[][] t, List<List<String>> result) {
        if (i == s.length()) {
            result.add(new ArrayList<>(currPartition));
            return;
        }

        for (int j = i; j < s.length(); j++) {
            if (t[i][j]) { // palindrome
                currPartition.add(s.substring(i, j + 1));
                solve(s, j + 1, currPartition, t, result);
                currPartition.remove(currPartition.size() - 1);
            }
        }
    }

    public List<List<String>> partition(String s) {
        int n = s.length();
        boolean[][] t = new boolean[n][n];

        // Initialize the DP table for palindromic substrings
        // t[i][j] = true -> s[i...j] is a palindrome

        for (int i = 0; i < n; ++i) {
            t[i][i] = true; // substring of a single character is always a palindrome
        }

        for (int L = 2; L <= n; ++L) {
            for (int i = 0; i < n - L + 1; ++i) {
                int j = i + L - 1;
                if (s.charAt(i) == s.charAt(j)) {
                    if (L == 2) {
                        t[i][j] = true;
                    } else {
                        t[i][j] = t[i + 1][j - 1];
                    }
                }
            }
        }

        List<List<String>> result = new ArrayList<>();
        List<String> currPartition = new ArrayList<>();
        solve(s, 0, currPartition, t, result);

        return result;
    }
}