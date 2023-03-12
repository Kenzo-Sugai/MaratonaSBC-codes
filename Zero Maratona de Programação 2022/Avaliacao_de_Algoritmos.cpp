#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct aluno {
  string nome;
  double media;
};

int main(){

  int N;
  string nome, nota;

  cin >> N;

  if(cin.peek() == '\n') cin.ignore();

  while(N--){
    int menor = 10, idx;
    getline(cin, nome);
    getline(cin, nota);

    string aux = "";
    vector<double> parcial;
    for(int i = 0; i < nota.size(); i++){

      if(nota[i] != ' '){
        aux += nota[i];
      }
      if(nota[i] == ' ' || i == nota.size() - 1){
        parcial.push_back(stod(aux));
        if(parcial.back() < menor){
          menor = parcial.back();
          idx = parcial.size() - 1;
        }
        aux = "";
      }
    }
    double media = 0;
    if(parcial.size() == 1) 
      media = (parcial[0] + 0)/2.0;
    if(parcial.size() == 2) 
      media = (parcial[0] + parcial[1])/2.0;
    if(parcial.size() == 3) 
      media = (parcial[0] + parcial[1] + parcial[2])/3.0;
    if(parcial.size() == 4){
      parcial.erase(parcial.begin()+idx);
      media = (parcial[0] + parcial[1] + parcial[2])/3.0;
    }
    
    cout << nome;
    printf(": %.1lf\n", media);
  }
}
