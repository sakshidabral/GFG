//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int lcs(string &s1, string &s2) {
        // code here
        int n = s1.length();
        int m = s2.length();
        vector<int> next(m+1,0), curr(m+1,0);
        
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(s1[i] == s2[j]) curr[j] = 1 + next[j+1];
                else curr[j] = max(next[j], curr[j+1]);
            }
            next = curr;
        }
        
        return next[0];
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends