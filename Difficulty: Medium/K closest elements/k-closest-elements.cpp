class Compare {
public:
    bool operator()(pair<int, int>& a, pair<int, int>& b){
        if (a.first == b.first)
        {
            return a.second < b.second;
        }
        return a.first > b.first; 
    }
};

class Solution {
  public:
  
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
        int n=arr.size();
        vector<int> res;
        priority_queue<pair<int,int>, vector<pair<int,int>>,Compare> pq;
        for(int i=0;i<n;i++)
        {
            pq.push({abs(arr[i]-x),arr[i]});
        }
        while(k>0)
        {
            if(pq.top().first==0)
            {
                pq.pop();
            }
            else
            {
                res.push_back(pq.top().second);
                pq.pop();
                k--;
            }
        }
        return res;
    }
};