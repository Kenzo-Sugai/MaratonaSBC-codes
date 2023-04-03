# Fase Regional da Maratona de Programação 2008

* [x] Apagando e Ganhando (Difícil)
* [ ] Babel (Difícil)
* [ ] O Salão do Clube (Difícil)
* [x] Dama (Fácil)
* [ ] Bolhas e Baldes (Médio)
* [ ] Loop Musical (Fácil)
* [ ] Set (Difícil)
* [ ] Divisão da Nlogônia (Fácil)
* [ ] Maior Subseqüência Crescente (Difícil)
* [ ] Vampiros (Fácil)

## Apagando e Ganhando

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N, D;

    while(cin >> N >> D){

        if(!N and !D) return 0;

        string num;
        
        cin >> num;

        vector<char> stack(N);

        int del = 0;
        int idx = -1;

        for(int i = 0; i < num.size(); i++){
        
            while(idx >= 0 && num[i] > stack[idx] && del < D){
                
                idx--;
                
                del++;

            }

            if(idx+1 < N - D) stack[++idx] = num[i];

        }

        for(int i = 0; i <= idx; i++) cout << stack[i];
        cout << endl; 
        

    }

}
```

## Dama

```cpp
#include <iostream>
#include <math.h>

using namespace std;

int X1, X2, Y1, Y2;

int main(){

    while(scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2)){
        if(!(X1) && !(Y1) && !(X2) && !(Y2)){
            return 0;
        }

        if(X1 == X2 && Y1 == Y2){
            printf("0\n");
        }
        else{
            if((X1 != X2 && Y1 == Y2) || (X1 == X2 && Y1 != Y2) || (std::abs(X1-X2) == std::abs(Y1-Y2))){
                printf("1\n");
            }
            else{
                printf("2\n");
            }
        }
    }
}
```
