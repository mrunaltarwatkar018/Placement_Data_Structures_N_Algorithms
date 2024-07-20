/* Leetcode Problem No.: 452. Minimum Number of Arrows to Burst Balloons  */

/*
    Company Tags                : Google, Facebook, PayPal, Microsoft
    Leetcode Link               : https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
    
    It falls under the category of "Interval Based Question" as well.
    Link  :   
*/


/******************************************************************** C++ **************************************************************/
//Approach-1 (Just like Leetcode - "Non Overlapping Intervals")
//Sorting on the basis of "End coordinate"
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(begin(points), end(points), [](vector<int>& v1, vector<int>& v2) {
            return v1[1] < v2[1];
        });
        
        int count         = 1;
        int lastEndPoint  = points[0][1];
        
        for(int i = 1; i<n; i++) {
            int curr_startPoint = points[i][0];
            
            if(curr_startPoint > lastEndPoint) {
                count++;
                lastEndPoint = points[i][1];
            }
        }
        
        return count;
    }
};


//Approach-2 (Sorting on the basis of start coordinate)
//T.C : O(nlogn)
//S.C : O(n) space
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(begin(points), end(points));
        
        vector<vector<int>> balloons;
        balloons.push_back(points[0]);
        
        for(int i = 1; i<n; i++) {
            int currStartPoint = points[i][0];
            int currEndPoint   = points[i][1];
            
            int prevStartPoint = balloons.back()[0];
            int prevEndPoint   = balloons.back()[1];
            
            if(currStartPoint > prevEndPoint) { //no overlap
                balloons.push_back(points[i]);
            } else {
                //overlap
                balloons.back()[0] = max(prevStartPoint, currStartPoint);
                balloons.back()[1] = min(prevEndPoint, currEndPoint);
            }
        }
        
        return balloons.size();
    }
};

//Approach-3 (Sorting on the basis of "Start Coordinate")
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(begin(points), end(points));
        
        vector<int> prev = points[0];
        int count = 1;
        for(int i = 1; i<n; i++) {
            int currStartPoint = points[i][0];
            int currEndPoint   = points[i][1];
            
            int prevStartPoint = prev[0];
            int prevEndPoint   = prev[1];
            
            if(currStartPoint > prevEndPoint) { //no overlap
                count++;
                prev = points[i];
            } else {
                //overlap
                prev[0] = max(prevStartPoint, currStartPoint);
                prev[1] = min(prevEndPoint, currEndPoint);
            }
        }
        
        return count;
    }
};


























/******************************************************************** JAVA ***********************************************************/
// Approach-1 (Just like Leetcode - "Non Overlapping Intervals")
// Sorting on the basis of "End coordinate"
// T.C : O(nlogn)
// S.C : O(1)
class Solution {
    public int findMinArrowShots(int[][] points) {
        int n = points.length;
        Arrays.sort(points, Comparator.comparingInt(a -> a[1]));
        
        int count = 1;
        int lastEndPoint = points[0][1];
        
        for (int i = 1; i < n; i++) {
            int currStartPoint = points[i][0];
            
            if (currStartPoint > lastEndPoint) {
                count++;
                lastEndPoint = points[i][1];
            }
        }
        
        return count;
    }
}

// Approach-2 (Sorting on the basis of start coordinate)
// T.C : O(nlogn)
// S.C : O(n) space
class Solution {
    public int findMinArrowShots(int[][] points) {
        int n = points.length;
        Arrays.sort(points, Comparator.comparingInt(a -> a[0]));
        
        int[][] balloons = new int[n][2];
        balloons[0] = points[0];
        int balloonIndex = 0;
        
        for (int i = 1; i < n; i++) {
            int currStartPoint = points[i][0];
            int currEndPoint = points[i][1];
            
            int prevStartPoint = balloons[balloonIndex][0];
            int prevEndPoint = balloons[balloonIndex][1];
            
            if (currStartPoint > prevEndPoint) { // no overlap
                balloons[++balloonIndex] = points[i];
            } else {
                // overlap
                balloons[balloonIndex][0] = Math.max(prevStartPoint, currStartPoint);
                balloons[balloonIndex][1] = Math.min(prevEndPoint, currEndPoint);
            }
        }
        
        return balloonIndex + 1;
    }
}

// Approach-3 (Sorting on the basis of "Start Coordinate")
// T.C : O(nlogn)
// S.C : O(1)
class Solution {
    public int findMinArrowShots(int[][] points) {
        int n = points.length;
        Arrays.sort(points, Comparator.comparingInt(a -> a[0]));
        
        int[] prev = points[0];
        int count = 1;
        
        for (int i = 1; i < n; i++) {
            int currStartPoint = points[i][0];
            int currEndPoint = points[i][1];
            
            int prevStartPoint = prev[0];
            int prevEndPoint = prev[1];
            
            if (currStartPoint > prevEndPoint) { // no overlap
                count++;
                prev = points[i];
            } else {
                // overlap
                prev[0] = Math.max(prevStartPoint, currStartPoint);
                prev[1] = Math.min(prevEndPoint, currEndPoint);
            }
        }
        
        return count;
    }
}

































/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=zfcGwzfDNu0
*/