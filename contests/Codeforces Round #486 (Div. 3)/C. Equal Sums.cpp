#include <bits/stdc++.h>
using namespace std;
int k;
vector<vector<int>> sequences;

int main(){
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        int z;
        scanf("%d", &z);
        sequences.push_back(vector<int>(z + 1, 0));
        int aux = 0;
        for(int j = 1; j <= z; j++){
            cin >> sequences[i][j];
            aux += sequences[i][j];
        }
        sort(sequences[i].begin() + 1, sequences[i].end());
        sequences[i][0] = aux;
    }
    int i = 0;
    for(i = 1; i < k; i++){
        int aux = abs(sequences[i - 1][0] - sequences[i][0]);
        if(!((sequences[i - 1].size() == sequences[i].size()) && !aux)){
            int num;
            for(int j = 1; j < sequences[i - 1].size(); j++){
                num = aux - sequences[i - 1][j];
                vector<int>::iterator it = lower_bound(sequences[i].begin() + 1, sequences[i].end(), num);
                if(num + sequences[i][it - sequences[i].begin()] == aux){
                    printf("YES\n%d %d\n%d %d\n", i, sequences[i - 1][j], i + 1, sequences[i][it - sequences[i].begin()]);
                    break;
                }
            }
        }
    }
    if(i == k)
        printf("NO\n");
    return 0;
}