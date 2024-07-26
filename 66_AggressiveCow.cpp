#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if it is possible to place cows with at least 'dist' distance apart
bool isFeasible(const vector<int>& stalls, int n, int c, int dist) {
    int count = 1; // Place the first cow in the first stall
    int last_position = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - last_position >= dist) {
            count++;
            last_position = stalls[i];
            if (count == c) {
                return true;
            }
        }
    }
    return false;
}

// Function to find the largest minimum distance
int largestMinDistance(int n, int c, vector<int>& stalls) {
    sort(stalls.begin(), stalls.end());

    int low = 0;
    int high = stalls[n - 1] - stalls[0];
    int best = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (isFeasible(stalls, n, c, mid)) {
            best = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return best;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        cout << largestMinDistance(n, c, stalls) << endl;
    }
    return 0;
}
