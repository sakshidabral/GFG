//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestStringChain(vector<string>& words) {
        // Code here
        sort(words.begin(), words.end(), [](const string &a, const string &b){
            return a.size() < b.size();
        });
        
        unordered_map<string, int> dp;
        int ans = 0;
        
        for (string &word : words) {
            int len = 1;
    
            for (int i = 0; i < word.size(); i++) {
                string prev = word;
                prev.erase(i, 1); // Instead of substr(), use erase() for O(1) removal
    
                if (dp.count(prev)) {
                    len = max(len, dp[prev] + 1);
                }
            }
    
            dp[word] = len;
            ans = max(ans, len);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends