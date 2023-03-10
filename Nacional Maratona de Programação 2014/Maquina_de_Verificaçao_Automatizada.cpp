#include <iostream>

using namespace std;

int main(){

    int check[5], n;

    for(int i = 0; i < 5; i++){
        cin >> check[i];
    }
    for(int i = 0; i < 5; i++){
        cin >> n;
        if(check[i] == n){
            cout << "N" << endl;
            return 0;
        }
    }
    cout << "Y" << endl;

}
