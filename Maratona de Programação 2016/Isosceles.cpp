#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N;

    cin >> N;

    vector<int> esq(N), dir(N), h(N);

    for(int i = 0; i < N; i++){

        cin >> h[i];

    }

    esq[0] = dir[N - 1] = 1;

    for(int i = 1, j = N - 2; i < N; i++, j--){

        esq[i] = min(h[i], esq[i - 1] + 1);
        dir[j] = min(h[j], dir[j + 1] + 1);
    
    }

    int resp = 0;

    for(int i = 0; i < N; i++){

        resp = max(resp, min(dir[i], esq[i]));

    }

    cout << resp << endl;

}
