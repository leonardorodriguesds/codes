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

int main(){
    int l1, c1;
    cin >> l1 >> c1;
    vector<vector<int>> matrix1(l1, vector<int>(c1, -1));
    for(int i = 0; i < l1; i++){
        for(int j = 0; j < c1; j++){
            int aux;
            cin >> aux;
            matrix1[i][j] = aux;
        }
    }
    int l2, c2;
    cin >> l2 >> c2;
    vector<vector<int>> matrix2(l2, vector<int>(c2, -1));
    for(int i = 0; i < l2; i++){
        for(int j = 0; j < c2; j++){
            int aux;
            cin >> aux;
            matrix2[i][j] = aux;
        }
    }
    vector<vector<int>> result = matrix_times(matrix1, matrix2);
    for(auto line: result){
        for(auto elem: line){
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}