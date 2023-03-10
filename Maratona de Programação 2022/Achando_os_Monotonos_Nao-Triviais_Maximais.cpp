#include <iostream>
 
using namespace std;
 
int main(){
 
    int N;
    cin >> N;
    string seq;
    cin >> seq;
 
    char check = seq[0];
    int cache[2] = {0, 0};
    int cnt = 1;
 
    for(int i = 1; i < N; i++){
 
        if(seq[i] == check) cnt++;
        else{
 
            if(cnt > 1) cache[check - 'a'] += cnt;
            
            cnt = 1;
 
        }
 
        check = seq[i];
 
    }
 
    if(cnt > 1) cache[check - 'a'] += cnt;
    
    cout << cache[0] << endl;
 
}
