class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        int n = queries.size();
        int n2 = arr.size();
        
        int l,r,k,m1,m2,m,f=0;
        
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            l = queries[i][0];
            r = queries[i][1];
            k = queries[i][2];
            f=0;
            while(l<=r){
                m = l+(r-l)/2;
                if(arr[m]>k)r=m-1;
                else if(arr[m]<k)l=m+1;
                else if(m-1>=0 && arr[m-1]==k){
                    r=m-1;
                    f=1;
                }
                else {
                    f=1;
                    break;
                }
            }
            if(f==0){
                ans.push_back(0);
                continue;
            }
            l = queries[i][0];
            r = queries[i][1];
            m1 = m;
            
            while(l<=r){
                m = l+(r-l)/2;
                if(arr[m]>k)r=m-1;
                else if(arr[m]<k)l=m+1;
                else if(m+1<n2 && arr[m+1]==k)l=m+1;
                else break;
            }
            
            m2=m;
            ans.push_back(m2-m1+1);
        }
        
        return ans;
    }
    
};