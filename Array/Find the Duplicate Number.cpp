class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        unordered_map<int,int> mp;

        for(auto x: nums){

            mp[x]++;
        }

        int dupli = -1;  

        for(auto x: mp){

            if(x.second>1){
                dupli = x.first;
                break;
            }
        }   

        return dupli;   
    }
};
