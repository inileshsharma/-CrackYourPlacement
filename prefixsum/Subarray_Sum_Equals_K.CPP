class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        mp[0] = 1;

        int cnt = 0;
        int currsum = 0;

        for(int i=0;i<nums.size();i++){

            currsum += nums[i];

            int cmltve_sum = currsum - k;

            if(mp.find(cmltve_sum) != mp.end()){
                cnt += mp[cmltve_sum];
            }

            mp[currsum]++;
        }

        return cnt;
        
    }
};
