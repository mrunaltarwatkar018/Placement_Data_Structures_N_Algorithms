/* Leetcode Problem No.: 2678. Number of Senior Citizens */

/*
    Company Tags                 : Facebook | Amazon | Microsoft | Netflix | Google | LinkedIn | Pega Systems | VMware | Adobe | Samsung
    Leetcode Qn Link             : https://leetcode.com/problems/number-of-senior-citizens/description/?envType=daily-question&envId=2024-08-01
*/


/************************* C++ *************************/
//T.C : O(n) where n = length of details
//S.C : O(1)
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;

        for(string &detail : details) {
            int secondDigit = detail[11] - '0';
            int firstDigit  = detail[12] - '0';

            int age         = secondDigit*10 + firstDigit;

            if(age > 60)
                count++;
        }

        return count;
    }
};




/************************* JAVA *************************/
//T.C : O(n) where n = length of details
//S.C : O(1)
class Solution {
    public int countSeniors(String[] details) {
        int count = 0;

        for (String detail : details) {
            int secondDigit = detail.charAt(11) - '0';
            int firstDigit = detail.charAt(12) - '0';

            int age = secondDigit * 10 + firstDigit;

            if (age > 60) {
                count++;
            }
        }

        return count;
    }
}