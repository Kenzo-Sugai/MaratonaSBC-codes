#include <iostream>
#include <vector>
using namespace std;

int main(){

    int N, R, n;

    while(cin >> N >> R){
        vector<bool> M(N, false);
        bool all = false;
        if(N == R){
            all = true;
            cout << "*" << endl;
        }
        for(int i = 0; i < R; i++){
            cin >> n;
            M[n - 1] = true;
        }

        if(!all){
            for(int i = 0; i < N; i++){
                if(!M[i]){
                    cout << i+1 << " ";
                }
            }
            cout << endl;
        }
    }
}
