/*Description
In the coin change problem, we are asked both to find  what is the smallest number of coins required to form a sum x?
and to print a solution can be constructed.
*/

/*Solution
dp(x) denotes the smallest number of coins we can form the sum x
first(x) denotes the first coin chose
example: coins = [1,3,4] ---> dp[x] = min(dp[x-c]+1) with c in coins
- If x < 0 ---> INF. Because it is impossible to form a negative sum of money
- It x = 0 ---> no coins are needed to form it 

*/
#include<bits/stdc++.h>

using namespace std;

void extendedCoinChange(int *coins, int size, int amount){
	if(amount < 0 ){
		cout << "It is negative value !!!";
		return;
	}
	if(amount == 0){
		cout << "We dont have any way to form the sum 0";
	}
	
	int dp[amount + 1], first[amount + 1];
	fill_n(dp, amount + 1, INT_MAX);
	fill_n(first, amount + 1, INT_MAX);
	
	dp[0] = first[0] = 0;
	for(int i = 0 ; i < size; ++i){
		for(int x = coins[i]; x <= amount; x++){
			if(dp[x] > dp[x - coins[i]] + 1){
				dp[x] = dp[x - coins[i]] + 1;
				first[x] = coins[i];
			}
		}
	}
	cout << "The smallest number of ways to form the sum x: " << dp[amount] << "\n";
	cout << "To form the sum x, we use coins: ";
	while(amount > 0){
		cout << first[amount] << "   ";
		amount -= first[amount];
	}		
}
int main(){
	int coins[] = {1, 3, 4};
	extendedCoinChange(coins, 3, 10);
	return 0;
}
