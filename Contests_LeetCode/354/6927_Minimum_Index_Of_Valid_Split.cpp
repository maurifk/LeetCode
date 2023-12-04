#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int dominante(vector<int>& vec, int bajo, int alto){
		unordered_map<int, int> mapa;
		int masfrec = -1;
		for (int i = bajo; i<alto+1; ++i){
			mapa[vec[i]]++;
			if(masfrec == -1){
				masfrec = vec[i];
			} else if (mapa[masfrec] < mapa[vec[i]]){
				masfrec = vec[i];
			}
		}

		if (mapa[masfrec] * 2 > (alto + 1  - bajo)){
			return masfrec;
		} else {
			return -1;
		}
	}

    int minimumIndex(vector<int>& nums) {
		unordered_map<int, int> freqBajo;
		unordered_map<int, int> freqAlto;
		int domAlto;
		int domBajo;
		int split = 0;

		if (nums.size() == 1) return -1;

		freqBajo[nums[split]] = 1;
		domBajo = nums[split];
		domAlto = nums[1];
		for (int i = 1; i<nums.size(); ++i){
			freqAlto[nums[i]]++;
			if (freqAlto[domAlto] < freqAlto[nums[i]]){
				domAlto = nums[i];
			}
		}
		if (freqAlto[domAlto]*2 > nums.size() - 1 && domAlto == domBajo){
			return 0;
		} else {
			while (split < nums.size() - 2){
				split++;
				freqBajo[nums[split]]++;
				freqAlto[nums[split]]--;

				if (freqBajo[domBajo]*2 <= split+1){
					for (auto it = freqBajo.begin(); it != freqBajo.end(); ++it){
						if (it->second > freqBajo[domBajo]){
							domBajo= it->second;
						}
					}
				}
				if (freqAlto[domAlto]*2 <= nums.size() - (split+1)){
					for (auto it = freqAlto.begin(); it != freqAlto.end(); ++it){
						if (it->second > freqAlto[domAlto]){
							domAlto = it->second;
						}
					}
				}
				if ((freqBajo[domBajo] * 2 > split + 1) && (freqAlto[domAlto] * 2 > nums.size() - (split+1)) && (domAlto == domBajo)){
					return split;
				}
			}
			return -1;
		}
    }
};
