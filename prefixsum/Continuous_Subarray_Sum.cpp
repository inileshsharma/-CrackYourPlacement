// MODULO PATTERN (%K) 
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        unordered_map<int,int>mp;

        mp[0] = -1;

        int currsum =0;

        for(int i=0;i<nums.size();i++){

            currsum += nums[i];
            int rem = currsum % k;
            //mp[rem] = i;

            if(mp.find(rem) != mp.end()){

                int len = i - mp[rem];
                if(len >= 2) return true;
            }
            else mp[rem] = i;
        }

        return false;
        
    }
};
