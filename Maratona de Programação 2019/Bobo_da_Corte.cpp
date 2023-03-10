#include <iostream>

using namespace std;

int N, voto, maior {0}, ganhador;

int main(){

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> voto;
        if(voto > maior){
            ganhador = i;
            maior = voto;
        }
    }

    if(ganhador == 0){
        cout << "S" << endl;
    }
    else{
        cout << "N" << endl;
    }
}
