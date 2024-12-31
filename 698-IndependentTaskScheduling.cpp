#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
    int n, sumA=0;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        sumA+=a[i];
    }
        
    for(int i=0; i<n; i++)
        cin >> b[i];
    vector<vector<int>> dp(n+1, vector<int>(sumA+1, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<=sumA; j++){
            if(j<a[i])
                dp[i+1][j] = dp[i][j]+b[i];
            else
                dp[i+1][j] = min(dp[i][j]+b[i], dp[i][j-a[i]]);
            
        }
    }
    int t = INT_MAX, res=0;
    for(int j=0; j<=sumA; j++){
        if(abs(j-dp[n][j])<t)
        {
            t=abs(j-dp[n][j]);
            res=dp[n][j];
        }
    }
    cout << res << endl;
    return 0;
}