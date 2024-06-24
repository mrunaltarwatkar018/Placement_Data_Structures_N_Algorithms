/* Leetcode Problem No.: 3191. Minimum Operations to Make Binary Array Elements Equal to One I */

/*
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/description/
*/
//  Same Leetcode Problem No.: 995. Minimum Number of K Consecutive Bit Flips
//SAMEW PROBLEM WITH  K = 3 - (Leetcode - 3191) "Minimum Operations to Make Binary Array Elements Equal to One I"
//SUGGESTION - Solve Leetcode-319 (Bulb Switcher) as well. It's kind of a similar problem (not exactly same)


/*
    Approach 1: Using Auxiliary Array to Mark Flipped Indices

        Time Complexity: O(n)
        Space Complexity: O(n)

        Description: This approach uses an auxiliary boolean array isFlipped to
        track whether an index has been flipped. The flipCountFromPastForCurri 
        variable keeps track of the cumulative number of flips affecting the 
        current index. For each index, it adjusts the flip count based on whether 
        the i-k index was flipped and then checks if the current bit needs to be 
        flipped based on the current flip count. If a flip is needed but not 
        possible due to array bounds, it returns -1.

*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int k = 3;
        int n = nums.size();

        int flips = 0;

        int flipsCountFromPastFori = 0;

        vector<bool> isFlipped(n, false);

        for (int i = 0; i < n; i++) {
            if (i >= k && isFlipped[i - k] == true) {
                flipsCountFromPastFori--;
            }

            // flips at index i
            if (flipsCountFromPastFori % 2 == nums[i]) {
                if (i + k > n)
                    return -1;
                flipsCountFromPastFori++;
                flips++;
                isFlipped[i] = true;
            }
        }

        return flips;
    }
};



// improving approach 1: modifiying input, before modifying inout asked  the interviewer 
/*

    Approach 2: Using the Input Array to Mark Flipped Indices - We will be manipulating the input as well

        Time Complexity: O(n)
        Space Complexity: O(1)
        
        Description: This approach modifies the input array to mark flipped indices 
        by setting flipped elements to 2. The index_i_kitna_flip_jhela variable is 
        used to track the number of flips affecting the current index. Similar to 
        Approach 1, it adjusts the flip count based on whether the i-k index was 
        flipped (indicated by 2 in the array) and checks if the current bit needs 
        to be flipped. If a flip is needed but not possible due to array bounds, it 
        returns -1.

*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int k = 3;
        int n = nums.size();

        int flips = 0;
        
        int flipCountFromPastForCurri = 0;

        for(int i = 0; i < n; i++) {

            // insted of 2, you can use any value, its is only for compairing purpose
            if(i >= k && nums[i-k] == 2) { //Was it flipped 
                flipCountFromPastForCurri--;
            }
            
            if(flipCountFromPastForCurri % 2 == nums[i]) {
                if(i+k > n){
                    return -1;
                }
                flipCountFromPastForCurri++;
                nums[i] = 2; //Marking as flipped
                flips++;
            }
        }

        return flips;
    }
};



/*

    Approach 3: Using Deque to Mark Flipped Indices

        Time Complexity: O(n)
        Space Complexity: O(k)

        Description: This approach uses a deque (flipQue) to efficiently track the 
        flips within the window of size k. The index_i_kitna_flip_jhela variable 
        keeps track of the cumulative number of flips affecting the current index. 
        For each index, it adjusts the flip count by removing the effect of the 
        flip that goes out of the k-window (front of the deque) and checks if the 
        current bit needs to be flipped. If a flip is needed but not possible due 
        to array bounds, it returns -1. The deque helps in maintaining the flip 
        history within the window efficiently.

*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int k = 3;
        int n = nums.size();

        int flips = 0;
        deque<int> flipQue;
        int flipCountFromPastForCurri = 0;

        for(int i = 0; i < n; i++) {
            if(i >= k){
                flipCountFromPastForCurri -= flipQue.front(); // representing [i-k] value
                flipQue.pop_front();
            }
            
            if(flipCountFromPastForCurri % 2 == nums[i]) {
                if(i+k > n){
                    return -1;
                }
                flipCountFromPastForCurri++;
                flipQue.push_back(1); // 1 means I have applied flip at index  i
                flips++;
            } else {
                // no need to flip
                flipQue.push_back(0); // 0 means I have not applied flip at index  i
            }
        }

        return flips;
    }
};


/*
        These three approaches offer different trade-offs between space complexity 
        and how the flip history is managed, with Approach 2 being the most 
        space-efficient and Approach 1 and 3 offering clear and efficient ways to 
        manage flip history with additional space usage.
*/