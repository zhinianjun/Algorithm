#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
    int amount, n;
        cin >> amount >> n;
        vector<int> costs(n);
        vector<int> val(n);
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        for(int i=0; i<n; i++)
            cin >> costs[i] >> val[i];

        for(int i=0; i<n; i++){
            for(int j=0; j<amount;j++){
                if(j<costs[i])
                    dp[i+1][j+1] = dp[i][j+1];
                else
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i][j-costs[i]+1]+val[i]);
            }
        }
        
    
        cout << dp[n][amount] << endl;
       

    return 0;
}
