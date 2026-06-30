// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    // Write C++ code here
    int n;
    cin>>n;
    int m ;
    cin>>m;
    int arr[n][m];
    for(int i = 0 ; i<n;i++){
        for(int j = 0; j<m;j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i = 0; i<m;i= i+2){
        for(int j = 0 ; j<n;j++){
            cout<<arr[j][i]<<" ";
        }
            cout<<endl;
    }

    return 0;
}