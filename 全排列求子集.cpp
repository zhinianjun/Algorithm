#include <iostream>
#include <vector>

using namespace std;

void backtrack(std::vector<int>& nums, int start, std::vector<int>& current, std::vector<std::vector<int>>& result) {
    result.push_back(current);
    for (int i = start; i < (int)nums.size(); ++i) {
        current.push_back(nums[i]);
        backtrack(nums, i + 1, current, result); 
        current.pop_back(); 
    }
}

std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::vector<int> current;
    backtrack(nums, 0, current, result);
    return result;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<std::vector<int>> subsetsResult = subsets(nums);
    for (const auto& subset : subsetsResult) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}
