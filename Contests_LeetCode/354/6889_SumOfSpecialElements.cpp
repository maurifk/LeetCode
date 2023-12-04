#include <vector>
using namespace std;

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
		int suma = 0;
		for (int i = 0; i < nums.size(); ++i){
			if ( nums.size() % (i+1) == 0){
				suma += (nums[i] * nums[i]);
			}
		}
		return suma;
    }
};
