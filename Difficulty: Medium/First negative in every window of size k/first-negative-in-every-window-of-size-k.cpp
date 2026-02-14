class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int i = 0;
        int j = 0;
        queue<int> q;
        
        for(; j<k; j++){
            
            if(arr[j] < 0){
                q.push(arr[j]);
            }
        }
        j--;
        vector<int> ans;
        
        while(j < arr.size()){
            if(q.empty()){
                ans.push_back(0);
            }
            else{
                ans.push_back(q.front());
            }
            
            if(!q.empty() && arr[i] == q.front()){
                q.pop();
            }
            i++;
            j++;
            if(arr[j] < 0){
                q.push(arr[j]);
            }
        }
        
        return ans;
    }
};