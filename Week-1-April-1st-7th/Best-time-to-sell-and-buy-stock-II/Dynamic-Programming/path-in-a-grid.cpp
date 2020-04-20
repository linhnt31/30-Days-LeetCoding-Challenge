"""Description
Our next problem is to find a path from the upper-left corner to the lower-right
corner of an n £ n grid, such that we only move down and right. Each square
contains a positive integer, and the path should be constructed so that the sum of
the values along the path is as large as possible.
"""

"""Solution
Because we can only move down or right 
---> sumAt(x, y) = max(sumAt(x-1, y), sumAt(x, y-1)) + valueAt[x][y]

"""

#include <bits/stdc++.h>

using namespace std;

int value[6][6];
int dp[6][6];
//Using recurrsion
//Time complexity: O(2^n) .... Space complexity:
int sumAt(int x, int y){
    if(x == 0 or y == 0){
        return 0;
    }
    return max(sumAt(x-1, y), sumAt(x, y-1)) + value[x][y];
}


// Using dynamic programming
//Time complexity: O(n^2) ... Space complexity: O(n)
// n is length of row and column
int sumAtDP(int x, int y){
    dp[0][1] = dp[1][0] = dp[0][0] = 0;
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + value[i][j];
        }
    }
    return dp[x][y];
}
int main()
{
    int x, y;
    cin >> x >> y;

    for(int i = 0; i < x; i++){
        for(int j = 0 ; j < y; j++){
            cin >> value[i][j];
        }
    }
    cout << "\n" << "Mang da nhap: " <<endl;
    for(int i = 0; i < x; i++){
        for(int j = 0 ; j < y; j++){
            cout << value[i][j] << " ";
        }
        cout << endl;
    }
    //int ans = sumAt(x, y);
    int ans = sumAtDP(x, y);
    cout << "Result: " << ans;

    return 0;
}
