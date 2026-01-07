class Solution {
public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        unordered_map<int, int> freq;
        vector<int> res;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
            
            if (i >= k - 1) {
                res.push_back(freq.size());
                freq[arr[i - k + 1]]--;
                if (freq[arr[i - k + 1]] == 0)
                    freq.erase(arr[i - k + 1]);
            }
        }
        return res;
    }
};