//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        vector<int>a;
        bool b=true;

// first find all the rows containind all elements 0 meaning they //know no one
        for(int i=0;i<mat.size();i++)
        {
            b=1;
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]!=0)
                {
                    b=false;
                    break;
                }
            }
            if(b)a.push_back(i);
        }

// now check if the one who knows no one is known by all //meaninig know we will check if they are know by all except //themselves 
        vector<int>ans;
        for(int i=0;i<a.size();i++)
        {
            b=1;
            for(int j=0;j<mat.size();j++)
            {
                if(mat[j][a[i]]!=1&&j!=a[i])
                {
                    b=false;
                    break;
                }
            }
            if(b)ans.push_back(a[i]);
        }
        if(ans.empty())return -1;
        return ans[0];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends
