// Dutch national flag

class Solution {
public:
    void sortColors(vector<int>& nums){

        int i = 0, s = 0, e = nums.size()-1;

        while(i<=e){

            if(nums[i] == 2){

                swap(nums[i],nums[e]);
                e--;
            }
            else if(nums[i] == 0){

                swap(nums[i], nums[s]);
                s++;
                i++;
            }
            else{
                i++;
            }

        }
    }
};
