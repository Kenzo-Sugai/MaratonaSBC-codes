#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N, D;

    while(cin >> N >> D){

        if(!N and !D) return 0;

        string num;
        
        cin >> num;

        vector<char> stack(N);

        int del = 0;
        int idx = -1;

        for(int i = 0; i < num.size(); i++){
        
            while(idx >= 0 && num[i] > stack[idx] && del < D){
                
                idx--;
                
                del++;

            }

            if(idx+1 < N - D) stack[++idx] = num[i];

        }

        for(int i = 0; i <= idx; i++) cout << stack[i];
        cout << endl; 
        

    }

}
