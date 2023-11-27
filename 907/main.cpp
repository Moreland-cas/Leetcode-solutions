#include <vector>
#include <iostream>
#include <algorithm>
#include<unordered_map>
#include <cmath>

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
    int constant = pow(10, 9) + 7;
    int sumSubarrayMins(vector<int>& arr) {
        // dp[i]表示以arr[i]为结尾的所有数组的子数组最小值的和
        vector<int> dp (arr.size(), 0);
        dp[0] = arr[0] % constant;
        for (int i=1; i<arr.size(); i++) {
            dp[i] = arr[i];
        }
        int output = 0;
        for (auto num:arr) {
            output += num;
        }
        return output;
    }
};


int main() {
    Solution s;
    // add
    vector<int> arr = {11,81,94,43,3};
    cout << s.sumSubarrayMins(arr) << "\n";
    return 0;
}