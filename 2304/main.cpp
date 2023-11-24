#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

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
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp (m, vector<int>(n, INT_MAX));
        // 填充dp表格
        // 第一行填充自己
        for (int j=0; j<n; j++) {
            dp[0][j] = grid[0][j];
        }
        // 之后每一行根据上一行计算
        for (int i=1; i<m; i++) {
            for (int j=0; j<n; j++) {
                int min_cost_so_far = INT_MAX;
                for (int k=0; k<n; k++) {
                    int cur_cost = dp[i-1][k] + moveCost[grid[i-1][k]][j];
                    if (cur_cost < min_cost_so_far) {
                        min_cost_so_far = cur_cost;
                    }
                }
                dp[i][j] = min_cost_so_far + grid[i][j];
            }
        }
        // 输出最后一行最小值
        int min_out = INT_MAX;
        for (int j=0; j<n; j++) {
            if (dp[m-1][j]<min_out) {
                min_out = dp[m-1][j];
            }
        }
        return min_out;
    }
};


int main() {
    Solution s;
    // add
    std::vector<std::vector<int>> grid = {{2, 3}, {1, 0}};
    std::vector<std::vector<int>> moveCost = {{9, 8}, {1, 5}, {10, 12}, {18, 6}};
    cout << s.minPathCost(grid, moveCost) << "\n";
    return 0;
}