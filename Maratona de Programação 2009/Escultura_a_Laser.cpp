#include <iostream>

using namespace std;

int main(){

    int A, C, n;

    while(cin >> A >> C){
        if(!A & !C) return 0;
        int alturas[C];

        int cnt = 0, alturaAnt = 0, altura;

        for(int i = 0; i < C; i++){

            cin >> alturas[i];
            altura = A - alturas[i];
            if(altura > alturaAnt){
                cnt += altura - alturaAnt;
            }
            alturaAnt = altura;

        }

        cout << cnt << endl;

    }

}
