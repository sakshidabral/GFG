class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        int divi = 0;
        
        for(int i=0; i<n; i++){
            int val = (arr[i]%k == 0) ? 0 : k - (arr[i] % k);
            if(val == 0) divi++;
            else pq.push(val);
        }
        
        int ans = 0, target = (n+1)/2;
        while(divi < target && !pq.empty() ){
            ans += pq.top();
            pq.pop();
            divi++;
        }
        
        return ans;
    }
};