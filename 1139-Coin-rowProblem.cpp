#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dfs(int i, vector<int>& nums, vector<int>& mem){
    if(i<0)
        return 0;
    if(mem[i]!=-1)
        return mem[i];
    else
        mem[i] = max(dfs(i-1, nums, mem), dfs(i-2, nums, mem)+nums[i]);
    return mem[i];
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> mem(n, -1);
    for(int i=0; i<n; i++)
        cin >> nums[i];
    
    cout << dfs(n-1, nums, mem) << endl;
    return 0;
}
