/* Leetcode Problem No.: 605. Can Place Flowers  */

/*
        Company Tags                : GOOGLE
        Leetcode Link               : https://leetcode.com/problems/can-place-flowers/
*/


/*
    Approach Explanation:

        1.  Base Case: 
                If n is 0, we can always return true, as there are no flowers to plant.
        
        2.  Iterate through the flowerbed: We iterate through each plot in the flowerbed 
            using a for loop.
        
        3.  Check if a plot is empty: If a plot is empty (flowerbed[i] == 0), we check if 
            its left and right sides are also empty.
        
        4.  Check left and right sides: We use two boolean variables, left_side_empty and 
            right_side_empty, to check if the left and right sides of the current plot are 
            empty. We use the || operator to handle the edge cases where the current plot 
            is at the beginning or end of the flowerbed.
        
        5.  Plant a flower: If both left and right sides are empty, we plant a flower in 
            the current plot by setting flowerbed[i] = 1 and decrementing n.
        
        6.  Return true if all flowers are planted: If n becomes 0, we return true, 
            indicating that all flowers can be planted without violating the condition.
        
        7.  Return false if not all flowers can be planted: If the loop completes without 
            planting all flowers, we return false.

    Complexities

        Time Complexity: 
            O(length), where length is the size of the flowerbed vector. We iterate through 
            each plot in the flowerbed once.
        
        Space Complexity: 
            O(1), as we only use a constant amount of space to store the left_side_empty and 
            right_side_empty boolean variables. We modify the input flowerbed vector in place.


*/



class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int length = flowerbed.size();

        if ( n == 0 ) 
            return true;

        for ( int  i = 0; i < length; i++ ) {
            if ( flowerbed[i] == 0 ) {

                bool left_side_empty = ( i == 0 ) || flowerbed[i - 1] == 0;
                bool right_side_empty = ( i == length - 1 ) || flowerbed[i + 1] == 0;

                if ( left_side_empty && right_side_empty ) {
                    flowerbed[i] = 1;
                    n--;

                    if ( n == 0 ) 
                        return true;
                }
            }
        }
        return false;
    }
};

























// another way
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int l = flowerbed.size();
        
        if(n == 0)
            return true;
        
        
        for(int i = 0; i<l; i++) {
            
            if(flowerbed[i] == 0) {
                
                bool leftEmpty   = (i == 0) || (flowerbed[i-1] == 0);
                
                bool rightEmpty  = (i == l-1) || (flowerbed[i+1] == 0);
                
                if(leftEmpty && rightEmpty) {
                    flowerbed[i] = 1;
                    n--;
                    if(n == 0)
                        return true;
                }
                
            }
            
        }
        
        return false;
        
    }
};





























/*
        YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=dNBXGp8BgoI
*/