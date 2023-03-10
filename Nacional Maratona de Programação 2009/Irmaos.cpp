#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct herdeiro {
    int ini;
    int i;
    int j;
};

bool comp(herdeiro a, herdeiro b){
    return a.ini < b.ini;
}


int main(){

    int R, N, M, K;
    int n;

    while(cin >> R >> N >> M >> K){
        if(!R && !N && !M && !K) return 0;

        vector<vector<int>> G(N);
        vector<vector<int>> copy;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> n;
                G[i].push_back(n);
            }
        }

        for(int k = 0; k < K; k++){
            copy = G;
            for(int i = 0; i < N; i++){

                for(int j = 0; j < M; j++){

                    vector<herdeiro> inimigo;
                    if(i-1 >= 0 && (copy[i][j] == copy[i-1][j]-1 || (copy[i][j] == R-1 && copy[i-1][j] == 0))) inimigo.push_back({copy[i-1][j], i-1, j});
                    if(i+1 < N && (copy[i][j] == copy[i+1][j]-1 || (copy[i][j] == R-1 && copy[i+1][j] == 0))) inimigo.push_back({copy[i+1][j], i+1, j});
                    if(j-1 >= 0 && (copy[i][j] == copy[i][j-1]-1 || (copy[i][j] == R-1 && copy[i][j-1] == 0))) inimigo.push_back({copy[i][j-1], i, j-1});
                    if(j+1 < M && (copy[i][j] == copy[i][j+1]-1 || (copy[i][j] == R-1 && copy[i][j+1] == 0))) inimigo.push_back({copy[i][j+1], i, j+1});

                    sort(inimigo.begin(), inimigo.end(), comp);
                    /*
                    cout << "[" << i << "," << j << "] " << copy[i][j] << ": ";
                    for(int m = 0; m < inimigo.size(); m++) cout << inimigo[m].ini << " ";
                    cout << endl;
                    */
                    for(int m = 0; m < inimigo.size() && inimigo[m].ini == inimigo[0].ini; m++) G[inimigo[m].i][inimigo[m].j] = copy[i][j];    

                }
            }

        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cout << G[i][j];
                if(j != M-1) cout << " ";
            }
            cout << endl;
        }
    }

}
