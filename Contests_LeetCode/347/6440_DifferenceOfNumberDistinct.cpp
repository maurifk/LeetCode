#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int contarDistintosDiagS(vector<vector<int>>& grid, int i, int j) {
        unordered_set<int> distintos;
        i--; j--;
        while (i >= 0 && j >= 0) {
            distintos.insert(grid[i][j]);
            i--; j--;
        }
        return distintos.size();
    }

    int contarDistintosDiagI(vector<vector<int>>& grid, int i, int j) {
        unordered_set<int> distintos;
        i++;
        j++;
        while (i < grid.size() && j < grid[0].size()) {
            distintos.insert(grid[i][j]);
            i++; j++;
        }
        return distintos.size();
    }

    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size(), 0));
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                ans[i][j] = abs(contarDistintosDiagS(grid, i, j) - contarDistintosDiagI(grid, i, j));
            }
        }

        return ans;
    }
};
