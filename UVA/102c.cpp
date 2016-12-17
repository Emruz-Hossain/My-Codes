#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#define S 4
#define MN 2147483647
using namespace std;
int main(){
    int b[S], g[S], c[S], srt[S], temp[S][S][S];
    int p[S], tot_B[S], tot_G[S], tot_C[S];
    while(cin >> b[1] >> g[1] >> c[1]){
        cin >> b[2] >> g[2] >> c[2] >> b[3] >> g[3] >> c[3];
        tot_B[1] = b[1]+b[2], tot_B[2] = b[2]+b[3], tot_B[3] = b[1]+b[3];
        tot_G[1] = g[1]+g[2], tot_G[2] = g[2]+g[3], tot_G[3] = g[1]+g[3];
        tot_C[1] = c[1]+c[2], tot_C[2] = c[2]+c[3], tot_C[3] = c[1]+c[3];
        int ansN = MN, flag = 0;
        temp[1][2][3] = tot_B[1]+tot_G[2]+tot_C[3], ansN = min(ansN, temp[1][2][3]);
        temp[1][3][2] = tot_B[1]+tot_G[3]+tot_C[2], ansN = min(ansN, temp[1][3][2]);
        temp[2][1][3] = tot_B[2]+tot_G[1]+tot_C[3], ansN = min(ansN, temp[2][1][3]);
        temp[2][3][1] = tot_B[2]+tot_G[3]+tot_C[1], ansN = min(ansN, temp[2][3][1]);
        temp[3][1][2] = tot_B[3]+tot_G[1]+tot_C[2], ansN = min(ansN, temp[3][1][2]);
        temp[3][2][1] = tot_B[3]+tot_G[2]+tot_C[1], ansN = min(ansN, temp[3][2][1]);
        for(int i = 1; i <= 3; i++){
            for(int j = 1; j <= 3; j++){
                for(int k = 1; k <= 3; k++){
                    if(ansN == temp[i][j][k]){
                        if(tot_B[i] <= tot_G[j] && tot_G[j] <= tot_C[k])cout << "BGC ";
                        else if(tot_B[i] <= tot_C[k] && tot_C[k] <= tot_G[j])cout << "BCG ";
                        else if(tot_G[j] <= tot_B[i] && tot_B[i] <= tot_C[k])cout << "GBC ";
                        else if(tot_G[j] <= tot_C[k] && tot_C[k] <= tot_B[i])cout << "GCB ";
                        else if(tot_C[k] <= tot_B[i] && tot_B[i] <= tot_G[j])cout << "CBG ";
                        else if(tot_C[k] <= tot_G[j] && tot_G[j] <= tot_B[i])cout << "CGB ";
                        flag = 1;
                    }
                    if(flag)break;
                }
                if(flag)break;
            }
            if(flag)break;
        }
        cout << ansN << endl;
    }
    return 0;
}
