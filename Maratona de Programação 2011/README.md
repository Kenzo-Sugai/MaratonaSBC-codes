# Fase Regional da Maratona de Programação 2011

* [x] Ácido Ribonucleico Alienígena (Médio)
* [x] Botas Perdidas (Fácil)
* [x] Estacionamento (Médio)
* [x] Guarda Costeira (Fácil)
* [ ] Desvio de Rua (Difícil)
* [ ] Campeonato de SMS (Difícil)
* [ ] Foco (Difícil)
* [ ] Homem, Elefante e Rato (Difícil)

## Ácido Ribonucleico Alienígena

```cpp
#include <iostream>
#include <stack>

using namespace std;

int main(){
  
  string codigo;
  char s, s2;
  int top1, top2;
  while(cin >> codigo){
    stack<char> S;
    stack<char> S2;
    
    for(int i = 0; i < codigo.size(); i++){
      S.push(codigo[i]);
    }
    int cnt = 0;
    while(!S.empty()){
      if(S2.size() > 0){
        s = S.top();
        s2 = S2.top();
        if(s != s2){
          if(s == 'B' || s == 'S') top1 = 0;
          else top1 = 1;
          if(s2 == 'F' || s2 == 'C') top2 = 1;
          else top2 = 0;
          if(top1 == top2){
            S2.pop();
            cnt++;
          }
          else{
            S2.push(S.top());
          }
        }
        else{
          S2.push(S.top());
        }
      }
      else{
        S2.push(S.top());
      }
      S.pop();  
    }
    cout << cnt << endl;
  }
}
```

## Botas Perdidas

```cpp
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
```
