#include <iostream>
#include <set>
#include <cctype>

using namespace std;

int main() {
  string frase;
  while(getline(cin, frase)){
    if(cin.peek() == '\n') cin.ignore();
    if(frase[0] == '*'){
      return 0;
    }
    bool check_set = false;
    string aux = "";
    set<char> check;
    for(int i = 0; i < frase.size(); i++){
      if(frase[i] != ' '){
        aux += tolower(frase[i]);
      }
      else{
        check.insert(aux[0]);
        aux = "";
        if(check.size() > 1){
          check_set = true;
          break;
        }
      }
    }
    check.insert(aux[0]);
    aux = "";
    if(check.size() > 1){
      check_set = true;
    }
    if(!check_set){
      cout << "Y" << endl;
    }
    else{
      cout << "N" << endl;
    }
  }
}
