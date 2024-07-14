/* Leetcode Problem No.: 179 . Largest Number  */

/*
    Company Tags                : Microsoft, Amazon, MakeMyTrip, Paytm, Zoho, Goldman Sachs
    Leetcode Link               : https://leetcode.com/problems/largest-number/
    Similar GFG Problem         : https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1
*/


/****************************************************** C++ ******************************************************/
//Leetcode Version

//T.C : O(nlogn)
//S.C : O(1) (I am ignoring the space taken by result of size n which we have to return
class Solution {
public:
    static bool myFunction(int a, int b) {
        string s1 = to_string(a);
        string s2 = to_string(b);
        
        return (s1+s2) > (s2+s1);
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), myFunction);
        
        
        if(nums[0] == 0)
            return "0";
        string result = "";
        for(int i:nums)
            result += to_string(i);
        return result;
        
    }
};





/*
    Approach Summary :

        The purpose of the method is to concatenate the strings in the 
        vector in a way that forms the largest possible number and return 
        the result as a string. To achieve this, a lambda function 
        myComparator is defined as a custom comparator for the sort 
        function. The lambda function compares two strings based on their 
        concatenation in two different orders and returns true if the 
        concatenation of the first string with the second results in a l
        arger number. The vector of strings arr is then sorted using the 
        custom comparator. Finally, the sorted strings are concatenated, 
        and the resulting string is returned as the output of the 
        printLargest method. In the Leetcode version, we have to convert 
        the int to string and then the problem is the same.
*/

// in lambda function

class Solution {
public:
    string largestNumber(vector<int>& nums) {

        auto myComparator = [] (int &a, int &b) {
	        
            string s1 = to_string(a);
            string s2 = to_string(b);
            
            if (s1 + s2 > s2 + s1){
	            return true;
	        }
	        return false;
	        
	        // or above 3 lines you can write as
	       // return s1 + s2 > s2 + s1;
	    };

        sort(begin(nums), end(nums), myComparator);

        if (nums[0] == 0) {
            return "0";
        }

        string result = "";
	    
	    for (int &num : nums) {
	        result += to_string(num);
	    }
	    
	    return result;
    }
};
















//GFG Version
//T.C : O(nlogn)

//S.C : O(1) (I am ignoring the space taken by result of size n which we have to return
    class Solution{
    public:
        string printLargest(int n, vector<string> &arr) {
            
            auto myComparator = [](string &s1, string &s2) {
                if(s1+s2 > s2+s1) {
                    return true;
                }
                return false;
            };
            
            sort(begin(arr), end(arr), myComparator);
            
            string result = "";
            for(string &s : arr) {
                result += s;
            }
            
            return result;
        }
    };




// in lambda function
    class Solution{
    public:
        // The main function that returns the arrangement with the largest value as
        // string.
        
        
        // The function accepts a vector of strings
        string printLargest(int n, vector<string> &arr) {
            
            auto myComparator = [] (string &s1, string &s2) {
                if (s1 + s2 > s2 + s1){
                    return true;
                }
                return false;
                
                // or above 3 lines you can write as
            // return s1 + s2 > s2 + s1;
            };
            
            sort(begin(arr), end(arr), myComparator);
            
            string result = "";
            
            for (string &s : arr) {
                result += s;
            }
            
            return result;
            
        }
        
    };


























/****************************************************** JAVA ******************************************************/
//Leetcode Version
//T.C : O(nlogn)
//S.C : O(1) (I am ignoring the space taken by result of size n which we have to return
public class Solution {
    public String largestNumber(int[] nums) {
        Integer[] numsAsInteger = Arrays.stream(nums).boxed().toArray(Integer[]::new);

        Arrays.sort(numsAsInteger, (a, b) -> {
            String s1 = Integer.toString(a);
            String s2 = Integer.toString(b);
            return (s2 + s1).compareTo(s1 + s2);
        });

        if (numsAsInteger[0] == 0) {
            return "0";
        }

        StringBuilder result = new StringBuilder();
        for (int num : numsAsInteger) {
            result.append(num);
        }

        return result.toString();
    }
}


//GFG Version
//T.C : O(nlogn)
//S.C : O(1) (I am ignoring the space taken by result of size n which we have to return
class Solution {
    String printLargest(int n, String[] arr) {
        Comparator<String> myComparator = (s1, s2) -> (s2 + s1).compareTo(s1 + s2);
        
        Arrays.sort(arr, myComparator);

        StringBuilder result = new StringBuilder();
        for (String s : arr) {
            result.append(s);
        }

        return result.toString();
    }
}









/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=oJyl4fbfpM0
*/