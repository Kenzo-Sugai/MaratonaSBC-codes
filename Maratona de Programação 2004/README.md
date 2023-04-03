# Fase Regional da Maratona de Programação 2004

* [ ] Caixas Muito Especiais (Difícil)
* [ ] Química (Difícil)
* [ ] Drop Out (Médio)
* [ ] Vá com Calma (Difícil)
* [x] Cara ou Coroa (Fácil)
* [x] Ajude! (Fácil)
* [ ] Apresse-se! (Difícil)
* [ ] Patrulheiros Romanos (Difícil)

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

### Ajude!
