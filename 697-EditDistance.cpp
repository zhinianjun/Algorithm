#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dfs(int i, int j, string& str1, string& str2, vector<vector<int>>& mem){
    if(i<0)
        return j+1;
    if(j<0)
        return i+1;
    if(mem[i][j]!=-1) return mem[i][j];
    if(str1[i]==str2[j])
        mem[i][j]=dfs(i-1, j-1, str1, str2, mem);
    else 
        mem[i][j] = min({dfs(i, j-1, str1, str2, mem), dfs(i-1, j, str1, str2, mem), dfs(i-1, j-1, str1, str2, mem)})+1;
    return mem[i][j];
}
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    int n = str1.size(), m = str2.size();
    vector<vector<int>> mem(n, vector<int>(m, -1));
    cout << dfs(n-1, m-1, str1, str2, mem) << endl;
    return 0;
}
