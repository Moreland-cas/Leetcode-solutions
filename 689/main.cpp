#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void print_vec(vector<int> nums) {
    for (int num:nums) {
        cout << num << " ";
    }
    cout << "\n";
}

void print_matrix(vector<vector<int>> dp) {
    for (auto vec:dp) {
        for (int num:vec) {
            cout << num << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}


class Solution {
public:
    bool is_bigger(int last1, int last2, int j, const vector<vector<int>>& index) {
        //比较两种递归方案s1和s2的字典序，如果s2更小，返回True
        vector<int> s1;
        vector<int> s2;
        while (j>0) {
            s1.push_back(last1);
            s2.push_back(last2);
            last1 = index[last1][j-1];
            last2 = index[last2][j-1];
            j--;
        }
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        return (s1 > s2);
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    // int maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        // 构建sums数组,sums[i]代表前i个数的和
        int n = nums.size();
        vector<int> sums(n + 1, 0);
        for (int i=1; i<=n; i++) {
            sums[i] = sums[i-1] + nums[i-1];
        }
        // print_vec(sums);
        // 初始化dp数组和index数组
        // dp[i][j]代表前i个数里，j个长度为k的子数组可能的最大和
        // index[i][j]代表当前问题设置下，第j个数组的起始位置
        vector<vector<int>> dp(n + 1, vector<int>(4, 0));
        vector<vector<int>> index(n + 1, vector<int>(4, -1));
        // 更新dp数组和index数组
        // dp[i][j] = max{ dp[i-1][j], dp[i-k][j-1] + sums[i]-sums[i-k] }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=3; j++) {
                if (i < j * k) {
                    continue;
                }
                int use_last = dp[i-k][j-1] + sums[i] - sums[i-k];
                int drop_last = dp[i-1][j];
                // 根据两者大小分类
                if (use_last > drop_last) {
                    dp[i][j] = use_last;
                    index[i][j] = i-k;
                }
                else if (use_last < drop_last) {
                    dp[i][j] = drop_last;
                    index[i][j] = index[i-1][j];
                }
                else { //两者相等需要特殊处理，取出字典序小的那个
                    dp[i][j] = drop_last;
                    // 比较字典序
                    // use_last => index[i-k][j-1], i-k
                    // drop_last => index[last][j-1], last=index[i-1][j]
                    int last1 = i-k;
                    int last2 = index[i-1][j];
                    if (is_bigger(last1, last2, j, index)) {
                        index[i][j] = index[i-1][j];
                    }
                    else {
                        index[i][j] = i-k;
                    }
                }
            }
        }
        // print_matrix(dp);
        // return dp[n][3];
        // 回溯index数组返回结果
        vector<int> result;
        int third = index[n][3];
        int second = index[third][2];
        int first = index[second][1];

        result.push_back(first);
        result.push_back(second);
        result.push_back(third);
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,1,2,6,7,5,1};
    int k = 2;
    // cout << s.maxSumOfThreeSubarrays(nums, k) << "\n";
    print_vec(s.maxSumOfThreeSubarrays(nums, k));
    return 0;
}