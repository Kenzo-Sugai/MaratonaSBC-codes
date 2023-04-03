# Fase Regional da Maratona de Programação 2006

* [ ] Fechem as Portas! (Fácil)
* [ ] MegaDamas (Médio)
* [ ] O Problema da Parada (Difícil)
* [x] Esquerda, Volver! (Fácil)
* [x] Circuito Bioquímico Digital (Médio)

## Circuito Bioquímico Digital

```cpp
#include <iostream>

using namespace std;

int main(){
    
    int N, M, C;

    while(cin >> N >> M >> C){
        if(!N && !M && !C){
            return 0;
        }
        int result {0};
        int exp[M][N];

        for(int i = 0; i < M; i++){

            for(int j = 0; j < N; j++){
                cin >> exp[i][j];
            }
        }

        for(int i = 0; i < N; i++){
            int cnt {0};
            for(int j = 0; j < M; j++){
          
                if(exp[j][i] == 1){
                    cnt++;
                }
                else{
                    if(cnt >= C){
                        result++;
                    }
                    cnt = 0;
                }
            }
            if(cnt >= C){
                result++;
            }
        }
        cout << result << endl;
    }
}
```

## Esquerda, Volver!

```cpp
#include <iostream>

using namespace std;

int main(){

    int N;
    char position[] = {'N', 'L', 'S', 'O'};
    string comandos;
    while(cin >> N){
    
        if(!N) return 0;
        
        cin >> comandos;
        
        int pos = 0;
        
        for(int i = 0; i < comandos.size(); i++){
            if(comandos[i] == 'D') pos++;
            else pos--;

            if(pos > 3) pos = 0;
            else if(pos < 0) pos = 3;
        }

        cout << position[pos] << endl;
    }
    
}
```
