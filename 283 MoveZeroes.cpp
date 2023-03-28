#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void cambiarDos(vector<int>& nums, int i1, int i2){
        int temp = nums[i1];
        nums[i1] = nums[i2];
        nums[i2] = temp;
    }

    void moveZeroes(vector<int>& nums) {
        int i1 = 0, i2 = 1;
        while ((i1 < i2) && (i2 < nums.size())){
            while (nums[i1] != 0){
                i1++;
                if (i1 >= nums.size()) return;
            }
            
            i2 = i1;
            while ((i2 < nums.size()) && (nums[i2] == 0)){
                i2++;
            }
            
            if(i2 >= nums.size()) return;
            cambiarDos(nums, i1, i2);
        }
    }
};