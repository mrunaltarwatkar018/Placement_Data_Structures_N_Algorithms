/*    Leetcode Problem No.: 3133. Minimum Array End    */

/*
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-array-end/description/
*/


/******************************************************** C++ ********************************************************/
//Approach - Simple using AND and OR
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long minEnd(int n, int x) {
        long long num = x;

        for(int i = 1; i < n; i++) {

            //num+1
            num = (num+1) | x;
            
        }

        return num;
    }
};


/******************************************************** JAVA ********************************************************/
//Approach - Simple using AND and OR
//T.C : O(n)
//S.C : O(1)
class Solution {
    public long minEnd(int n, int x) {
        long num = x;

        for (int i = 1; i < n; i++) {
            // Increment num and perform bitwise OR with x
            num = (num + 1) | x;
        }

        return num;
    }
}