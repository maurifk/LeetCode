#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    pair<int, int> findMin(vector<vector<int>>& mat, int i, int j) {
        int m = mat.size();
        int n = mat[0].size();
        int min_i = i;
        int min_j = j;

        for (int k = 0; k < m; k++) {
            if (mat[k][j] < mat[min_i][min_j]) {
                min_i = k;
                min_j = j;
            }
        }
        for (int k = 0; k < n; k++) {
            if (mat[i][k] < mat[min_i][min_j]) {
                min_i = i;
                min_j = k;
            }
        }
        return {min_i, min_j};
    }

    vector<pair<int, int>> masCercanos(vector<vector<int>>& mat, int i, int j) {
        int m = mat.size();
        int n = mat[0].size();
        int min_i = i;
        int min_j = j;
        int dist = -1;
        vector<pair<int, int>> res;

        for (int k = 0; k < m; k++) {
            if (mat[k][j] < mat[min_i][min_j] && (dist == -1 || mat[i][j] - mat[k][j] < dist)) {
                res.clear();
                min_i = k;
                min_j = j;
                dist = mat[i][j] - mat[k][j];
                res.push_back({k, j});
            } else if (mat[k][j] < mat[min_i][min_j] && (dist == -1 || mat[i][j] - mat[k][j] == dist)){
                res.push_back({k, j});
            }
        }
        for (int k = 0; k < n; k++) {
            if (mat[i][k] < mat[min_i][min_j] && (dist == -1 || mat[i][j] - mat[i][k] < dist)) {
                res.clear();
                min_i = i;
                min_j = k;
                dist = mat[i][j] - mat[i][k];
                res.push_back({i, k});
            } else if (mat[i][k] < mat[min_i][min_j] && (dist == -1 || mat[i][j] - mat[i][k] == dist)){
                res.push_back({i, k});
            }
        }
        return res;
    }

    int maxIncreasingCells(vector<vector<int>>& mat) {
        vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), -1));
        int m = mat.size();
        int n = mat[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pair<int, int> min_pos = findMin(mat, i, j);
                if (min_pos.first == i && min_pos.second == j) {
                    dp[i][j] = 1;
                }
            }
        }
        int max_cont = 0, cont;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cont = 1;
                if (dp[i][j] == 1) {

                    pair<int, int> ant = {i,j};
                    vector<pair<int, int>> min_pos = masCercanos(mat, i, j);
                    queue<pair<int, pair<int, int>>> q;

                    for (auto p : min_pos){
                        q.push({1, p});
                    }

                    while (!q.empty()) {
                        pair<int, pair<int, int>> aux = q.front();
                        q.pop();
                        dp[aux.second.first][aux.second.second] = aux.first+1;
                        vector<pair<int, int>> min_pos_aux = masCercanos(mat, aux.second.first, aux.second.second);
                        for (auto p : min_pos_aux){
                            // @TODO
                        }
                    }


                    if (cont > max_cont) {
                        max_cont = cont;
                    }
                }
            }
        }
        return max_cont;
    }
};
