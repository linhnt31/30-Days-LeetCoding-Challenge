// Time complexity: O(xlogn)  - x is a specific value
// Space complexity: O(1)
// Reference : https://cp-algorithms.com/algebra/primality_tests.html
// Link Leetcode: https://leetcode.com/problems/count-primes/
class Solution {
public:
    // O(square root of x)
    bool isPrime(int x){
        // Note: The only even prime number is 2
        if(x != 2 && x % 2 == 0) return false;
        
        /* For example, we suppose:
        n % d == 0 ---- > n % (n/d) == 0 
        We must remember that the largest square root value of n is square root of n
        ---> d <= square root of n and n/d <= square root of n
        */
        for(int i = 2; i*i <= x ;i++){
            if(x % i == 0){
                return false;
            }
        }
        return true;
    }
    int countPrimes(int n) {
        int ans = 0;
        for(int i = 2; i < n ; i++){
            if(isPrime(i)){
                ans += 1;
            }
        }
        return ans;
    }
};
