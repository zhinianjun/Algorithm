#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int amount, n;
    while(cin >> amount >> n){
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
        if(dp[0][amount]==0)
        {
            cout << 0 << endl;
            continue;
        }
        cout << dp[0][amount] << endl;
        int t = amount;
        vector<int> path;
        for(int i=0; i<n; i++)
        {
            if(dp[i][t]==dp[i+1][t-costs[i]]+val[i])
            {
                path.push_back(i+1);
                t-=costs[i];
            }
        }
        for(size_t i=0; i<path.size(); i++)
        {
            cout << path[i];
            if(i!=path.size()-1)
                cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
