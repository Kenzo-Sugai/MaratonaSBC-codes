#include <iostream>
#include <vector>

using namespace std;

struct Botas{
    int tamanho;
    char par;

};

int main(){

    int N, tamanho;
    char par;

    while(cin >> N){
        vector<Botas> caixas;
        int cnt = 0;
        for(int i = 0; i < N; i++){
            cin >> tamanho >> par;
            bool find = false;
            for(int j = 0; j < caixas.size(); j++){
                if(caixas[j].tamanho == tamanho && caixas[j].par != par){
                    caixas.erase(caixas.begin()+j);
                    find = true;
                    cnt++;
                    break;
                }
            }
            if(find == false){
                caixas.push_back({tamanho, par});
            }
        }
        cout << cnt << endl;
    }
}
