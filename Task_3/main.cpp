#include <bits/stdc++.h>
#define _fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void matrix_flatten(vector<vector<vector<int>>> &matrix_3d, vector<int> &vector_1d);

int getIndex1D(int i, int j, int k, int n, int m, int p);

int main() {
    _fast_io
    int n, m, p;
    cin >> n >> m >> p;
    vector<vector<vector<int>>> matrix_3d (n, vector<vector<int>>(m, vector<int>(p)));

    int num;
    
    // take input from user and insert it in 3D matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                cin >> num;
                matrix_3d[i][j][k] = num;
            }
        }
    }

    int q = n*m*p;
    vector<int> vector_1d(q);
    matrix_flatten(matrix_3d, vector_1d);

    
    // to check whether getIndex1D is true or not 
    // we iterate through every element in 3D matrix and give getIndex1D these parameters: i j k then check if vector1D[getten index] = matrix3D[i][j][k]
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                if(matrix_3d[i][j][k] == vector_1d[getIndex1D(i, j , k, n, m, p)]){
                    cout << "true" << endl;
                }
                else{
                    cout << "false" << endl;
                }
            }
        }
    }

}

void matrix_flatten(vector<vector<vector<int>>> &matrix_3d, vector<int> &vector_1d){
    int y = 0;

    for (int i = 0; i < matrix_3d.size(); ++i) {
        for (int j = 0; j < matrix_3d[0].size(); ++j) {
            for (int k = 0; k < matrix_3d[0][0].size(); ++k) {
                vector_1d[y] = matrix_3d[i][j][k];
                y++;
            }
        }
    }
}

int getIndex1D(int i, int j, int k, int n, int m, int p){
    return i*m*n + j*m + k;
}
