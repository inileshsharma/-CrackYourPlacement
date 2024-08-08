class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int lft = 0, rgt = 0;


        while(rgt < nums.size()){

            if(nums[rgt] != 0){
                swap(nums[rgt],nums[lft]);
                lft++;
            }
            rgt++;
        }

    }
};
