#include <iostream>
#include <map>

using namespace std;

int main(){

    int N, M, n;

    while(cin >> N >> M){
        if(!N && !M) return 0;

        map<int, int> hash;

        for(int i = 0; i < M; i++){
            cin >> n;
            hash[n]++;
        }
        int cnt = 0;
        for(auto x: hash){
            if(x.second > 1) cnt++;
        }

        cout << cnt << endl;
    }

}
