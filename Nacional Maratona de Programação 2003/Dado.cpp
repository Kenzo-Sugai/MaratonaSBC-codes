#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct player {
    int id;
    int casa;
    bool trap = false;
};

int main(){

    int N, M, n, d1, d2;
    int j, t;

    while(cin >> N >> M){
        if(!N && !M) return 0;
        map<int, bool> trap;
        for(int i = 0; i < 3; i++){
            cin >> n;
            trap[n] = true;
        }

        vector<player> cs;
        for(int i = 0; i < N; i++) cs.push_back({i+1, 0, false});
        
        cin >> n;
        int v;
        for(int i = 0; i < n; i++){
            v = i % N;
            while(cs[v].trap){
                cs[v].trap = false;
                //cout << v+1 << " pulado" << endl;
                v++; i++; n++;
                if(v == N) v = 0;
            }
            cin >> d1 >> d2;
            int d = d1+d2;
            //cout << cs[v].id << ": " << d << endl;
            cs[v].casa += d;
            if(cs[v].casa > M){
                cout << cs[v].id << endl;
                break;
            }
            if(trap[cs[v].casa]) cs[v].trap = true;
        }
    }

}
