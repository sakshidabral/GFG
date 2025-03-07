//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int f(string& s, string& rev, int i, int j, vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == rev[j]){
            return dp[i][j] = 1 + f(s, rev, i-1, j-1,dp);
        }
        else{
            int l = f(s, rev, i, j-1,dp);
            int r = f(s, rev, i-1, j,dp);
            return dp[i][j] = max(l,r);
        }
    }
    int longestPalinSubseq(string &s) {
        // code here
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(s, rev, n-1, n-1, dp);
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends