class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        sort(prices.begin(), prices.end());
        
        int n = prices.size();
        int candies_to_buy = (n + k) / (k + 1);
        
        int min_cost = 0;
        for(int i = 0; i < candies_to_buy; i++) {
            min_cost += prices[i];
        }
        
        int max_cost = 0;
        for(int i = n - candies_to_buy; i < n; i++) {
            max_cost += prices[i];
        }
        
        return {min_cost, max_cost};
    }
};