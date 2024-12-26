#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfss(int i, int status, int n, vector<vector<int>>& valige){
    if(status==0)
        return valige[i][0];
    int res = INT_MAX / 2;
    for(int t = 0; t < n-1; t++){
        if(status&(1<<t))
            res = min(res, dfss(n-t-1, status^(1<<i), n, valige)+valige[i][n-t-1]);
        
    }
    return res;
}

int main(){
    int n;
    
    cin >> n;
    vector<vector<int>> valige(n, vector<int>(n, 0));
    int status = (1<<n)-1;
    for(int i = 0; i < n; i++)
        for(int j=0; j<n; j++)
            cin >> valige[i][j];
    cout << dfss(0, status, n, valige) << endl;
    return 0;
}