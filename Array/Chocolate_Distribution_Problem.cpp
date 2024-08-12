class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    
    sort(a.begin(),a.end());
    
    long long mini = 1e9;
    
    long long i = 0;
    
    while(i <= n-m){
        
        mini = min(mini,a[i + m -1] - a[i]);
        i++;
    }
    
    return mini;
    
    }

};
