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

## Estacionamento

```cpp
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){

  int size, evt, size_car, size_total, total {0};
  string placa;
  char type;

  while(cin >> size >> evt){
    map<string, pair<int, int>> car;
    vector<bool> interval_size(size, false);
    size_total = 0;
    total = 0;
    for(int i = 0; i < evt; i++){
        cin >> type;
        if(type == 'C'){
            cin >> placa >> size_car;
            int cnt = 0, idx_start, idx_end;
            for(int j = 0; j < interval_size.size(); j++){
                if(interval_size[j] == true) cnt = 0;
                else{ 
                    cnt++;
                    if(cnt == 1){
                        idx_start = j;
                    }
                }

                if(cnt == size_car){
                    total += 10;
                    idx_end = j;
                    car[placa] = {idx_start, idx_end};
                    for(int k = idx_start; k <= idx_end; k++) interval_size[k] = true;
                    break;
                }
            }

        }
        if(type == 'S'){
            cin >> placa;
            for(int j = car[placa].first; j <= car[placa].second; j++){
                interval_size[j] = false;
            }
        }
    }
    cout << total << endl;
  }
}
```

## Guarda Costeira

```cpp
#include <iostream>
#include <math.h>

using namespace std;
 
int main() {
    float D, VF, VG, t, tempF, tempG, hip;
    while(cin >> D >> VF >> VG){
        bool v = false;
        for(int i = 1; i <= 12; i++){
         tempF = i/VF;
         hip = sqrt((D*D) + (i*i));
         tempG = hip/VG;
    
         if(tempG <= tempF){
             v = true;
             cout << "S" << endl;
             break;
         }
        }
        if(v == false){
            cout << "N" << endl;
        }
    }
 
    return 0;
}
```
