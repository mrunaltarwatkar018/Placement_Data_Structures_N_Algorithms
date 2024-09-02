/* Leetcode Problem No.: 1894. Find the Student that Will Replace the Chalk  */

/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk
*/




/************************************************************ C++ ************************************************/


/*
    Summary :

        Approach 1: Simulation (TLE)

            Description: 
                This approach simulates the chalk usage by iterating through the students in 
                a loop and subtracting their chalk requirements from k until k becomes less 
                than a student's chalk requirement. The simulation continues until the 
                condition is met.

            Time Complexity: 
                O(k/sum * n) — where sum is the total sum of chalk requirements in one full 
                iteration and n is the number of students. This can result in a Time Limit 
                Exceeded (TLE) error for large inputs, as k might be very large.
                
            Space Complexity: 
                O(1) — The approach only uses a constant amount of extra space.

*/

//Approach-1 - Simulation (TLE)
//T.C : O(k/sum * n)
//S.C : O(1)


class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        while(true) {
            for(int i = 0; i < chalk.size(); i++) {
                if(k < chalk[i]) {
                    return i;
                }
            }
        }

        return -1;
    }
};



/*
    Summary :

        Approach 2: Remainder Optimization

            Description: 
                Instead of simulating the entire process, this approach calculates the total 
                chalk required for one complete round of all students (totalChalkSum). It 
                then computes the remainder of k when divided by totalChalkSum 
                (remainChalk). This allows us to reduce the problem to a smaller equivalent 
                by only considering the remaining chalk. Finally, it finds the first student 
                whose chalk requirement exceeds remainChalk.

            Time Complexity: 
                O(n) — The total chalk sum is computed in one pass, and finding the student 
                who runs out of chalk takes another pass.

            Space Complexity: 
                O(1) — This approach also only uses a constant amount of extra space.

*/


//Approach-2 (Making use of remainder)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();

        long long totalChalkSum = 0; //Total chalks required in one iteration
        for(int &chalkReq : chalk) { //O(n)
            totalChalkSum += chalkReq;
        }

        //Number of full iteration possible = k/totalChalkSum

        int remainChalk = k%totalChalkSum;

        for(int i = 0; i < n; i++) { //O(n)
            if(remainChalk < chalk[i]) {
                return i;
            }

            remainChalk -= chalk[i];
        }

        return -1;
    }
};


// small modification / optimization in approach 2

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();

        long long totalChalkSum = 0; //Total chalks required in one iteration

        for(int &chalkReq : chalk) { //O(n)
            totalChalkSum += chalkReq;

            if (totalChalkSum > k ) { // small modification / optimization
                break;
            }
        }

        //Number of full iteration possible = k / totalChalkSum

        int remainChalk = k % totalChalkSum;

        for(int i = 0; i < n; i++) { //O(n)
            if(remainChalk < chalk[i]) {
                return i;
            }

            remainChalk -= chalk[i];
        }

        return -1;
    }
};



/************************************************************ JAVA ************************************************/
//Approach-1 - Simulation (TLE)
//T.C : O(k/sum * n)
//S.C : O(1)
class Solution {
    public int chalkReplacer(int[] chalk, int k) {
        while (true) {
            for (int i = 0; i < chalk.length; i++) {
                if (k < chalk[i]) {
                    return i;
                }
                k -= chalk[i];
            }
        }
    }
}

//Approach-2 (Making use of remainder)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int chalkReplacer(int[] chalk, int k) {
        int n = chalk.length;

        // Calculate the total sum of chalk required in one iteration
        long totalChalkSum = 0;
        for (int chalkReq : chalk) {
            totalChalkSum += chalkReq;
        }

        // Calculate the remaining chalk after full iterations
        int remainChalk = (int)(k % totalChalkSum);

        // Find the first student who cannot complete their required chalk usage
        for (int i = 0; i < n; i++) {
            if (remainChalk < chalk[i]) {
                return i;
            }
            remainChalk -= chalk[i];
        }

        return -1; // In theory, this line should never be reached
    }
}
















// another way
// maths
class Solution {
    public int chalkReplacer(int[] chalk, int k) {
        long sum=0;
        for(int i=0;i<chalk.length;i++){
            sum+=chalk[i];
        }
        int remainingChalks = (int)(k % sum);
        for(int i=0;i<chalk.length;i++){
            if(remainingChalks < chalk[i]){
                return i;
            }
            remainingChalks -= chalk[i];
        }
        return -1;
    }
}

// binary search
class Solution {
    int n;
    public int ceil(long prefixSum[], int remainingChalks){
        int start = 0;
        int end = n-1;
        int ans=0;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(prefixSum[mid] == remainingChalks){
                return mid+1;
            }else if(prefixSum[mid] < remainingChalks){
                start = mid+1;
            }else{
                ans = mid;
                end = mid-1;
            }
        }
        return ans;
    }
    public int chalkReplacer(int[] chalk, int k) {
        n = chalk.length;
        long prefixSum[] = new long[n];
        prefixSum[0] = chalk[0];
        for(int i=1;i<n;i++){
            prefixSum[i] = prefixSum[i-1] + chalk[i];
        }
        long sum = prefixSum[n-1];
        int remainingChalks = (int)(k % sum);
        return ceil(prefixSum,remainingChalks);
    }
}