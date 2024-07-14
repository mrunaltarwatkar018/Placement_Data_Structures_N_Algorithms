/*  Problem oN.: Function Pointers as a comparators  */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// bool myComparator(int a, int b) {
//     // if ( a < b) //  ascending order
//     if ( a > b) //  decending order
//         return true;
    
//     return false;
// }

void print(vector<pair<int, int>> &vec) {
    for ( pair<int, int> &p : vec) {
        cout << p.first << ", " << p.second << " : ";
    }
    cout << endl;
}

// // MAin Function
int main() {
    vector<pair<int, int>> vec = {{2, 3}, {2, 4}, {3, 1}};


    // sort(begin(vec), end(vec), myComparator);
    sort(begin(vec), end(vec));

    // print(vec);

    return 0;
}































// bool myComparator(int a, int b) {
//     // if ( a < b) //  ascending order
//     if ( a > b) //  decending order
//         return true;
    
//     return false;
// }

// void print(vector<int> &vec) {
//     for ( int &x : vec) {
//         cout << x << " ";
//     }
//     cout << endl;
// }

// // MAin Function
// int main() {
//     vector<int> vec = {1, 3, 5, 6, 2};

//     // sort(begin(vec), end(vec));
//     // or u can write as
//     // sort(vec.begin(), vec.end());
//     // this sor can be sort by default in ascensing order

//     sort(begin(vec), end(vec), myComparator);

//     print(vec);

//     return 0;
// }