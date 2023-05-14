#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  bool estaAdentro (int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
  }

  int maxMoves(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> OPT(n, vector<int>(m, 0));
    for (int i = 0; i < m; ++i) {
      OPT[i][n-1] = 0;
    }

    vector<int> largos(3, 0);

    for (int j = m-2; j >= 0; --j) {
      for (int i = 0; i < n; ++i) {
        bool avance = false;
        if (estaAdentro(i-1, j+1, n, m) && grid[i-1][j+1] > grid[i][j]) {
          avance = true;
          largos[0] = OPT[i-1][j+1];
        } else {
          largos[0] = 0;
        }
        if (estaAdentro(i, j+1, n, m) && grid[i][j+1] > grid[i][j]) {
          avance = true;
          largos[1] = OPT[i][j+1];
        } else {
          largos[1] = 0;
        }
        if (estaAdentro(i+1, j+1, n, m) && grid[i+1][j+1] > grid[i][j]) {
          avance = true;
          largos[2] = OPT[i+1][j+1];
        } else {
          largos[2] = 0;
        }

        if (avance)
          OPT[i][j] = 1 + max(largos[0], max(largos[1], largos[2]));
        else OPT[i][j] = 0;
      }
    }

    int maxo = 0;
    for (int i = 0; i<m; ++i){
      maxo = max(maxo, OPT[i][0]);
    }
    return maxo;
  }
};

int main (){
  Solution* sol = new Solution();
  vector<vector<int>> grid = {{1000000,92910,1021,1022,1023,1024,1025,1026,1027,1028,1029,1030,1031,1032,1033,1034,1035,1036,1037,1038,1039,1040,1041,1042,1043,1044,1045,1046,1047,1048,1049,1050,1051,1052,1053,1054,1055,1056,1057,1058,1059,1060,1061,1062,1063,1064,1065,1066,1067,1068},{1069,1070,1071,1072,1073,1074,1075,1076,1077,1078,1079,1080,1081,1082,1083,1084,1085,1086,1087,1088,1089,1090,1091,1092,1093,1094,1095,1096,1097,1098,1099,1100,1101,1102,1103,1104,1105,1106,1107,1108,1109,1110,1111,1112,1113,1114,1115,1116,1117,1118}};
  cout<<sol->maxMoves(grid);

  return 0;
}

