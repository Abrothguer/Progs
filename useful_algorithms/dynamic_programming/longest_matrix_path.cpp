#include <iostream>

#define MAX    500

using namespace std;

int longest_aux(int matrix[][MAX], int memo[][MAX], int x, int y, int n) {
    if (memo[x][y] != -1) {
        return(memo[x][y]);
    }

    // Can move in 4 directions.
    if (x - 1 >= 0 and matrix[x - 1][y] == matrix[x][y] + 1) {
        return(memo[x][y] = 1 + longest_aux(matrix, memo, x - 1, y, n));
    }
    if (x + 1 < n and matrix[x + 1][y] == matrix[x][y] + 1) {
        return(memo[x][y] = 1 + longest_aux(matrix, memo, x + 1, y, n));
    }
    if (y - 1 >= 0 and matrix[x][y - 1] == matrix[x][y] + 1) {
        return(memo[x][y] = 1 + longest_aux(matrix, memo, x, y - 1, n));
    }
    if (y + 1 < n and matrix[x][y + 1] == matrix[x][y] + 1) {
        return(memo[x][y] = 1 + longest_aux(matrix, memo, x, y + 1, n));
    }

    return(memo[x][y] = 1);
}

int longest_path(int matrix[][MAX], int n) {
    int memo[n][MAX];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            memo[i][j] = -1;
        }
    }
    int maxi = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (memo[i][j] == -1) {
                maxi = max(longest_aux(matrix, memo, i, j, n), maxi);
            }
        }
    }
    return(maxi);
}

int main() {
    int m;
    int matrix[MAX][MAX];

    while (true) {
        cout << "Type the size of the matrix: ";
        cin >> m;
        if (m <= 0) {
            break;
        }

        cout << "Type the elements of the matrix: " << endl;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> matrix[i][j];
            }
        }

        cout << "Longest increasing path is " << longest_path(matrix, m) << endl;
    }
    return(0);
}
