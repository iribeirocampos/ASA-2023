#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int X, Y, n;
vector<vector<int>> matrix;
int recursion(int x, int y)
{

    // Preenchimento da matriz
    for (int j = 0; j <= y; j++)
    {
        for (int i = 0; i <= x; i++)
        {
            for (int k = 0; k <= i / 2; k++)
            {
                // Cortes segundo X
                if ((i - k > 0))
                    matrix[i][j] = max(matrix[i][j], matrix[i - k][j] + matrix[k][j]);
            }
            // Cortes segundo Y
            for (int k = 0; k <= j / 2; k++)
                if ((j - k > 0))
                    matrix[i][j] = max(matrix[i][j], matrix[i][j - k] + matrix[i][k]);
        }
    }

    return matrix[x][y];
}

int main()
{
    time_t start, end;
    time(&start);
    scanf("%d %d", &X, &Y);
    matrix.assign(X + 1, vector<int>(Y + 1, 0));

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int x, y, p;
        scanf("%d %d %d", &x, &y, &p);
        if ((x <= X) && (y <= Y))
            matrix[x][y] = max(p, matrix[x][y]);
        if ((x <= Y) && (y <= X))
            matrix[y][x] = max(p, matrix[y][x]);
    }

    cout << recursion(X, Y) << endl;
    time(&end);
    double time_taken = double(end - start);
    cout << "\nTime taken by program is : " << fixed
         << time_taken << setprecision(500);
    cout << " sec " << endl;
    return 0;
}
