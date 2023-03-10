#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
 
    string S, temp, reversetemp;
    cin >> S;
    for(int i : S){
        if(i == 'a' or i == 'e' or i == 'i' or i == 'o' or i == 'u'){
            temp += i;
        }
    }
    reversetemp = temp;
    reverse(reversetemp.begin(), reversetemp.end());
    
    if(temp == reversetemp) cout << "S" << endl;
    else cout << "N" << endl;
 
    return 0;
}
