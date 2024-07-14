/* Leetcode Problem No.: 2108. Find First Palindromic String in the Array  */

/*
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/find-first-palindromic-string-in-the-array
*/


/****************************************************************** C++ ******************************************************************/

//Approach-1 (creating a reversed string)
//T.C : O(m*n) - m = number of words, n = max length length of words
//S.C : O(n) - Creating a reversed string

/*
    Approach Summary : 
        Approach-1 Summary:
            Method: 
                Creating a reversed string for each word and checking 
                if the original word is equal to its reversed form.
            
            Time Complexity (T.C): O(m*n) - m = number of words, n = max 
                length of words.

            Space Complexity (S.C): O(n) - Space used for creating the 
                reversed string.

            Details: 
                Iterates through the given words, creates a reversed string 
                for each word, and compares it with the original word. 
                Returns the first palindrome found or an empty string if 
                none is found.

*/

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        
        for(string &word : words) {
            if(word == string(rbegin(word), rend(word))) {
                return word;
            }
        }
        
        return "";
        
    }
};


//Approach-2 (using equal)
//T.C : O(m*n) - m = number of words, n = max length length of words
//S.C : O(1)

/*
    Approach Summary : 

        Approach-2 Summary:

        Method: 
            Using the equal function to check if the first half of the word 
            is equal to its reversed second half.

        Time Complexity (T.C): O(m*n) - m = number of words, n = max length 
            of words.
        
        Space Complexity (S.C): O(1) - Constant space as no additional  
            space is used.

        Details: 
            Iterates through the given words, checks if the first half of   
            each word is equal to its reversed second half using the equal 
            function. Returns the first palindrome found or an empty string 
            if none is found.
*/

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        
        for(string &word : words) {
            if(equal(word.begin(), word.begin() + word.size() / 2, word.rbegin())) {
                return word;
            }
        }
        
        return "";
        
    }
};


// Approach 3- Two Pointer Technique
//T.C : O(m*n) - m = number of words, n = max length length of words
//S.C : O(1)

/*
    Approach 3: (2 pointer)

        1.  We're on a mission to find that elusive palindromic string! But remember, we only need one to solve the puzzle. Once we catch it, we're outta here! 
        2.  First up, we've got our trusty detective function named check(). It's on the lookout for any suspicious non-palindromic behavior in each string.
        3.  Now, we're rolling up our sleeves for some two-pointer action! We're gonna compare the first and last characters of each string using the classic "good cop, bad cop" routine. 
        4.  If our check function finds a non-matching pair, it raises the alarm and returns false. But if it gives the all-clear, we know we're onto something good, and it signals true! 
        5.  With true in hand, we've got our palindromic suspect in custody! We're gonna proudly present it as the answer. And if false is the verdict, we'll keep sleuthing until we crack the case! 

        This way, we'll nail that first palindromic string without breaking a sweat! 💪😎

    Complexity
    1. Time complexity:
    O(N.M)
    (N is the number of words in the input array and M is the maximum length of a word.)

    2. Space complexity:
    O(1)
*/

class Solution {
public:
    bool check ( string s ) {
        int i = 0, j = s.size() - 1;

        while ( i <= j ) {
            if ( s[i] == s[j] ) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for ( int i = 0; i < words.size(); i++ ) {
            if ( check( words[i] ) )
                return words[i];
        }
        return "";
    }
};



































/****************************************************************** JAVA ******************************************************************/
//Approach-1 (creating a reversed string)
//T.C : O(m*n) - m = number of words, n = max length length of words
//S.C : O(n) - Creating a reversed string
class Solution {
    public String firstPalindrome(String[] words) {
        for (String word : words) {
            String reversed = new StringBuilder(word).reverse().toString();

            if (word.equals(reversed)) {
                return word;
            }
        }
        return "";
    }
}


//Approach-2 (using 2 pointer)
//T.C : O(m*n) - m = number of words, n = max length length of words
//S.C : O(1)
public class Solution {
    public String firstPalindrome(List<String> words) {
        for (String word : words) {
            if (isPalindrome(word)) {
                return word;
            }
        }
        return "";
    }

    private boolean isPalindrome(String word) {
        int length = word.length();
        for (int i = 0; i < length / 2; i++) {
            if (word.charAt(i) != word.charAt(length - 1 - i)) {
                return false;
            }
        }
        return true;
    }
}














/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=JPB_lLGSgnc
*/