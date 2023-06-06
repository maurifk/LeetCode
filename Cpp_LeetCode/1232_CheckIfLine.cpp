#include <vector>
using namespace std;

class Solution {
public:
	int calcDeltaX(vector<int>& a, vector<int>& b){
		return a[0] - b[0];
	}

	int calcDeltaY(vector<int>& a, vector<int>& b){
		return a[1] - b[1];
	}

	bool checkStraightLine(vector<vector<int>>& coordinates) {
		int deltaX = calcDeltaX(coordinates[0], coordinates[1]);
		int deltaY = calcDeltaY(coordinates[0], coordinates[1]);

		for (int i = 2; i < coordinates.size(); ++i){
			if ((deltaY * calcDeltaX(coordinates[0], coordinates[i])) != deltaX * calcDeltaY(coordinates[0], coordinates[i]))
				return false;
		}
		return true;
	}
};
