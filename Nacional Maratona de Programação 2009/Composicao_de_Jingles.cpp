#include <iostream>
#include <map>

using namespace std;
int main() {
  int begin, end, compasso = 0;
  double total;
  map<string, float> letra;
  //map<string,int>::iterator it = letra.begin();
    letra["W"] = 1.0;
    letra["H"] = 1.0/2;
    letra["Q"] = 1.0/4;
    letra["E"] = 1.0/8;
    letra["S"] = 1.0/16;
    letra["T"] = 1.0/32;
    letra["X"] = 1.0/64;
  string jingle, letra_jingle;
  while(getline(cin, jingle)){
    if(jingle != "*"){
      for(int i = 0; i < jingle.length(); i++){
        if(!(jingle[i] == '/')){
          letra_jingle = jingle[i];
          total = total + letra[letra_jingle];
        }
        else{
          if(total == 1){
            compasso++;
          }
          total = 0;
        }
      }
    cout << compasso << endl;
    compasso = 0;
    }
    else{
      break;
    }
  }
} 
