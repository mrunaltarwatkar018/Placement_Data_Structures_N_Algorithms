/*    Leetcode Problem No.: 1823. Find the Winner of the Circular Game  */

/*
        Company Tags 		    : Goldman Sachs, Amazon
        Leetcode Link		    : https://leetcode.com/problems/find-the-winner-of-the-circular-game
        GFG Link      		    : https://www.geeksforgeeks.org/problems/game-of-death-in-a-circle1840/1

                Also Known as "Josephus Problem"
*/

/*************************************************************** C++ ***************************************************************/
//Approach-1 (Brute Force - Simple Simulation)
//T.C : O(n^2)
//S.C : O(n)

/*
    Approach 1: Brute Force (Simple Simulation)

        Time Complexity: O(n^2)
        Space Complexity: O(n)

        Description: 
            This approach uses a vector/ArrayList to simulate the elimination 
            process. It iteratively calculates the index of the player to be 
            eliminated, removes the player from the list, and continues until 
            only one player remains. The index of the next player to be 
            eliminated is adjusted using modulo arithmetic.

*/

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> arr;
        for(int i = 1; i <= n; i++) {
            arr.push_back(i);
        }

        int i = 0; //Game starts from 1st player which is sitting at index 0 in arr

        while(arr.size() > 1) {
            int idx = (i + k - 1) % arr.size();

            arr.erase(arr.begin() + idx);

            i = idx;
        }

        return arr[0];
    }
};


//Approach-2 (Using Queue for Simulation)
//T.C : O(n*k)
//S.C : O(n)

/*
    Approach 2: Using Queue for Simulation

        Time Complexity: O(n * k)
        Space Complexity: O(n)

        Description: 
            This method employs a Queue to simulate the game. Players are added 
            to the queue initially. In each iteration, players up to k-1 are 
            moved to the back of the queue, and the k-th player is removed. This 
            process is repeated until only one player remains in the queue.

*/

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> que;
        for(int i = 1; i <= n; i++) {
            que.push(i);
        }

        while(que.size() > 1) {

            for(int count = 1; count <= k-1; count++) {
                que.push(que.front());
                que.pop();
            }

            que.pop();

        }

        return que.front();
    }
};


//Approach-3 (Using Recursion)
//T.C : O(n)
//S.C : O(1), but note that it will take o(n) system stack space

/*
    Approach 3: Using Recursion

        Time Complexity: O(n)
        Space Complexity: O(1) (but O(n) due to recursion stack)

        Description: 
            This recursive approach calculates the index of the winning player 
            directly. It uses a helper function to find the winner index for n-1 
            players and adjusts this index to reflect the position in the 
            original group of n players. The base case handles the scenario with 
            only one player left, returning index 0.

        Each approach offers a different balance of time and space complexity, 
        allowing for flexibility based on the specific constraints and 
        requirements of the problem.
*/

class Solution {
public:

    int findWinnerIdx(int n, int k) {
        if(n == 1) {
            return 0; //index
        }

        int idx = findWinnerIdx(n-1, k);
        idx = (idx + k) % n; //to find the original index in the original array

        return idx;
    }

    int findTheWinner(int n, int k) {
        
        int result_idx = findWinnerIdx(n, k);


        return result_idx + 1;

    }
};

































/*************************************************************** JAVA ***************************************************************/
//Approach 1: Brute Force (Simple Simulation)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
    public int findTheWinner(int n, int k) {
        ArrayList<Integer> arr = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            arr.add(i);
        }

        int i = 0; // Game starts from 1st player which is sitting at index 0 in arr

        while (arr.size() > 1) {
            int idx = (i + k - 1) % arr.size();
            arr.remove(idx);
            i = idx;
        }

        return arr.get(0);
    }
}


//Approach 2: Using Queue for Simulation
//T.C : O(n*k)
//S.C : O(n)
class Solution {
    public int findTheWinner(int n, int k) {
        Queue<Integer> que = new LinkedList<>();
        for (int i = 1; i <= n; i++) {
            que.add(i);
        }

        while (que.size() > 1) {
            for (int count = 1; count <= k - 1; count++) {
                que.add(que.poll());
            }
            que.poll();
        }

        return que.peek();
    }
}


//Approach 3: Using Recursion
//T.C : O(n)
//S.C : O(1), but note that it will take o(n) system stack space
class Solution {
    private int findWinnerIdx(int n, int k) {
        if (n == 1) {
            return 0; // index
        }

        int idx = findWinnerIdx(n - 1, k);
        idx = (idx + k) % n; // to find the original index in the original array

        return idx;
    }

    public int findTheWinner(int n, int k) {
        int resultIdx = findWinnerIdx(n, k);
        return resultIdx + 1;
    }
}






















/*
	YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=lq3RMxKST-Y
*/