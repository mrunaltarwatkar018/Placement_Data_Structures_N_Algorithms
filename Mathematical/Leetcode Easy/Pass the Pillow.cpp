/*    Leetcode Problem No.: 2582. Pass the Pillow    */

/*
    Company Tags                : Microsoft
    Leetcode Link               : https://leetcode.com/problems/pass-the-pillow/description/
*/


/************************************************************ C++ ************************************************************/

/*
    Approach 1 (Simple Simulation)

        Time Complexity: O(time)
        Space Complexity: O(1)

        Description: 
            This approach simulates the passing of the pillow in real-time. 
            We maintain two variables, idx for the current position and dir 
            for the direction (either forward or backward). 
            
            As long as there is remaining time, we update the position and 
            direction based on the current state, decrementing the time with each 
            step until the time runs out.

            This approach is straightforward but may be inefficient for large time 
            values due to its linear complexity.
*/


//Approach-1 (Simple Simulation)
//T.C : O(time)
//S.C : O(1)
class Solution {
public:
    int passThePillow(int n, int time) {
        int idx  = 1; // position of pillow
        int dir = 1; // direction from left to right

        while(time > 0) {
            if(idx + dir >=1 && idx + dir <= n) {
                idx += dir;
                time--;
            } else {
                dir *= -1; // direction from right to left
            }
        }
        return idx;
    }
};






//Approach-2 (Simple Maths)
//T.C : O(1)
//S.C : O(1)

/*   
    Approach 2 (Simple Maths)

        Time Complexity: O(1)
        Space Complexity: O(1)

        Description: 
            This approach uses mathematical calculations to determine the final 
            position without simulating each step. 
            
            It calculates the number of full rounds of passing the pillow 
            (totalFullRounds) and the remaining time (timeLeft).

            Depending on whether the number of full rounds is even or odd, it 
            adjusts the final position accordingly. 
            
            This method is highly efficient with constant time complexity, making 
            it suitable for larger inputs.
*/

class Solution {
public:
    int passThePillow(int n, int time) {
        
        int totalFullRounds = time / (n-1);

        int timeLeft        = time % (n-1);

        if(totalFullRounds % 2 == 0) {
            return timeLeft + 1;
        } else {
            return n - timeLeft;
        }

        return -1;
    }
};





































/************************************************************ JAVA ************************************************************/
//Approach-1 (Simple Simulation)
// T.C : O(time)
// S.C : O(1)
class Solution {
    public int passThePillow(int n, int time) {
        int idx = 1;
        int dir = 1;

        while (time > 0) {
            if (idx + dir >= 1 && idx + dir <= n) {
                idx += dir;
                time--;
            } else {
                dir *= -1;
            }
        }
        return idx;
    }
}


//Approach-2 (Simple Maths)
// T.C : O(1)
// S.C : O(1)
class Solution {
    public int passThePillow(int n, int time) {
        int totalFullRounds = time / (n - 1);
        int timeLeft = time % (n - 1);

        if (totalFullRounds % 2 == 0) {
            return timeLeft + 1;
        } else {
            return n - timeLeft;
        }
    }
}




































/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=tI8OO93t2zM
*/