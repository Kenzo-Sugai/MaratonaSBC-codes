#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

struct tempo {
    int h,m,s;
    char sinal;
};

void fillVector(deque<int> &idx, vector<tempo> &hor, int E, int X){

    for(int i = 0; i < E; i++){
        int front = idx.front();
        hor[front].sinal = 'E';
        idx.pop_front();
    }
    for(int i = 0; i < X; i++){
        int back = idx.back();
        hor[back].sinal = 'X';
        idx.pop_back();
    }
    int n = idx.size();
    int i = 0;
    for(; i < n / 2; i++){
        int front = idx.front();
        hor[front].sinal = 'E';
        idx.pop_front();
    }
    for(; i < n; i++){
        int front = idx.front();
        hor[front].sinal = 'X';
        idx.pop_front();
    }
}

bool comp(tempo a, tempo b){

    if(a.h == b.h){

        if(a.m == b.m){

            return a.s < b.s;

        }

        return a.m < b.m;

    }

    return a.h < b.h;

}

int main(){

    int N;

    while(cin >> N && N){

        int h, m, s;
        char p, K;

        vector<tempo> horario;

        for(int i = 0; i < N; i++){

            cin >> h >> p >> m >> p >> s >> K;
            horario.push_back({h,m,s,K});

        }

        sort(horario.begin(), horario.end(), comp);

        int cnt = 0;

        deque<int> saveIdx;

        for(int i = 0; i < N; i++){
            
            if(horario[i].sinal == 'E') cnt++;
            if(horario[i].sinal == 'X') cnt--;
            if(horario[i].sinal == '?') saveIdx.push_back(i);
            
        }

        if(cnt == 0) fillVector(saveIdx, horario, 0, 0);
        else if(cnt < 0) fillVector(saveIdx, horario, abs(cnt), 0);
        else if(cnt > 0) fillVector(saveIdx, horario, 0, cnt);

        //for(int i = 0; i < N; i++) cout << horario[i].sinal << " ";

        int maxPessoas = 0;

        cnt = 0;

        for(int i = 0; i < N; i++){

            if(horario[i].sinal == 'E') cnt++;
            if(horario[i].sinal == 'X') cnt--;

            maxPessoas = max(maxPessoas, cnt);

        }

        cout << maxPessoas << endl;

    }


}
