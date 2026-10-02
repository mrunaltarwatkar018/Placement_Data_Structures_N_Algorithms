/* Leetcode Problem No.: 1111. Maximum Nesting Depth of Two Valid Parentheses Strings  */

/*
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/description/
*/

/*********************************************************** C++ **************************************************/
//Approach - Greedily divide depth in half
//T.C - O(n)
//S.C - O(1)
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> result(seq.size());
        int d = 0;

        for (int i = 0; i < seq.size(); i++) {
            if (seq[i] == '(') {
                d++;
                result[i] = d % 2 == 0 ? 0 : 1;
            } 
            else {
                result[i] = d % 2 == 0 ? 0 : 1;
                d--;
            }
        }

        return result;
    }
};



/*********************************************************** JAVA **************************************************/
//Approach - Greedily divide depth in half
//T.C - O(n)
//S.C - O(1)
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int[] result = new int[seq.length()];
        int d = 0;

        for (int i = 0; i < seq.length(); i++) {
            if (seq.charAt(i) == '(') {
                d++;
                result[i] = d % 2 == 0 ? 0 : 1;
            } else {
                result[i] = d % 2 == 0 ? 0 : 1;
                d--;
            }
        }

        return result;
    }
}