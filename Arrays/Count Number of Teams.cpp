/* Leetcode Problem No.: 1395. Count Number of Teams  */

/*
    Company Tags                : Goldman Saches, Amazon, IBM
    Leetcode Link               : https://leetcode.com/problems/count-number-of-teams/description/
*/


/************************************************************ C++ ************************************************/
// Simple Approach - Counting left and right values
// T.C : O(n^2)
// S.C : O(1)

/*
    Summary :

        The provided solution calculates the number of valid teams that can be 
        formed from the given rating array. A valid team consists of three 
        soldiers, with their ratings either strictly increasing or strictly 
        decreasing. The approach can be summarized as follows:

        Initialization:

            Initialize a variable teams to 0 to keep track of the number of 
            valid teams.

            Get the size of the rating array.

        Iterate Through the Middle Soldier:

            Use an outer loop to iterate through each element j in the rating 
            array, excluding the first and last elements. This element serves 
            as the middle soldier in the potential teams.

        Count Elements on the Left and Right:

        For each j, use two inner loops:

            The first inner loop counts the number of elements on the left of j 
            that are either smaller (countSmallerLeft) or larger 
            (countLargerLeft) than rating[j].

            The second inner loop counts the number of elements on the right of 
            j that are either larger (countLargerRight) or smaller 
            (countSmallerRight) than rating[j].

        Calculate the Number of Valid Teams:

            Calculate the number of valid teams by considering:
                    Teams that form a strictly increasing sequence: 
                        countSmallerLeft * countLargerRight.

                    Teams that form a strictly decreasing sequence: 
                        countLargerLeft * countSmallerRight.

                    Add these counts to the teams variable.

        Return the Result:

        Return the total number of valid teams stored in the teams variable.
*/



class Solution {
public:
    int numTeams(vector<int>& rating) {

        int n = rating.size();

        int teams = 0;

        for ( int j = 0; j < n - 1; j++ ) {
            int count_Smaller_Left = 0;
            int count_Larger_Left = 0;
            int count_Smaller_Right = 0;
            int count_Larger_Right = 0;


            // for left side: count_Smaller_Left & count_Larger_Left
            for ( int i = 0; i < j; i++ ) {
                if  ( rating[i] < rating[j] ) {
                    count_Smaller_Left++;
                } else if ( rating[i] > rating[j ] ) {
                    count_Larger_Left++;
                }
            }

            // for right side: count_Smaller_Right & count_Larger_Right
            for( int k = j+1; k < n; k++ ) {
                if( rating[j] < rating[k] ) {
                    count_Larger_Right++;
                } else if ( rating[j] > rating[k] ) {
                    count_Smaller_Right++;
                }
            }
            // finding teams

            teams += ( count_Larger_Left * count_Smaller_Right ) + ( count_Smaller_Left * count_Larger_Right );

        }

        return teams;
        
    }
};

// other way to do similar approach
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();

        int teams = 0;

        for(int j = 1; j < n-1; j++) {

            int countSmallerLeft = 0;
            int countLargerLeft  = 0;
            int countSmallerRight = 0;
            int countLargerRight = 0;

            for(int i = 0; i < j; i++) {
                if(rating[i] < rating[j]) {
                    countSmallerLeft++;
                } else if(rating[i] > rating[j]) {
                    countLargerLeft++;
                }
            }

            for(int k = j+1; k < n; k++) {
                if(rating[j] < rating[k]) {
                    countLargerRight++;
                } else if(rating[j] > rating[k]) {
                    countSmallerRight++;
                }
            }

            teams += (countLargerLeft * countSmallerRight) + (countSmallerLeft * countLargerRight);


        }

        return teams;
    }
};



/************************************************************ JAVA *****************************************************/
//Simple Approach - Counting left and right values
//T.C : O(n^2)
//S.C : O(1)
class Solution {
    public int numTeams(int[] rating) {
        int n = rating.length;
        int teams = 0;

        for (int j = 1; j < n - 1; j++) {
            int countSmallerLeft = 0;
            int countLargerLeft = 0;
            int countSmallerRight = 0;
            int countLargerRight = 0;

            for (int i = 0; i < j; i++) {
                if (rating[i] < rating[j]) {
                    countSmallerLeft++;
                } else if (rating[i] > rating[j]) {
                    countLargerLeft++;
                }
            }

            for (int k = j + 1; k < n; k++) {
                if (rating[j] < rating[k]) {
                    countLargerRight++;
                } else if (rating[j] > rating[k]) {
                    countSmallerRight++;
                }
            }

            teams += (countLargerLeft * countSmallerRight) + (countSmallerLeft * countLargerRight);
        }

        return teams;
    }
}


























/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=UZupIKXnzq8
*/