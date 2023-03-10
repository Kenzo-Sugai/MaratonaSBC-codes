#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct num {
    int id, qnt;
};

bool comp(num a, num b){ 
    if(a.qnt == b.qnt){
        return a.id < b.id;
    }
    return a.qnt < b.qnt; 
}

int main(){

    int N, C, K, n;

    while(cin >> N >> C >> K){
        if(!N && !C && !K) return 0;

        vector<num> hist;

        for(int i = 0; i < K; i++) hist.push_back({i+1, 0});

        for(int i = 0; i < N; i++){
            hist[i].id = i+1;
            for(int j = 0; j < C; j++){
                cin >> n;
                hist[n-1].qnt++;
            }
        }

        sort(hist.begin(), hist.end(), comp);
        
        cout << hist[0].id;

        for(int i = 1;i < K && hist[0].qnt == hist[i].qnt; i++){
            cout << " " << hist[i].id;
        }
        cout << endl;

    }

}
