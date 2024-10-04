/* Leetcode Problem No.: 2419. Divide Players Into Teams of Equal Skill  */

/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/divide-players-into-teams-of-equal-skill
*/



/************************************************************ C++ ************************************************/
//Approach-1 (Using frequency of skills similar to counting sort)
//T.C : O(nlogn)
//S.C : O(1)

/*
    Summary :
        Approach 1: Two Pointers with Sorting

            Steps:

                Sort the skill array.

                Use two pointers (i starting from the beginning and j from the end) to form 
                pairs.

                Calculate the sum of each pair (skill[i] + skill[j]) and check if it matches 
                a precomputed sum.

                If any pair doesn't match, return -1.

                Calculate and accumulate the chemistry (skill[i] * skill[j]) for each valid 
                pair.

            Complexity:

                Time Complexity: O(nlogn) due to sorting.
                Space Complexity: O(1) extra space (ignoring the input array).

            Use Case:

                Efficient when the sum constraints are simple and the array can be sorted 
                easily.

*/


class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        sort(begin(skill), end(skill));

        int i = 0;
        int j = n-1;
        int s = skill[i] + skill[j];

        long long chem = 0;

        while(i < j) {
            int currSkill = skill[i] + skill[j];

            if(currSkill != s) {
                return -1;
            }

            chem += (long long)(skill[i]) * (long long)(skill[j]);
            i++;
            j--;
        }
        

        return chem;

    }
};



//Approach-2 (Using frequency of skills similar to counting sort)
//T.C : O(n)
//S.C : O(1000) ~= O(1)


/*
    Summary :
        Approach 2: Frequency Array with Target Sum

            Steps:

                Use a frequency array (freq) to track occurrences of each skill.]

                Calculate the total sum of the skills and determine the target sum for each team.

                For each skill, find its complementary skill (target - skill[i]) using the 
                frequency array.

                If the complementary skill is not present, return -1.

                Accumulate chemistry (skill[i] * complementarySkill) and adjust frequencies.

            Complexity:

                Time Complexity: O(n) (linear traversal).
                Space Complexity: O(1001) for the frequency array.

            Use Case:

                Useful when the input values have a constrained range, allowing quick frequency 
                lookups.

*/


class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        vector<int> vec(1001, 0);
        int SUM = 0;
        for(int &s : skill) {
            SUM += s;
            vec[s]++; //freq updated
        }

        int teams = n/2;

        if(SUM % teams != 0) {
            return -1;
        }

        int target = SUM / teams;
        long long chem = 0;

        for(int i = 0; i < n; i++) {
            int currSkill   = skill[i];
            int remainSkill = target - currSkill;

            if(vec[remainSkill] <= 0) {
                return -1;
            }

            chem += (long long)currSkill * (long long)(remainSkill);
            vec[remainSkill] -= 1;
        }

        return chem/2;

    }
};





/************************************************************ JAVA ************************************************/
//Approach-1 (Using frequency of skills similar to counting sort)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
    public long dividePlayers(int[] skill) {
        int n = skill.length;
        
        // Sort the skill array
        Arrays.sort(skill);
        
        int i = 0;
        int j = n - 1;
        int s = skill[i] + skill[j];
        
        long chem = 0;
        
        // Check each pair from both ends of the sorted array
        while (i < j) {
            int currSkill = skill[i] + skill[j];
            
            // If current pair sum is not equal to expected sum, return -1
            if (currSkill != s) {
                return -1;
            }
            
            // Calculate the chemistry and move to the next pair
            chem += (long) skill[i] * (long) skill[j];
            i++;
            j--;
        }
        
        return chem;
    }
}



//Approach-2 (Using frequency of skills similar to counting sort)
//T.C : O(n)
//S.C : O(1000) ~= O(1)
class Solution {
    public long dividePlayers(int[] skill) {
        int n = skill.length;

        // Frequency array to count occurrences of each skill value
        int[] freq = new int[1001];
        int totalSum = 0;

        for (int s : skill) {
            totalSum += s;
            freq[s]++; // Update frequency
        }

        int teams = n / 2;

        // Check if total sum is divisible by the number of teams
        if (totalSum % teams != 0) {
            return -1;
        }

        int targetSum = totalSum / teams;
        long chemistry = 0;

        for (int currSkill : skill) {
            int remainingSkill = targetSum - currSkill;

            // If the complementary skill is not available, return -1
            if (freq[remainingSkill] <= 0) {
                return -1;
            }

            chemistry += (long) currSkill * (long) remainingSkill;
            freq[remainingSkill]--; // Reduce the frequency of used skill
        }

        return chemistry / 2;
    }
}