class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int minn = INT_MAX;
        int maxx = 0;
        
        if(!left.empty()){
            for(int i=0; i<left.size(); i++){
                maxx = max(maxx, left[i]);
            }
        }
        
        if(!right.empty()){
            for(int i=0; i<right.size(); i++){
                minn = min(minn, right[i]);
            }
        }
        
        return max(maxx, n-minn);
    }
};