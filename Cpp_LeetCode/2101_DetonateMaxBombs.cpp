#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
	double distancia (vector<int>& bomba, vector<int>& pos){
		return sqrt(pow(bomba[0] - pos[0], 2) + pow(bomba[1] - pos[1], 2));
	}

	bool enRango (vector<int>& bomba, vector<int>& pos){
		return distancia(bomba, pos) <= bomba[2];
	}

    int maximumDetonation(vector<vector<int>>& bombs) {
		vector<vector<int>> g(bombs.size());

		for (int i = 0; i < bombs.size(); i++) {
			for (int j = 0; j < bombs.size(); j++) {
				if (i != j && enRango(bombs[i], bombs[j])){
					g[i].push_back(j);
				}
			}
		}

		int maxi = 0;
		queue<int> q;
		unordered_set<int> noV;
		unordered_set<int> vistosAhora;

		for (int i = 0; i < bombs.size(); i++) {
			noV.insert(i);
		}

		do{
			int cont = 1;
			auto it = noV.begin();
			auto b = *it;
			noV.erase(it);
			q.push(b);
			vistosAhora.insert(b);

			while (!q.empty()){
				int a = q.front();
				q.pop();
				for (int j : g[a]){
					if (vistosAhora.find(j) == noV.end()){
						q.push(j);
						if (noV.find(j) != noV.end()){
							noV.erase(j);
						}
						vistosAhora.insert(j);
						cont++;
					}
				}
			}
			vistosAhora.clear();
			maxi = max(maxi, cont);
		} while (!noV.empty());

		return maxi;
    }
};
