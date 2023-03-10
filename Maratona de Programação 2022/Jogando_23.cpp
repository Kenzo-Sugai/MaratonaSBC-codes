#include <iostream>
#include <vector>
 
using namespace std;
 
int main(){
 
    vector<int> cards(15, 4);
    int N, J = 0, M = 0, c1, c2;
 
    cin >> N;
 
    cin >> c1 >> c2;
 
    cards[c1]--; cards[c2]--;
 
    if(c1 > 10) c1 = 10;
    if(c2 > 10) c2 = 10;
 
    J += c1; J += c2;
 
    cin >> c1 >> c2;
 
    cards[c1]--; cards[c2]--;
 
    if(c1 > 10) c1 = 10;
    if(c2 > 10) c2 = 10;
 
    M += c1; M += c2;
 
    for(int i = 0; i < N; i++){
 
        cin >> c1;
 
        cards[c1]--;
 
        if(c1 > 10) c1 = 10;
 
        J += c1; M += c1;
 
    }
 
    int ans = -1;
 
    for(int i = 1; i < 14; i++){
 
        if(cards[i] > 0){
            int c = i;
            if(c > 10) c = 10;
 
            if(M + c == 23 || (J + c > 23 && M + c <= 23)){
                ans = i;
                break;
            }
        }
 
    }
 
    cout << ans << endl;
 
}
