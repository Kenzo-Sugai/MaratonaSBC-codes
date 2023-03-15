#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N, C, n;

    cin >> N >> C;

    vector<int> mon;

    for(int i = 0; i < N; i++){

        cin >> n;
        mon.push_back(n);

    }

    int cnt =0;
    int maxH = 0;
    for(int i = 0; i < N; i++){
        cnt = 1;
        for(int j = i+1, k = i; j < N; j++){

            if(mon[j] - mon[k] <= C){
                cnt++;
                k++;
            }
            else break;

        }

        maxH = max(maxH, cnt);

    }

    cout << maxH << endl;
}
