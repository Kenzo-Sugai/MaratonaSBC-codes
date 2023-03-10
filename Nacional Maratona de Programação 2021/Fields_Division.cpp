#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> G;
vector<bool> cor;

void DFS(int u){
    for(int i = 0; i < G[u].size(); i++){
        if(!cor[G[u][i]]){
            cor[G[u][i]] = true;
            DFS(G[u][i]); 
        }
    }
}

int main(){

    int N, M, X, Y;

    cin >> N >> M;

    G.resize(N);
    cor.resize(N, false);

    for(int i = 0; i < M; i++){

        cin >> X >> Y;
        X--; Y--;
        if(X != N - 1 && Y != N - 1){

            G[X].push_back(Y);
            G[Y].push_back(X);

        }

    }

    cor[N-2] = true;
    DFS(N-2);

    for(auto x : cor){
        if(x) cout << "B";
        else cout << "A";
    }
    cout << endl;


}
