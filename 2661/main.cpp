#include <vector>
#include <iostream>
#include <algorithm>
#include<unordered_map>

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
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> map; // 存储每个数的行列位置
        int num_rows = mat.size();
        int num_cols = mat[0].size();

        for (int i=0; i<num_rows; i++) {
            for (int j=0; j<num_cols; j++) {
                map[mat[i][j]] = {i, j};
            }
        }
        vector<int> cols (num_cols, 0);
        vector<int> rows (num_rows, 0);
        for (int i=0; i<num_cols*num_rows; i++) {
            // 添加
            int cur_num = arr[i];
            int row = map[cur_num].first;
            int col = map[cur_num].second;
            cols[col]++;
            rows[row]++;
            if ((cols[col]>=num_rows) || (rows[row]>=num_cols)) {
                return i;
            }
        }
        return 0;
    }
};

int main() {
    Solution s;
    // add
    return 0;
}