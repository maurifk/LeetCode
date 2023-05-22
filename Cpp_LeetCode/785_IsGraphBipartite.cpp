#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  bool isBipartite(vector<vector<int>>& graph) {
    // BFS
    queue<int> q;
    vector<int> color(graph.size(), -1);

    int first = 0;
    do {
      color[first] = 0;
      q.push(first);

      while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
          for (int i = 0; i < graph[cur].size(); i++) {
            if (color[graph[cur][i]] == color[cur]) {
              return false;
            }
          }
          if (color[next] == -1) {
            color[next] = 1 - color[cur];
            q.push(next);
          }
        }
      }

      while (first < graph.size() && color[first] != -1) {
        first++;
      }
    } while (first < graph.size());

    return true;
  }
};
