#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int dfs(int i, int status, int n, vector<vector<int>>& valige, vector<vector<int>>& dp){
    if(status==(1<<n)-1)
        return valige[i][0];
    if(dp[i][status]!=-1)
        return dp[i][status];
    int ans = INT_MAX / 2;
    for(int j=0; j<n; j++){
        if((status&(1<<j)) == 0)
            ans = min(ans, dfs(j, status|(1<<j), n, valige, dp) +valige[i][j]);
    dp[i][status] = ans;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;

    int status = (1<<n)-1;
    vector<vector<int>> valige(n, vector<int>(n, 0));
    vector<vector<int>> dp(n, vector<int>((1<<n)-1, -1));
    
    for(int i = 0; i < n; i++)
        for(int j=0; j<n; j++)
            cin >> valige[i][j];       
    cout << dfs(0, 1, n, valige, dp) << endl;
    return 0;
}