#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Node{
    int count;
    int sumV;
}node;

int main(){
    int n, capcity;
    while(cin >> n >> capcity){
        vector<int> weight(n);
        vector<vector<node>> dp(n+1, vector<node>(capcity+1, {0, 0}));
        
        for(int i=0; i<n; i++)
            cin >> weight[i];
            
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<=capcity; j++){
                if(j<weight[i])
                    dp[i][j] = dp[i+1][j];
                else
                {
                    if((dp[i+1][j-weight[i]].count+1)>dp[i+1][j].count || ((dp[i+1][j-weight[i]].count+1)==dp[i+1][j].count&& (dp[i+1][j-weight[i]].sumV+weight[i])>dp[i+1][j].sumV)){
                        dp[i][j].count=dp[i+1][j-weight[i]].count+1;
                        dp[i][j].sumV=dp[i+1][j-weight[i]].sumV+weight[i];
                    }
                    else 
                    dp[i][j] = dp[i+1][j];
                }
            }
        }

        cout << dp[0][capcity].count << ' ' <<dp[0][capcity].sumV << endl;

        if(dp[0][capcity].count>0){
            int t = capcity;
            vector<int> path;
            for(int i=0; i<n; i++){
                if((dp[i][t].sumV == dp[i+1][t-weight[i]].sumV+weight[i]) && (dp[i][t].count == dp[i+1][t-weight[i]].count+1)){
                    path.push_back(weight[i]);
                    t-=weight[i];
                }   
            }
            for(size_t i=0; i<path.size(); i++)
            {
                cout << path[i];
                if(i!=path.size()-1)
                    cout << ' ';
            }
        }
        
        cout << '\n';
    }
    return 0;
}