#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrix_times(vector<vector<int>> first, vector<vector<int>> second){
    vector<vector<int>> ans(first.size(), vector<int>(second[0].size()));
    for(int i = 0; i < first.size(); i++){
        for(int z = 0; z < second[0].size(); z++){
            int aux = 0;
            for(int j = 0; j < first[i].size(); j++)
                aux += (first[i][j] * second[j][z]);
            ans[i][z] = aux;
        }
    }
    return ans;
}

vector<vector<int>> fast_exp(vector<vector<int>> base, long long exp){
    if(exp == 1)
        return base;
    vector<vector<int>> aux = fast_exp(base, (exp / 2));
    aux = matrix_times(aux, aux);
    return ((exp & 1))? matrix_times(base, aux) : aux;
}

int main(){
    int l1, c1, exp;
    cin >> l1 >> c1 >> exp;
    vector<vector<int>> matrix1(l1, vector<int>(c1, -1));
    for(int i = 0; i < l1; i++){
        for(int j = 0; j < c1; j++){
            int aux;
            cin >> aux;
            matrix1[i][j] = aux;
        }
    }
    vector<vector<int>> result = fast_exp(matrix1, exp);
    for(auto line: result){
        for(auto elem: line){
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}