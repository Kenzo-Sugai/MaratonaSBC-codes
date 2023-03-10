#include <iostream>
 
using namespace std;
 
int main() {
 
    int N, n;
    
    cin >> N;
    int cnt = 0;
    while(N--){
        
        cin >> n;
        if(n != 1) cnt++;
    }
    
    cout << cnt << endl;
 
    return 0;
}
