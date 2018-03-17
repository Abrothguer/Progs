#include <iostream>

#define MAX    300

using namespace std;

int maxmatrix(int matrix[][MAX], int n, int m) {
    int maxsize = 0;
    int aux[n][m];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (not i or not j or not matrix[i][j]) {
                aux[i][j] = matrix[i][j];
            }
            else if (matrix[i][j]) {
                aux[i][j] = 1 + min(aux[i - 1][j - 1], min(aux[i - 1][j], aux[i][j - 1]));
            }
            maxsize = max(aux[i][j], maxsize);
        }
    }
    return(maxsize);
}

int main() {
    int n, m;
    int matrix[MAX][MAX];

    while (true) {
        cout << "Type n: ";
        cin >> n;
        if (n <= 0) {
            break;
        }
        cout << "Type m: ";
        cin >> m;
        if (m <= 0) {
            break;
        }

        cout << "Type the matrix of size " << n << "x" << m << ":" << endl;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> matrix[i][j];
            }
        }

        cout << "The size of the maximum square submatrix with all 1 is: "
             << maxmatrix(matrix, n, m) << endl;
    }
    return(0);
}
