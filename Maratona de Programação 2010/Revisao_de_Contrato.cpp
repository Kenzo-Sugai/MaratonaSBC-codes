#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    char NumberDeleted;
    string Sequence;

    while(cin >> NumberDeleted >> Sequence){
        if(NumberDeleted == '0' && Sequence[0] == '0'){
            return 0;
        }

        Sequence.erase(remove(Sequence.begin(), Sequence.end(), NumberDeleted), Sequence.end());

        bool lock = true, in = false;

        for(int i = 0; i < Sequence.size(); i++){
            if(Sequence[i] != '0'){
                lock = false;
            }
            if(!lock){
                in = true;
                cout << Sequence[i];
            }
        }
        if(in == false){
            cout << "0" << endl;
        }
        else{
            cout << endl;
        }
    }
}
