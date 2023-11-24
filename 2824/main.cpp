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
    int countPairs(vector<int>& nums, int target) {
        int num = 0;
        for (int i=0; i<nums.size()-1; i++) {
            for (int j=i+1; j<nums.size(); j++) {
                if (nums[i] + nums[j] < target) {
                    num++;
                }
            }
        }
        return num;
    }
};

int main() {
    Solution s;
    // add
    return 0;
}