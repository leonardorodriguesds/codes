#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, aux;
    vector<int> students;
    set<int> student;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &aux);
        students.push_back(aux);
        student.insert(aux);
    }
    printf("%s\n", (student.size() >= k? "YES" : "NO"));
    if(student.size() >= k){
        int j = 0;
        map<int, bool> showing;
        for(int i = 0; i < students.size(); i++){
            if(j == k)
                break;
            if(!showing.count(students[i])){
                showing[students[i]] = true;
                printf("%d ", i + 1);
                j++;
            }
        }
        printf("\n");
    }
    return 0;
}