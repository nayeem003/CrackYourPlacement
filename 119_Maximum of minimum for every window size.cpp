//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
          stack < int > st;
  int left[n + 1], right[n + 1];
  vector < int > ans(n + 1);
  for (int i = 0; i < n; i++) {
    left[i] = -1;
    right[i] = n;
  }
  for (int i = 0; i < n; i++) {
    while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
    if (!st.empty()) left[i] = st.top();
    st.push(i);
  }
  while (!st.empty()) st.pop();
  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
    if (!st.empty()) right[i] = st.top();
    st.push(i);
  }
  for (int i = 0; i <= n; i++) ans[i] = 0;
  for (int i = 0; i < n; i++) {
    int len = right[i] - left[i] - 1;
    ans[len] = max(ans[len], arr[i]);
  }
  for (int i = n - 1; i >= 0; i--) {
    ans[i] = max(ans[i], ans[i + 1]);
  }
  ans.erase(ans.begin());
  return ans;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
