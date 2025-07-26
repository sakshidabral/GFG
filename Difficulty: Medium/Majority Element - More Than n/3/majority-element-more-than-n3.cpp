class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        map<int,int> m;
        for(int n : arr){
            m[n]++;
        }
        
        int n = arr.size()/3;
        vector<int> res;
        for(auto i : m){
            if(i.second > n){
                res.push_back(i.first);
            }
        }
        
        return res;
    }
};