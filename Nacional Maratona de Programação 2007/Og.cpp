#include <iostream>
 
using namespace std;
 
int main() {
 
    int e, d;
    while(cin >> e >> d){
        if(e == 0 && d == 0){
            break;
        }
        cout << e+d << endl;
    }
}
