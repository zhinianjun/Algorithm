#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int dfs(int i, int status, int n, vector<vector<int>>& valige, vector<vector<int>>& dp){
    if(dp[i][status]<INT_MAX/2)
        return dp[i][status];
    if(status==0)
        return valige[i][0];
    for(int t = 0; t < n-1; t++){
        if(status&(1<<t))
            dp[i][status] = min(dp[i][status], dfs(n-t-1, status^(1<<i), n, valige, dp)+valige[i][n-t-1]); 
    }
    return dp[i][status];
}

int main(){
    int n;
    cin >> n;

    int status = (1<<n)-1;
    vector<vector<int>> valige(n, vector<int>(n, 0));
    vector<vector<int>> dp(n+1, vector<int>(status+1, INT_MAX/2));
    
    for(int i = 0; i < n; i++)
        for(int j=0; j<n; j++)
            cin >> valige[i][j];       
    cout << dfs(0, status, n, valige, dp) << endl;
    for(int i=0; i < n; i++){
        for(int j=0; j <status; j++)
            cout << dp[i][j] << ' ';
        cout << endl;
    }
        
    
        
    return 0;
}