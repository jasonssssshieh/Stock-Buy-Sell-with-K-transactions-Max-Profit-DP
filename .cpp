//
//  main.cpp
//  Stock Buy & Sell with K transactions Max Profit DP
//
//  Created by Zijian Xie on 2016/11/17.
//  Copyright © 2016年 Jason Xie. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class StockBuySellKtransactions{
private:
    int k;
    vector<int> prices;
public:
    StockBuySellKtransactions(int k, vector<int>prices){
        this->k = k;
        this->prices = prices;
    }
    
    int DP(){
        /*
        dp[i][j]代表了在第j天已经有了i次交易。
         那么对于dp[i][j]而言就有两种可能：1. 我当天不交易，那么就等于前一天的结果dp[i][j-1]
         2. 我当天有交易，sell，那么我一定在某一天有buy的行为，那么假设我们在第m天buy，那么我们的profit是多少呢？
         1. 股票买卖的收入： price[j] - price[m]//这里已经用掉了一次交易，那么还剩下i-1次交易
         2. 在买这个股票之前的收入，那么也就是说我们到m天为止，就一定有了i-1此交易，所以dp[i-1][m]
         for m = 0,1,2,```,j-1
         取两者最大的即可
         */
        int n = (int)prices.size();
        vector<vector<int>> dp(k+1,vector<int>(n,0));
        for(int i = 1; i <= k; ++i){
            for(int j = 1; j < n; ++j){
                dp[i][j] = dp[i][j-1];
                for(int m = 0; m < j; ++m){
                    dp[i][j] = max(dp[i][j], prices[j] - prices[m] + dp[i-1][m]);
                }
            }
        }
        cout<<"The max profit with k = "<<k<<" times transactions is: "<<dp[k-1][n-1]<<endl;;
        return dp[k][n-1];
    }
};

int main(int argc, const char * argv[]) {
    int k = 3;
    vector<int> prices = {2,5,7,1,4,3,1,3};
    StockBuySellKtransactions test(k,prices);
    test.DP();
    return 0;
}
