class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int pft = 0,mini = INT_MAX;

        for(int i=0;i<prices.size();i++){

            pft = max(pft,prices[i] - mini);

            mini = min(mini,prices[i]);
        }

        return pft;
        
    }
};
