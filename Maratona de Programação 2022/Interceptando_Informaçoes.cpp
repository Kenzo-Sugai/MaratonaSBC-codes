#include <iostream>
 
using namespace std;
 
int main(){
 
    int n;
    string resp = "S";
 
    for(int i = 0; i < 8; i++){
 
        cin >> n;
        if(n > 1) resp = "F";
 
    }
 
    cout << resp << endl;
 
}
