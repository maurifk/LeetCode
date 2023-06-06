#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
		vector<vector<int>> g(isConnected.size());
		unordered_set<int> noV;

		for (int i = 0; i < isConnected.size(); i++){
			for (int j = i+1; j < isConnected.size(); j++){
				if (isConnected[i][j] == 1){
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}

			noV.insert(i);
		}

		int cant = 0;
		queue<int> q;

		do {
			int v = *noV.begin();
			noV.erase(noV.begin());
			q.push(v);

			while(!q.empty()){
				v = q.front();
				q.pop();
				for(int u : g[v]){
					if (noV.find(u) != noV.end()){
						q.push(u);
						noV.erase(u);
					}
				}
			}
			cant++;
		} while (!noV.empty());

		return cant;
    }
};
