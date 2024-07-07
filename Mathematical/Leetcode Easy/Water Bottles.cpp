/*    Leetcode Problem No.: 1581. Water Bottles    */

/*
    Company Tags                 : AMAZON
    Leetcode Link                : https://leetcode.com/problems/water-bottles
*/


/********************************************************************* C++ *********************************************************************/

/*
    Approach-1 (Simple simulation)

        Time Complexity: O(numBottles)
        Space Complexity: O(1)

        Summary: 
            This approach simulates the process of consuming water bottles and 
            exchanging the empty ones for full bottles. It repeatedly consumes 
            and exchanges until the number of bottles left is less than the 
            exchange threshold. The total consumed bottles are returned.

*/



//Approach-1 (Simple simulation)
//T.C : O(numBottles)
//S.C : O(1)
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumed = 0;

        while(numBottles >= numExchange) {

            consumed   += numExchange;
            numBottles -= numExchange;

            numBottles += 1;

        }

        return consumed + numBottles;
    }
};




/*
    Approach-2 (Improvement on Approach-1)

        Time Complexity: O(lognumExchange(numBottles))
        Space Complexity: O(1)

        Summary: 
            This approach optimizes the first one by using integer division and 
            modulo operations to calculate how many new full bottles can be 
            obtained from empty bottles in each iteration. It reduces the number 
            of iterations needed to complete the exchange process.

*/

//Approach-2 (Improvement on Approach-1)
//T.C : O(log_numExchange_(numBottles))
//S.C : O(1)
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumed = numBottles;
        int emptyBottles = numBottles;

        while(emptyBottles >= numExchange) {
            int extraFullBottles = emptyBottles / numExchange;

            int remain = emptyBottles % numExchange;

            consumed += extraFullBottles;

            emptyBottles = remain + extraFullBottles;
        }

        return consumed;
    }
};


/*
    Approach-3 (Using maths)

        Time Complexity: O(1)
        Space Complexity: O(1)

        Summary: 
            This approach uses a mathematical formula to directly calculate the 
            total number of consumed bottles. It leverages the insight that the 
            total number of bottles is the initial count plus the number of 
            additional bottles obtained through exchanges, which is derived from 
            simple arithmetic operations.
*/

//Approach-3 (Using maths)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + (numBottles-1) / (numExchange-1);
    }
};



























/********************************************************************* JAVA *********************************************************************/

//Approach-1 (Simple simulation)
//T.C : O(numBottles)
//S.C : O(1)
class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int consumed = 0;

        while (numBottles >= numExchange) {
            consumed += numExchange;
            numBottles -= numExchange;

            numBottles += 1;
        }

        return consumed + numBottles;
    }
}


//Approach-2 (Improvement on Approach-1)
//T.C : O(log_numExchange_(numBottles))
//S.C : O(1)
class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int consumed = numBottles;
        int emptyBottles = numBottles;

        while (emptyBottles >= numExchange) {
            int extraFullBottles = emptyBottles / numExchange;
            int remain = emptyBottles % numExchange;

            consumed += extraFullBottles;
            emptyBottles = remain + extraFullBottles;
        }

        return consumed;
    }
}


//Approach-3 (Using maths):
//T.C : O(1)
//S.C:  O(1)
class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
}


/*
    Approach-1 (Simple simulation)

        Time Complexity: O(numBottles)
        Space Complexity: O(1)

        Summary: 
            This approach simulates the process of consuming water bottles and 
            exchanging the empty ones for full bottles. It repeatedly consumes 
            and exchanges until the number of bottles left is less than the 
            exchange threshold. The total consumed bottles are returned.

    Approach-2 (Improvement on Approach-1)

        Time Complexity: O(lognumExchange(numBottles))
        Space Complexity: O(1)

        Summary: 
            This approach optimizes the first one by using integer division and 
            modulo operations to calculate how many new full bottles can be 
            obtained from empty bottles in each iteration. It reduces the number 
            of iterations needed to complete the exchange process.

    Approach-3 (Using maths)

        Time Complexity: O(1)
        Space Complexity: O(1)

        Summary: 
            This approach uses a mathematical formula to directly calculate the 
            total number of consumed bottles. It leverages the insight that the 
            total number of bottles is the initial count plus the number of 
            additional bottles obtained through exchanges, which is derived from 
            simple arithmetic operations.
*/



/*
    YOUTUBE VIDEO ON THIS Qn  : https://www.youtube.com/watch?v=v2D_v3llC98
*/