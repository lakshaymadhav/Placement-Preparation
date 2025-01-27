// { Driver Code Starts
//Initial funciton template for C++

#include <bits/stdc++.h>
using namespace std;

int Shape(vector<string> &, int, int);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<string> arr;
        for (int i = 0; i < n; i++)
        {
            string S;
            cin >> S;
            arr.push_back(S);
        }
        cout << Shape(arr, n, m) << endl;
    }
} // } Driver Code Ends

//User function template for C++

// A : vector of given strings
void DFS(int i, int j, vector<string> &mat, vector<vector<bool>> &visited, int n, int m)
{
    if (i < 0 || j < 0 || i >= n || j >= m || mat[i][j] != 'X' || visited[i][j] == true)
        return;

    visited[i][j] = true;

    DFS(i + 1, j, mat, visited, n, m);
    DFS(i - 1, j, mat, visited, n, m);
    DFS(i, j + 1, mat, visited, n, m);
    DFS(i, j - 1, mat, visited, n, m);
}

int Shape(vector<string> &mat, int n, int m)
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'X' && !visited[i][j])
            {
                DFS(i, j, mat, visited, n, m);
                count++;
            }
        }
    }

    return count;
}