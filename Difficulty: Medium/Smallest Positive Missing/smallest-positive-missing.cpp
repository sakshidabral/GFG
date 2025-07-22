class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        unordered_map<int,int> map;
        for(int n : arr){
            map[n] = 1;
        }
        
        int i = 1;
        while(1){
            if(map.find(i) == map.end()) return i;
            i++;
        }
        
        return -1;
    }
};