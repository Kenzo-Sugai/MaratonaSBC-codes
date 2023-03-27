#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N;

void floyd(vector<vector<int>>&g){
    for (int k = 0; k < N; k++) {
        
        for (int i = 0; i < N; i++) {
            
            for (int j = 0; j < N; j++) {
              
                if (g[i][j] > (g[i][k] + g[k][j]) && (g[k][j] != INT_MAX
                        && g[i][k] != INT_MAX))
                    g[i][j] = g[i][k] + g[k][j];
            }
        }
    }
}

int main(){

    int M, v, w, p;

    while(cin >> N >> M && N+M){

        vector<vector<int>> G(N, vector<int>(N, INT_MAX));

        for(int i = 0; i < M; i++){

            cin >> v >> w >> p;
            v--; w--;
            if(p == 1){
                G[v][w] = 1;
            }
            if(p == 2){
                G[w][v] = 1;
                G[v][w] = 1;
            }

        }

        floyd(G);

        int resp = 1;

        for(int i = 0; i < N; i++){

            if(!(G[i][N-1] != INT_MAX && G[N-1][i] != INT_MAX)){
                resp = 0;
                break;
            }

        }

        cout << resp << endl;

        

    }

}
