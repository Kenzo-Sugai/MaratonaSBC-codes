#include <iostream>
#include <vector>
#include <string>

using namespace std;

void paint(char k, vector<vector<char>> &M, int j){

    if(k == '1'){
        M[0][j] = '*';
    }
    if(k == '2'){
        M[0][j] = '*';
        M[1][j] = '*';
    }
    if(k == '3'){
        M[0][j] = '*';
        M[0][j+1] = '*';
    }
    if(k == '4'){
        M[0][j] = '*';
        M[0][j+1] = '*';
        M[1][j+1] = '*';
    }
    if(k == '5'){
        M[0][j] = '*';
        M[1][j+1] = '*';
    }
    if(k == '6'){
        M[0][j] = '*';
        M[0][j+1] = '*';
        M[1][j] = '*';
    }
    if(k == '7'){
        M[0][j] = '*';
        M[0][j+1] = '*';
        M[1][j] = '*';
        M[1][j+1] = '*';
    }
    if(k == '8'){
        M[0][j] = '*';
        M[1][j] = '*';
        M[1][j+1] = '*';
    }
    if(k == '9'){
        M[0][j+1] = '*';
        M[1][j] = '*';
    }
    if(k == '0'){
        M[0][j+1] = '*';
        M[1][j] = '*';
        M[1][j+1] = '*';
    }
}

char check(vector<vector<char>> M, int j){
   
    if(M[0][j] == '*' && M[0][j+1] == '.' && M[1][j] == '.' && M[1][j+1] == '.') return '1';
    if(M[0][j] == '*' && M[0][j+1] == '.' && M[1][j] == '*' && M[1][j+1] == '.') return '2';
    if(M[0][j] == '*' && M[0][j+1] == '*' && M[1][j] == '.' && M[1][j+1] == '.') return '3';
    if(M[0][j] == '*' && M[0][j+1] == '*' && M[1][j] == '.' && M[1][j+1] == '*') return '4';
    if(M[0][j] == '*' && M[0][j+1] == '.' && M[1][j] == '.' && M[1][j+1] == '*') return '5';
    if(M[0][j] == '*' && M[0][j+1] == '*' && M[1][j] == '*' && M[1][j+1] == '.') return '6';
    if(M[0][j] == '*' && M[0][j+1] == '*' && M[1][j] == '*' && M[1][j+1] == '*') return '7';
    if(M[0][j] == '*' && M[0][j+1] == '.' && M[1][j] == '*' && M[1][j+1] == '*') return '8';
    if(M[0][j] == '.' && M[0][j+1] == '*' && M[1][j] == '*' && M[1][j+1] == '.') return '9';
    if(M[0][j] == '.' && M[0][j+1] == '*' && M[1][j] == '*' && M[1][j+1] == '*') return '0';
    

}

int main(){

    int N;
    char t;
    string n;

    while(cin >> N){
        if(!N) break;
        cin >> t;
        vector<vector<char>> M(3);
        if(t == 'S'){
            cin >> n;

            for(int i = 0; i < M.size(); i++){
                for(int j = 0; j < N*2; j++){
                    M[i].push_back('.');
                }
            }

            int c = 0;
            for(int i = 0; i < N*2; i+=2){
                n[c];
                paint(n[c], M, i);
                c++;
            }
            for(int i = 0; i < M.size(); i++){
                for(int j = 0; j < M[i].size(); j++){
                    if(j != 0 && j % 2 == 0) cout << " ";
                    cout << M[i][j];
                }
                cout << endl;
            }
        }
        else{
            string sub;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < N; j++){
                    cin >> sub;
                    M[i].push_back(sub[0]);
                    M[i].push_back(sub[1]);
                }
            }

            string total = "";
            int j = 0;
            for(int i = 0; i < N; i++){
              total += check(M, j);
              j += 2;
            }
            cout << total << endl;

        }
        


    }

}
