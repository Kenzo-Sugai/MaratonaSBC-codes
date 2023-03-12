#include <iostream>

using namespace std;

int main(){

    int N, tempo;
    string T;
    cin >> N;

    for(int i = 0; i < N; i++){
        bool check = false;
        cin >> tempo >> T;
        if(tempo > 45){
            check = true;
            tempo -= 45;
        }

        if(check){
            if(T[0] == '1'){
                cout << 45;
            } else{
                cout << 90;
            }
            cout << "+" << tempo << endl;  
        }else{
            if(T[0] == '1'){
                cout << tempo << endl;
            } else{
                cout << tempo + 45 << endl;
            }
        }
    }

}
