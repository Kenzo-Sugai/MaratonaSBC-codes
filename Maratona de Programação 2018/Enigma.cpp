#include <iostream>

using namespace std;

int main(){

    string word, enigma;

    cin >> word;
    cin >> enigma;

    int contador = 0;

    for(int i = 0; i + enigma.size() <= word.size(); i++){

        bool check = false;
        
        for(int j = 0; j < enigma.size(); j++){

            if(word[i + j] == enigma[j]) { check = true; break; }
            
        }

        if(!check) contador++;

    }

    cout << contador << endl;


}
