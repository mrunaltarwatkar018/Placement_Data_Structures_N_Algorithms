/* Leetcode Problem No.: 860. Lemonade Change  */

/*
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/lemonade-change
*/


/*************************************************************** C++ ********************************************************/
// Simply Simulation
// T.C : O(n)
// S.C : O(1)


/*
    Summary :

        The code above implements a solution to the Lemonade Change problem. The goal 
        is to determine if you can provide the correct change to each customer in a 
        line given an initial cash register with no money.

        Input: 
            An array of integers bills, where each element represents the bill a 
            customer gives (either $5, $10, or $20).

        Output: 
            A boolean value indicating whether you can give back the correct change to 
            each customer.

        Logic:

            You start with no $5 or $10 bills.

        As you process each bill:
            If the customer gives a $5 bill, you simply store it.

            If the customer gives a $10 bill, you need to return one $5 bill as 
            change. If you have one, you give it back and store the $10 bill.

            If the customer gives a $20 bill, you try to return one $10 and one $5 
            bill (if available). If not, you try to return three $5 bills. If neither 
            is possible, you return false.

            The solution ensures you always provide the correct change, and if you 
            can't at any point, it returns false. If you can process all customers, it 
            returns true.
*/


class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int count_of_five = 0;
        int count_of_ten = 0;

        for ( int & bill : bills ) {
            if ( bill == 5 ) {
                count_of_five++;
            } else if ( bill == 10 ) { // return  $5 to the customer
                if ( count_of_five > 0 ) {
                    count_of_five--;
                    count_of_ten++;
                } else {
                    return false;
                }
            } else if ( count_of_five > 0 && count_of_ten > 0 ) { // return  $15 to the customer
                count_of_five--;
                count_of_ten--;
            } else if ( count_of_five >= 3 ) { // so we can return here $5, $5, $5 to the customer
                count_of_five -= 3;
            } else {
                return false;
            }
        }

        return true;
        
    }
};

// another way

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten  = 0;


        for(int &bill : bills) {
            if(bill == 5) {
                five++;
            } else if(bill == 10) { //return 5$ to customer
                if(five > 0) {
                    five--;
                    ten++;
                } else {
                    return false;
                }
            } else if(five > 0 && ten > 0) { //return 15$ to customer
                five--;
                ten--;
            } else if(five >= 3) { //5, 5, 5
                five -= 3;
            } else {
                return false;
            }
        }

        return true;
    }
};


/*************************************************************** JAVA ********************************************************/
//Simply Simulation
//T.C : O(n)
//S.C : O(1)
class Solution {
    public boolean lemonadeChange(int[] bills) {
        int five = 0;
        int ten  = 0;

        for (int bill : bills) {
            if (bill == 5) {
                five++;
            } else if (bill == 10) { // return $5 to customer
                if (five > 0) {
                    five--;
                    ten++;
                } else {
                    return false;
                }
            } else if (five > 0 && ten > 0) { // return $15 to customer
                five--;
                ten--;
            } else if (five >= 3) { // $5, $5, $5
                five -= 3;
            } else {
                return false;
            }
        }

        return true;
    }
}



















/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=sYHJEPs9sSE
*/