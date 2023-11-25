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

void print_map(unordered_map<int, int>& map) {
    for (auto pair:map) {
        cout << pair.first << ":" << pair.second << " ";
    }
    cout << "\n";
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int is_valid(unordered_map<int, int>& path_dict) {
        // 如果只有一项的数目是1，或者没有全都是偶数，那就没问题
        int odd = 0;
        for (int i=1; i<=9; i++) {
            if (path_dict[i] % 2 == 1) {
                odd++;
            }
        }
        if (odd >= 2) {
            return 0;
        }
        return 1;
    }
    int helper(TreeNode* cur_node, unordered_map<int, int>& cur_dict) {
        if (!cur_node) return 0;
        if ((!cur_node->left) && (!cur_node->right)) {
            // 结算
            cur_dict[cur_node->val]++;
            int out = is_valid(cur_dict);
            cur_dict[cur_node->val]--;
            return out;
        }
        cur_dict[cur_node->val]++;
        int out = helper(cur_node->left, cur_dict) + helper(cur_node->right, cur_dict);
        cur_dict[cur_node->val]--;
        return out;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int, int> path_dict;
        return helper(root, path_dict);
    }
};


int main() {
    Solution s;
    // add
    return 0;
}