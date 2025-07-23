class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        // code here
        int n = arr.size();
        int i = 0, j = 0;
        int sum = 0, currSum = 0;
        
        for(int i=0;i<n;i++){
            sum += arr[i] * (i+1)*(n-i);
        }
        
        return sum;
    }
};