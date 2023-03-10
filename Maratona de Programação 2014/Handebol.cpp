#include <iostream>

using namespace std;

int main(){
  int cnt = 0, jog, part, gols;

  cin >> jog >> part;

  for(int i = 0; i < jog; i++){
    gols = 0;
    bool check = true;
    for(int j = 0; j < part; j++){
      cin >> gols;
      if(gols < 1){
        check = false;
      }
      if(j == part - 1 && check == true){
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}
