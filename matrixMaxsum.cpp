#include <iostream>
#include <vector>
using namespace std;

// void SumCal(int row, int col, vector<vector<int>> &arr) {
//     for(int i = 0; i < row; i++) {
//         int sum = 0;
//         for(int j = 0; j < col; j++) {
//             sum += arr[i][j];
//         }
//         cout << sum << endl;
//     }
// }
void MaxSum(int row, int col, vector<vector<int>> &arr) {
    int maxi = -1;
    int index = -1;
    for(int i = 0; i < row; i++) {
        int sum = 0;
        for(int j = 0; j < col; j++) {
            sum += arr[i][j];
            
        }
        maxi = max(maxi,sum);
        index = i;
        
        
        cout << sum << endl;
        
    }
        cout << maxi << endl;
        cout << index<< endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    // SumCal(n, m, arr);
    MaxSum(n, m, arr);

    return 0;
}