//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        unordered_map<int,int> m;
        int sum = 0, maxSize = 0;
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum == 0) maxSize = i+1;
            else{
                if(m.find(sum) != m.end()) maxSize = max(maxSize, i-m[sum]);
                else m[sum] = i;
            }
        }
        
        return maxSize;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.maxLen(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends