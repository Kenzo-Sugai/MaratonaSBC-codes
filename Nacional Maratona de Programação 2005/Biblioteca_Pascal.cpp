#include <iostream>
#include <vector>

using namespace std;

int main(){
  int N, J, n;
  
  while(cin >> N >> J){
    if(!N and !J) return 0;
    bool check = false;
    vector<int> A(N, 0);  
    for(int j = 0; j < J; j++){
      
      for(int i = 0; i < N; i++){
        cin >> n;
        A[i] += n;
        if(A[i] == J) check = true;
      }
    }
    check ? cout << "yes" << endl : cout << "no" << endl;
  }

} 
