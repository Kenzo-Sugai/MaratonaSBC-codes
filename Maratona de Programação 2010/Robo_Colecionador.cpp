#include <bits/stdc++.h>

using namespace std;

struct cord {
    int l;
    int c;
};

void print(vector<vector<char>> &mapa){

    for(int a = 0; a < mapa.size(); a++){

        for(int b = 0; b < mapa[a].size(); b++){
            cout << mapa[a][b];
        }
        cout << endl;
    }

}

int main(){
    
    int N, M, I;
    char pos[4] = {'N', 'L', 'S', 'O'};
    cord ori[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    string line;

    while(cin >> N >> M >> I){
        if(!N && !M && !I) return 0;
        int k, cnt = 0;
        cord position;
        vector<vector<char>> mapa(N);

        for(int i = 0; i < N; i++){
            cin >> line;
            for(int j = 0; j < M; j++){
                if(line[j] != '*' && line[j] != '.' && line[j] != '#'){
                    for(k = 0; k < 4; k++){
                        if(pos[k] == line[j]) break;
                    }
                    position = {i, j};
                    mapa[i].push_back('.');
                }
                else
                    mapa[i].push_back(line[j]);
                     

            }

        }
        
        cin >> line;
        for(int j = 0; j < line.size(); j++){
            if(line[j] == 'F'){
                if(position.l + ori[k].l < N && position.l + ori[k].l >= 0 && position.c + ori[k].c < M && position.c + ori[k].c >= 0 && 
                    mapa[position.l + ori[k].l][position.c + ori[k].c] != '#'){
                    
                    //mapa[position.l][position.c] == '.';
                    position.l += ori[k].l; position.c += ori[k].c;
                    if(mapa[position.l][position.c] == '*'){
                        mapa[position.l][position.c] = '.';
                        cnt++;
                    }
                    //mapa[position.l][position.c] = 'R';
                    //print(mapa);
                    //cout << endl;
                } 
            }
            else if(line[j] == 'D'){
                k++;
                if(k == 4) k = 0;
            }
            else if(line[j] == 'E'){
                k--;
                if(k == -1) k = 3;
            }

        }
        cout << cnt << endl;




    }

}
