#include <iostream>
 
using namespace std;
 
int main(){
 
    int T, D, M, n;
 
    cin >> T >> D >> M;
    int tempo = 0;
    for(int i = 0; i < M; i++){
 
        cin >> n;
        tempo = n - tempo;
 
        if(tempo >= T){
            cout << "Y" << endl;
            return 0;
        }
        tempo = n;
 
    }
 
    tempo = D - tempo;
 
    if(tempo >= T){
        cout << "Y" << endl;
        return 0;
    }
 
    cout << "N" << endl;
 
 
}
