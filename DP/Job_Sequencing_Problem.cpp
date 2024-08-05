// GREEDY SOLUTION 

class Solution 
{
    public:
    
    static bool cmp(Job j1, Job j2){
        return j1.profit > j2.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,cmp);
        
        int maxdead = INT_MIN;
        
        for(int i=0;i<n;i++){
            
            maxdead = max(maxdead,arr[i].dead);
        }
        
        vector<int> profitarr(maxdead + 1,-1);
        
        int maxpft = 0;
        int cnt = 0;
        
        for(int i=0;i<n;i++){
            
            int pft = arr[i].profit;
            int jobid = arr[i].id;
            int lastdate = arr[i].dead;
            
            for(int j = lastdate;j>0;j--){
                
                if(profitarr[j] == -1){
                    
                    profitarr[j] = jobid;
                    
                    maxpft += pft;
                    cnt++;
                    break;
                }
            }
        }
        
        return {cnt,maxpft};
    } 
};
