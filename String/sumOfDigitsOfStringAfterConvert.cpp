/* Leetcode Problem No.: 1945. Sum of Digits of String After Convert  */

/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/?envType=daily-question&envId=2024-09-03
*/




/************************************************************ C++ ************************************************/
// T.C : O(k*n)
// S.C : O(n)
class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";

        for(char &ch : s) {
            int char_int = ch - 'a' + 1; //a : 1, b : 2 and so on...
            num         += to_string(char_int);
        }
        
        int sum = 0;

        while(k--) {
            sum = 0;
            for(char &ch : num) {
                sum += ch - '0';
            }

            num = to_string(sum);
        }

        return stoi(num);
    }
};




/************************************************ JAVA ************************************************************/
// T.C : O(k*n)
// S.C : O(n)
class Solution {
    public int getLucky(String s, int k) {
        // Initialize an empty string to store the numeric representation of the characters
        StringBuilder num = new StringBuilder();
        
        // Convert each character in the string to its corresponding number (a: 1, b: 2, ..., z: 26)
        for (char ch : s.toCharArray()) {
            int charInt = ch - 'a' + 1;
            num.append(charInt);
        }

        // Initialize sum
        int sum = 0;

        // Repeat the process k times
        while (k-- > 0) {
            sum = 0;
            // Calculate the sum of digits
            for (char ch : num.toString().toCharArray()) {
                sum += ch - '0';
            }

            // Convert the sum back to a string
            num = new StringBuilder(Integer.toString(sum));
        }

        // Return the final result as an integer
        return Integer.parseInt(num.toString());
    }
}







// 1st approach
class Solution {
    public int getLucky(String s, int k) {
        StringBuilder sb = new StringBuilder();
        for(char ch : s.toCharArray()){
            sb.append(ch-96);
        }
        while(k>0){
            int sum=0;
            for(int i=0;i<sb.length();i++){ 
                sum += (sb.charAt(i) - '0');
            }
            k--;
            sb = new StringBuilder(String.valueOf(sum)); 
        }
        return Integer.parseInt(sb.toString());
    }
}


// 2nd approach
class Solution {
    public int getLucky(String s, int k) {
        int sum1=0;
        StringBuilder sb = new StringBuilder();
        for(char ch : s.toCharArray()){
            int num = ch-96;
            while(num>0){ //log base 10 (num)
                sum1 += (num%10);
                num/=10;
            }
        }
        sb.append(sum1);
        while(k>1){ //k*z
            int sum=0;
            for(int i=0;i<sb.length();i++){  //z
                sum += (sb.charAt(i) - '0');
            }
            k--;
            sb = new StringBuilder(String.valueOf(sum)); 
        }
        return Integer.parseInt(sb.toString());
    }
}