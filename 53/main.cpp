#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// helper functions
void print_vec(vector<int> nums) {
    for (int num:nums) {
        cout << num << " ";
    }
    cout << "\n";
}

void print_matrix(vector<vector<int>> matrix) {
    for (auto vec:matrix) {
        for (int num:vec) {
            cout << num << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// add Solution class
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 使用dp解决 dp[i]表示以nums[i]及以前的数组中，以nums[i]为结尾的子数组的最大和
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for (int i=1; i<nums.size(); i++) {
            int prev = 0;
            if (dp[i-1] > 0) {
                prev = dp[i-1];
            }
            dp[i] = nums[i] + prev;
        }
        int max = nums[0];
        for (int i=0; i<nums.size(); i++) {
            if (dp[i] > max) {
                max = dp[i];
            }
        }
        return max;
    }
};

int main() {
    Solution s;
    // add
    vector<int> arr = {5,4,-1,7,8};
    cout << s.maxSubArray(arr) << "\n";
    return 0;
}