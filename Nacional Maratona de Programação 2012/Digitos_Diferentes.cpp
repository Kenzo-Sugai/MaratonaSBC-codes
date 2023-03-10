#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int main(){

  int num[10];
  string N, M ,n;

  while(cin >> N >> M){
    int total = 0;

    for(int i = stoi(N); i <= stoi(M); i++){
      
      bool verify = false;
      memset(num, 0, sizeof(num));
      n = to_string(i);
      
      for(int j = 0; j < n.size(); j++){

        if(num[(int)n[j] - 48] > 0){
          verify = true;
          break;
        }
        else{
          num[(int)n[j] - 48] += 1;
        }
      }
      if(verify == false){
        total++;
      }
    }
    cout << total << endl;
  }
}
