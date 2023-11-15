#include <iostream>
#include <vector>
#include <limit>
using namespace std;




class Solution {
public:
    const int INF = numeric_limits<int>::max();

    void floydWarshall(vector<vector<int>>& dist, int V) {
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INF));
        for (int i=0; i<n; i++) {
            dist[i][i] = 0;
        }
        for (vector<int>& edge : edges) {
            int from, to, weight;
            from = edge[0];
            to = edge[1];
            weight = edge[2];
            dist[from][to] = weight;
            dist[to][from] = weight;
        }
        floydWarshall(dist, n);

        vector<int> nums (n, 0);
        int min_cities = n + 1;
        int index = -1;
        for (int i=0; i<n; i++) {
            int cur = 0;
            for (int j=0; j<n; j++) {
                if (dist[i][j] <= distanceThreshold) {
                    cur++;
                }
            }
            if (cur <= min_cities) {
                min_cities = cur;
                index = i;
            }
        }
        return i;
    }
};


int main(){
    cout << "Hello world!" << "\n";
}