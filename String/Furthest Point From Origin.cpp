/* Leetcode Problem No.: 2833: Furthest Point From Origin   */

/*
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/furthest-point-from-origin
*/

/*************************************************************************** C++ ***************************************************************************/
//Approach (simple traverse and count)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left  = 0;
        int right = 0;
        int dash  = 0;

        for(char &ch : moves) {
            if(ch == 'L') left++;
            else if(ch == 'R') right++;
            else dash++;
        }

        return abs(left - right) + dash;
    }
};


/*************************************************************************** JAVA ***************************************************************************/
//Approach (simple traverse and count)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int furthestDistanceFromOrigin(String moves) {
        int left  = 0;
        int right = 0;
        int dash  = 0;

        for(char ch : moves.toCharArray()) {
            if(ch == 'L') left++;
            else if(ch == 'R') right++;
            else dash++;
        }

        return Math.abs(left - right) + dash;
    }
}