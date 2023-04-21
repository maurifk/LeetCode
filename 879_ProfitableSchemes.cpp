#include <vector>
using namespace std;

int modulo = 1e9 + 7;

class Solution
{
public:
  int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
  {
    int m = group.size();
    vector<vector<vector<int>>> OPT(m + 1, vector(n + 1, vector(minProfit + 1, 0)));
    OPT[0][0][0] = 1;

    for (int i = 0; i < m; i++){
      for (int j = 0; j <= n; j++){
        for (int k = 0; k <= minProfit; k++){
          OPT[i + 1][j][k] = (OPT[i + 1][j][k] + OPT[i][j][k]) % modulo;
          if (j + group[i] <= n){
            int newProfit = min(k + profit[i], minProfit);
            OPT[i + 1][j + group[i]][newProfit] = (OPT[i + 1][j + group[i]][newProfit] + OPT[i][j][k]) % modulo;
          }
        }
      }
    }

    int ans = 0;
    for (int j = 0; j<=n; ++j){
      ans = (ans + OPT[m][j][minProfit]) % modulo;
    }

    return ans;
  }
};