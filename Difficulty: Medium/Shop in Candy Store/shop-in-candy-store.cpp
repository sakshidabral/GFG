class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        sort(prices.begin(), prices.end());
        int n = prices.size();
        
        int min = 0;
        int i = 0, j = n-1;
        
        while(i <= j){
            min += prices[i];
            i++;
            j -= k;
        }
        
        int max = 0;
        i = n-1, j = 0;
        
        while(i >= j){
            max += prices[i];
            i--;
            j += k;
        }
        
        return {min, max};
    }
};