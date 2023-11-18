#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution {
public:
    int num_sum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += (num % 10);
            num = num / 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        // 找到所有i, j， 使得 num_sum(nums[i]) = num_sum(nums[j])
        unordered_map<int, vector<int>> hashmap;
        for (int num:nums) {
            hashmap[num_sum(num)].push_back(num);
        }
        // 返回最大的num_sum
        int max_num_sum = -1;
        for (auto& pair:hashmap) {
            int len = pair.second.size();
            if (len >= 2) {
                sort(pair.second.begin(), pair.second.end());
                int cur = pair.second[len-1] + pair.second[len-2];
                if (cur > max_num_sum) {
                    max_num_sum = cur;
                }
            }
        }
        return max_num_sum;
    }
};

int main() {
    vector<int> nums = {18,43,36,13,7};
    Solution s;
    std::cout << s.maximumSum(nums) << "\n";
    return 0;
}