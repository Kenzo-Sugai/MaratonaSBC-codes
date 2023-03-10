#include <iostream>
#include <queue>

using namespace std;

struct pos {
    int i;
    int j;
    int az;
};

int main(){

    int N, M, cnt = 0, menor;

    cin >> N >> M;
    int G[N][M];
    bool cor[N][M];

    menor = N*M;
    
    for(int i = 0; i < N; i++){

        for(int j = 0; j < M; j++){
            cin >> G[i][j];
            cor[i][j] = false;
        }
    }

    queue<pos> Q;
    Q.push({0, 0, G[0][0]});

    for(int i = 0; i < N; i++){

        for(int j = 0; j < M; j++){
            if(!cor[i][j]){
                cor[i][j] = true;
                Q.push({i, j, G[i][j]});

            }
            cnt = 0;
            
            while(!Q.empty()){

                pos u = Q.front();
                Q.pop();

                //cout << "u: v - " << u.az << " " << u.i << " " << u.j <<endl;
                cnt++;
                if(u.i-1 >= 0 && !cor[u.i-1][u.j] && G[u.i-1][u.j] == u.az){
                    cor[u.i-1][u.j] = true;
                    Q.push({u.i-1, u.j, u.az});
                }
                if(u.i+1 < N && !cor[u.i+1][u.j] && G[u.i+1][u.j] == u.az){
                    cor[u.i+1][u.j] = true;
                    Q.push({u.i+1, u.j, u.az});
                }
                if(u.j-1 >= 0 && !cor[u.i][u.j-1] && G[u.i][u.j-1] == u.az){
                    cor[u.i][u.j-1] = true;
                    Q.push({u.i, u.j-1, u.az});
                }
                if(u.j+1 < M && !cor[u.i][u.j+1] && G[u.i][u.j+1] == u.az){
                    cor[u.i][u.j+1] = true;
                    Q.push({u.i, u.j+1, u.az});
                }
            

            }

            if(cnt != 0 && cnt < menor){
                menor = cnt;
            }

        }
    }

    cout << menor << endl;

}
