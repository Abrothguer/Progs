#include <iostream>

#define MAX    300

using namespace std;

int min_cost_path(int matrix[][MAX], int n, int m) {
    int aux[n][m];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (not i and not j) {
                aux[i][j] = matrix[i][j];
            }
            else if (not i) {
                aux[i][j] = matrix[i][j] + aux[i][j - 1];
            }
            else if (not j) {
                aux[i][j] = matrix[i][j] + aux[i - 1][j];
            }
            else{
                aux[i][j] = matrix[i][j] + min(aux[i - 1][j - 1], min(aux[i - 1][j], aux[i][j - 1]));
            }
        }
    }

    return(aux[n - 1][m - 1]);
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

        cout << "Type the values of the matrix of size " << n << "x" << m << ":" << endl;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> matrix[i][j];
            }
        }

        cout << "The minimum cost to reach (" << n - 1 << ", " << m - 1 << ") is " <<
        min_cost_path(matrix, n, m) << endl;
    }
    return(0);
}
