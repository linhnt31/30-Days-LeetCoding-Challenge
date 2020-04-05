#include <bits/stdc++.h>

using namespace std;
/* 
we know that after the first repetition, we have the maximum value = 10*9^2 = 810
(int) [2147483647]
*/
//Time complexity of this func: O(logn)
int square(int n){
    int total = 0;
    while(n){
        int tmp = n % 10;
        n /= 10;
        total += tmp * tmp;
    }
    return total;
}

// In here, i want to caculate the maximum of repetiton.
int isHappy(int n){
    unordered_set <int> check; // check infinite loop [1]

    for(int rep = 0; rep <= 810; rep++){ // So rep = 19 is enough [*]
        if(n == 1){
            return rep;
        }
        n = square(n);
        if(check.count(n) == 1){ // [2]
            return rep;
        }
        check.insert(n);
    }
}
int main()
{
    int n; cin >> n;
    int m = 0;
    // Caculating the numbers of repetitions
    for(int n = 0; n < 811; n++){
        m = max(m, isHappy(n));
    }
    cout << "The maximum repetition is: " << (m + 1)<< endl; //[*] must plus the first repetiton.

    return 0;
}


// Standard solution on Leetcode
class Solution {
    int square(int n){
        int total = 0;
        while(n){
            int digit = n % 10;
            total += digit * digit;
            n /= 10;
        }
        return total;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> check;
        for(int rep = 0; rep < 19; rep++){
            if(n == 1){
                return true;
            }
            n = square(n);
            if(check.count(n) == 1){
                return false;
            }
            check.insert(n);
        }
        return false;
    }
};

