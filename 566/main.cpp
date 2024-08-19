#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

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
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int num_rows = mat.size();
        int num_cols = mat[0].size();
        if (num_rows * num_cols != r * c) {
            return mat;
        }
        vector<vector<int>> return_mat(r, vector<int>(c, 0));
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                // 获取对应的元素在原始矩阵中的位置
                int row = (i * c + j) / num_cols;
                int col = (i * c + j) % num_cols;
                return_mat[i][j] = mat[row][col];
            }
        }
        return return_mat;
    }
};

int main() {
    Solution s;
    // add
    vector<vector<int>> mat = {{1,2},{3,4}};
    print_matrix(s.matrixReshape(mat, 4, 1));
    return 0;
}