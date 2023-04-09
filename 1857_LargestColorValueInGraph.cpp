#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

// ChatGPT created

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        const int n = colors.size();
        vector<vector<int>> adj(n);
        vector<vector<int>> cnt(n, vector<int>(26, 0)); // cnt[i][j] stores the number of nodes colored j in the subtree rooted at node i
        vector<int> indegree(n, 0);
        queue<int> q;
        int ans = 0, seen = 0;
        
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cnt[u][colors[u] - 'a']++;
            int curColor = cnt[u][colors[u] - 'a'];
            ans = max(ans, curColor);
            seen++;
            for (int v : adj[u]) {
                for (int j = 0; j < 26; j++) {
                    cnt[v][j] = max(cnt[v][j], cnt[u][j]);
                }
                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        if (seen < n) {
            return -1;
        } else {
            return ans;
        }
    }
};