#include <vector>
using namespace std;

class Solution {
public:
  bool posible(vector<vector<char>> &board, int x, int y, char n){
    bool posi = true;
    for (int i = 0; i < 9; ++i){
      if (board[i][y] == n)
        return false;
      if (board[x][i] == n)
        return false;
    }

    if (posi){
      int subfil = x / 3, subcol = y / 3;
      for (int j = 0; j < 3; ++j){
        for (int k = 0; k < 3; ++k){
          if (board[j + subfil * 3][k + subcol * 3] == n)
            return false;
        }
      }
    }
    return true;
  }

  bool solveSudoku(vector<vector<char>> &board){
    for (int i = 0; i < 9; ++i){
      for (int j = 0; j < 9; ++j){
        if (board[i][j] == '.'){
          for (char k = '1'; k <= '9'; ++k){
            if (posible(board, i, j, k)){
              board[i][j] = k;
              if (solveSudoku(board)){
                return true;
              }
              board[i][j] = '.';
            }
          }
          return false;
        }
      }
    }
    return true;
  }
};
