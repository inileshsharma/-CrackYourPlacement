class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        for(int i=0;i<nums.size();i++){

            if(nums[i] == 0){
                nums[i] = -1;
            }
        }

        unordered_map<int,int> mp;
        mp[0] = -1;

        int len = 0;
        int currsum = 0;

        for(int i=0;i<nums.size();i++){

            currsum += nums[i];

            int cmltve_sum = currsum - 0;

            if(mp.find(cmltve_sum) != mp.end()){
                
                len = max(len, i - mp[cmltve_sum]);
            }
            else  mp[currsum] = i;
        }

        return len;
        
    }
};
