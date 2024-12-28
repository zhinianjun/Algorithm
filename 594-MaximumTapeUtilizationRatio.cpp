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
    cin >> n >> capcity;
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
    
    return 0;
}