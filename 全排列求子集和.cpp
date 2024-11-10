#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtrack(vector<int> &state, int target, vector<int> &choices, int start, vector<vector<int>> &res) {
    if (target == 0) {
        res.push_back(state);
        return;
    }
    for (int i = start; i < choices.size(); i++) {
        if (target - choices[i] < 0) {
            break;
        }
        if (i > start && choices[i] == choices[i - 1]) {
            continue;
        }

        state.push_back(choices[i]);
        backtrack(state, target - choices[i], choices, i + 1, res);
        state.pop_back();
    }
}

vector<vector<int>> subsetSumII(vector<int> &nums, int target) {
    vector<int> state;     
    sort(nums.begin(), nums.end()); 
    int start = 0;                  
    vector<vector<int>> res;        
    backtrack(state, target, nums, start, res);
    return res;
}
int main() {
    vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> res = subsetSumII(nums, target);
    for (const auto &subset : res) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "\n";
    }
    return 0;
}