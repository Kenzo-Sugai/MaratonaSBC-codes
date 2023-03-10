#include <iostream>
using namespace std;

int main(){

  int n;
  while(cin >> n){
    if(n == 0){
      break;
    }
    int Qn = 0;
    for(int i = 1; i <= n; i++){
      Qn += i*i;
    }
    cout << Qn << endl;
  }
}
