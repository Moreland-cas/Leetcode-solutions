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
    int calculate_for_one(vector<int>& position, int str_len) {
        // 在position首尾补充0和str_len
        position.insert(position.begin(), -1);
        position.push_back(str_len);
        // 对于中间每个元素计算相邻的乘积
        int sum = 0;
        for (int index=1; index < position.size()-1; index++) {
            sum += (position[index] - position[index-1]) * (position[index+1] - position[index]);
        }
        return sum;
    } 

    int uniqueLetterString(string s) {
        // 记录字符串中每个字符所出现的位置
        int str_len = s.size();
        unordered_map<char, vector<int>> map;
        int index = 0;
        for (char c: s) {
            map[c].push_back(index);
            index++;
        }
        int sum = 0;
        for (auto pair:map) {
            sum += calculate_for_one(pair.second, str_len);
        }
        return sum;
    }
};

int main() {
    Solution s;
    // add
    string test = "LEETCODE";
    cout << s.uniqueLetterString(test) << "\n";
    return 0;
}