/* Leetcode Problem No.: 42. Trapping Rain Water (without stack)  */

/*
    Company Tags                      : Accolite, Adobe, Amazon, D-E-Shaw, MakeMyTrip, Microsoft, Payu
    Leetcode Link                     : https://leetcode.com/problems/trapping-rain-water/
*/


/********************************************************** C++ **********************************************************/

/*
    Summary : 
    
        This code implements the trapping rain water problem using a two-pass 
        approach. The `trap` function calculates the amount of water that can be 
        trapped between the bars given their heights. It first computes two arrays: 
        `leftMax` and `rightMax`, which store the maximum height encountered from 
        the left and right directions respectively, up to each index. Then, it 
        iterates through each bar and calculates the amount of water that can be 
        trapped at that position by taking the minimum of the left and right 
        maximum heights and subtracting the height of the current bar. Finally, it 
        sums up these amounts for all bars and returns the total trapped water.
            
        In summary, the algorithm computes the left and right maximum heights for 
        each position in linear time, then calculates the trapped water for each 
        bar in a single pass, resulting in a time complexity of O(n), where n is 
        the number of bars.
        
*/

//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> getLeftMax(vector<int>& height, int n) {
        vector<int> leftMax(n);
        leftMax[0] = height[0];
        for(int i = 1; i<n; i++) {
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        return leftMax;
    }
    vector<int> getRightMax(vector<int>& height, int n) {
        vector<int> rightMax(n);
        rightMax[n-1] = height[n-1];
        for(int i = n-2; i>=0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        return rightMax;
    } 
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 1 || n == 0)
            return 0;
        vector<int> leftMax = getLeftMax(height, n);
        vector<int> rightMax = getRightMax(height, n);
        int sum = 0;
        for(int i = 0; i<n; i++) {
            sum += min(leftMax[i], rightMax[i]) - height[i];
        }
        return sum;
    }
};



/********************************************************** JAVA **********************************************************/
//T.C : O(n)
//S.C : O(n)
public class Solution {
    public int[] getLeftMax(int[] height, int n) {
        int[] leftMax = new int[n];
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = Math.max(leftMax[i - 1], height[i]);
        }
        return leftMax;
    }

    public int[] getRightMax(int[] height, int n) {
        int[] rightMax = new int[n];
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = Math.max(rightMax[i + 1], height[i]);
        }
        return rightMax;
    }

    public int trap(int[] height) {
        int n = height.length;
        if (n == 1 || n == 0)
            return 0;
        
        int[] leftMax = getLeftMax(height, n);
        int[] rightMax = getRightMax(height, n);

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += Math.min(leftMax[i], rightMax[i]) - height[i];
        }
        return sum;
    }
}


/*
    YOUTUBE VIDEO LINK FOR THIS Qn    : https://www.youtube.com/watch?v=f2QgmVxPiS4
*/