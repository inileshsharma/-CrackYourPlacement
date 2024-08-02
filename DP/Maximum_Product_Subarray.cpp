class Solution {
public:
    int maxProduct(vector<int>& nums) {

        double maxp = nums[0];
        double minp = nums[0];

        double res = nums[0];

        for(int i=1;i<nums.size();i++){

            if(nums[i] < 0){
                swap(maxp,minp);
            }

            maxp = max((double)nums[i],nums[i]*maxp);
            minp = min((double)nums[i],nums[i]*minp);

            
            if(res < maxp) res = maxp;

        }
        return (int)res;
}
};
