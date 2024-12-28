#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

double dfs(int i, int j, double p, vector<vector<double>>& dp)
{
    if(i==0)
        return 1;
    if(j==0)
        return 0;
    if(dp[i][j]!=2)
        return dp[i][j];
    
    dp[i][j] = dfs(i-1, j, p, dp)*p + dfs(i, j-1, p, dp)*(1-p);
    return dp[i][j];
}

int main()
{
    int n;
    double p;
    while(cin >> n >> p){
        vector<vector<double>> dp(n+1, vector<double>(n+1, 2));
        cout << dfs(n, n, p, dp) << endl;
    }
    return 0;
}
