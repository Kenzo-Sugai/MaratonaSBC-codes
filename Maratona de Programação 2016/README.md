# Fase Regional da Maratona de Programação 2016

* [x] Andando do Tempo
* [ ] Batata Quente
* [x] Cachorros-Quentes
* [ ] Contaires
* [ ] Divisores
* [ ] Estatística Hexa
* [ ] Estiquetas Coloridas
* [ ] Fundindo Árvores
* [ ] Go--
* [x] Huaauhahhuahau
* [x] Isósceles
* [ ] Jogos Olímpicos
* [ ] Kit de Encolhimento de Polígonos
* [x] Ladrilhos

## Andando no Tempo

```cpp
#include <iostream>

using namespace std;

int main(){

  int a, b, c;
  cin >> a >> b >> c;
  if(a == b || a == c || b == c){
    cout << "S" << endl;
  }
  else if(a + b == c || a + c == b || b + c == a){
    cout << "S" << endl;
  }
  else{
    cout << "N" << endl;
  }
}
```
