# Fase Regional da Maratona de Programação 2004

* [ ] Caixas Muito Especiais
* [ ] Química
* [ ] Drop Out
* [ ] Vá com Calma
* [x] Cara ou Coroa
* [x] Ajude!
* [ ] Apresse-se!
* [ ] Patrulheiros Romanos

## Cara ou Coroa

```cpp
#include <iostream>

using namespace std;

int main(){

  int N, ri, M = 0, J = 0;

  while(cin >> N){
    if(N == 0){
      break;
    }

    M = 0, J =0;

    while(N--){
      cin >> ri;
      if(ri == 0)
        M++;
      else
        J++;
    }
    cout << "Mary won " << M << " times and John won " << J << " times" << endl;
  }
}
```

## Ajude!

```cpp
#include <iostream>
#include <vector>

class Problems{
    public:
        char id;
        bool correct = false;
        int time;

        Problems(char id, int time, bool correct){
            this->id = id; this->time = time; this->correct = correct;
        }
};

using namespace std;

int main(){
    int N, time;
    char P;
    string C;
    while(cin >> N){
        if(N == 0) break;

        vector<Problems> correct_cash;
        vector<Problems> incorrect_cash;

        for(int i = 0; i < N; i++){
            cin >> P >> time >> C;
            if(C == "correct") correct_cash.push_back(Problems(P, time, true));
            if(C == "incorrect") incorrect_cash.push_back(Problems(P, 1, false)); 
        }

        int counter = correct_cash.size(), timer = 0, incorrects = 0;

        for(int i = 0; i < correct_cash.size(); i++){
            timer += correct_cash[i].time;
        }
        for(int i = 0; i < incorrect_cash.size(); i++){
            for(int j = 0; j < correct_cash.size(); j++){
                if(incorrect_cash[i].id == correct_cash[j].id){
                    incorrects++;
                    break;
                }
            }
        }
        cout << counter << " " << timer+incorrects*20 << endl;
    }
}
```
