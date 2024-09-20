/* GFG Problem: Facing the sun */

/*
    Company Tags                : Amazon 
    GFG Link                    : https://www.geeksforgeeks.org/problems/facing-the-sun2126/1
*/





class Solution {
public:
    /* Returns count of buildings that can see sunlight */
    int countBuildings(std::vector<int>& height) {
        /* Initialize count and max height with the first building's height */
        int count = 1;
        int maxi = height[0];

        /* Iterate through the rest of the buildings */
        for (int i = 1; i < height.size(); i++) {
            if (height[i] > maxi) {
                /* If the current building is taller, increment count and update max height */
                count++;
                maxi = height[i];
            }
        }
        return count;
    }
};
