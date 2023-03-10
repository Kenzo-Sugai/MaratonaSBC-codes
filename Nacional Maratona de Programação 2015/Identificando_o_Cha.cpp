#include <iostream>

using namespace std;

int main(){
  
  int N, q = 0, C[5];
  
  cin >> N;
  
  
  for(int i =0 ; i < 5; i++){
    cin >> C[i];  
  }
  for(int i = 0; i < 5; i++){
    if(C[i] == N) q++;
  }
  
  cout << q << endl;
  
  

}
