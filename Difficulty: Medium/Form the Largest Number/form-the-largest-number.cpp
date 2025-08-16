class Solution {
  public:
  
    struct cmp {
    bool operator()(const string &a, const string &b) const {
        // For priority_queue: return true if a has *lower* priority
        return (a + b) < (b + a);
    }
};
    string findLargest(vector<int> &arr) {
        // code here
        priority_queue<string, vector<string> , cmp> pq;
        
        for(auto num: arr){
            pq.push(to_string(num));
        }
        
        string ans = "";
        
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        
        int i = 0;
        int n = ans.size();
        
        while(i < n){
            if(ans[i] != '0'){
                break;
            }
            i++;
        }
        string res = ans.substr(i);
        
        return res == "" ? "0" : res;
    }
};