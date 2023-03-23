#include <iostream>

using namespace std;

int main(){

    string S;

    cin >> S;

    int soma = 0, notas = 0, i = 0;

    while(i < S.size()){

        if(i < S.size() - 1 && S[i] == '1' && S[i+1] == '0'){

            soma += 10;
            notas++;
            i += 2;
        }
        else{
            soma += S[i] - '0';
            notas++;
            i++;
        }
    }

    double media = (double)soma/(double)notas;

    printf("%.2f\n", media);

}
