class Solution {
public:
    int numTrees(int n) {
        // Create 'sol' vector to store the solution...
        std::vector<int> sol(n + 1, 0);
        sol[0] = sol[1] = 1;

        // Run a loop from 2 to n...
        for (int i = 2; i <= n; i++) {
            // Within the above loop, run a nested loop from 1 to i...
            for (int j = 1; j <= i; j++) {
                // Update the i-th position of the vector by adding the multiplication of the respective index...
                sol[i] += sol[i - j] * sol[j - 1];
            }
        }
        // Return the value of the nth index of the vector to get the solution...
        return sol[n];
    }
};
