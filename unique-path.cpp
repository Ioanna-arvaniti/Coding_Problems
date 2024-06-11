

Αντιγραφή κώδικα
#include <iostream>
#include <vector>
using namespace std;

// Function to calculate unique paths
int uniquePaths(int m, int n) {
    // Handle edge cases for invalid input
    if (m <= 0 || n <= 0) {
        cerr << "Error: Dimensions must be greater than zero." << endl;
        return 0;
    }

    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Initialize the bottom row and rightmost column
    for (int i = 0; i < m; i++) {
        dp[i][n - 1] = 1;
    }
    for (int j = 0; j < n; j++) {
        dp[m - 1][j] = 1;
    }

    // Fill the dp table
    for (int i = m - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        }
    }

    return dp[0][0];
}

int main() {
    int m, n;

    // Example inputs
    m = 3;
    n = 2;

    // Calculate and print unique paths
    cout << "Unique paths for m = " << m << ", n = " << n << ": " << uniquePaths(m, n) << endl;

    // Additional test cases
    m = 7;
    n = 3;
    cout << "Unique paths for m = " << m << ", n = " << n << ": " << uniquePaths(m, n) << endl;

    m = 3;
    n = 3;
    cout << "Unique paths for m = " << m << ", n = " << n << ": " << uniquePaths(m, n) << endl;

    m = 3;
    n = 7;
    cout << "Unique paths for m = " << m << ", n = " << n << ": " << uniquePaths(m, n) << endl;

    return 0;
}