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

for(int i=n-1; i >=0; i--){
    for(int j=0; j<=amount;j++){
    if(j<costs[i])
    dp[i][j] = dp[i+1][j];
    else
    dp[i][j] = max(dp[i+1][j], dp[i+1][j-costs[i]]+val[i]);
}
}
    
    cout << dp[0][amount] << endl;
int t = amount;
    for(int i=0; i<n; i++)
    {
        if(dp[i][t]==dp[i+1][t-costs[i]]+val[i])
        {
            cout<< i+1 << ' ';
            t-=costs[i];
        }
    }
    return 0;
}
