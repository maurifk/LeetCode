#include <vector>

using namespace std;

class Solution {
public:
	// In C++ since Java did the same but ended in TLE since everything is passed by value
    bool special (vector<vector<int>>& mat, int i, int j) {
        bool res = true;
        for (int l = 0; l < mat.size(); ++l) {
            if (l == i) continue;
            if (mat[l][j] == 1 || mat[l][j] == -1) {
                mat[l][j] = -1;
                res = false;
            }
        }
        for (int l = 0; l<mat[0].size(); ++l) {
            if (l == j) continue;
            if (mat[i][l] == 1 || mat[i][l] == -1) {
                mat[i][l] = -1;
                res = false;
            }
        }
        return res;
    }

    int numSpecial(vector<vector<int>>& mat) {
        int res = 0;
        for (int i = 0; i<mat.size(); ++i){
            for (int j = 0; j<mat[0].size(); ++j) {
                if (mat[i][j] == 1) {
                    if (special(mat, i, j))
                        res++;
                }
            }
        }
        return res;
    }
};
