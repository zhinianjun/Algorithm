#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums(n, vector<int>(m));
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> nums[i][j];
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j])+nums[i][j];
    
    cout << dp[n][m] << endl;
    return 0;
}
