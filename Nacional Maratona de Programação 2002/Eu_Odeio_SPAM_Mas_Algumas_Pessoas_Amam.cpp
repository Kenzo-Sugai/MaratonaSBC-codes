#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int P, C, lim1, lim2;
    string str1, str2, str3, nome;
    while(cin >> P){
        if(P == 0){
            cin >> P;
            if(P == 0){
                break;
            }
        }
        vector<vector<int>> G;
        vector<vector<string>> G2;
        vector<string> nomes;
        G.resize(P+1);
        G2.resize(P+1);
        for(int i = 1; i <= P; i++){
            while(C != 0){
                cin >> C;
                if(C != 0){
                    G[i].push_back(C);
                }
            }
            C = 1;
            //cout << "SAIU | c = " << c << endl;
        }
        while(true){
            cin >> C;
            if(C == 0){
                break;
            }
            cin >> lim1 >> lim2 >> str1 >> str2 >> str3;
            queue<int> Q;
            Q.push(C);
            vector<bool> cor(P+1, false);
            cor[C] = true;
            while(!Q.empty()){
                int u = Q.front();
                Q.pop();
                for(int i = 0; i < G[u].size(); i++){
                    if(!cor[G[u][i]]){
                        //cout << "COR " << G[u][i] << " TRUE" << endl;
                        cor[G[u][i]] = true;
                        Q.push(G[u][i]);
                    }
                }
            }
            for(int j = 1; j <= P; j++){
                if(G[j].size() < lim1 || cor[j] == false){
                    G2[j].push_back(str1);
                }
                else if(lim1 <= G[j].size() && G[j].size() < lim2 && cor[j] == true){
                    G2[j].push_back(str2);
                }
                else if(lim2 <= G[j].size() && cor[j] == true){
                    G2[j].push_back(str3);
                }
            }
        }
        C = 1;
        nomes.push_back("/*default*/");
        for(int i = 1; i <= P; i++){
            cin >> nome;
            nomes.push_back(nome);
        }
        for(int i = 1; i <= P; i++){
            cout << nomes[i] << ":";
            for(int j = 0; j < G2[i].size(); j++){
                cout << " " << G2[i][j];
            }
            cout << " " << endl;
        }
    }
}
