#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, j, last = 0;
    scanf("%d", &n);
    vector<int> students_;
    vector<int> students;
    for(int i = 0; i < n; i++){
        int aux;
        scanf("%d", &aux);
        students_.push_back(aux);
        students.push_back(aux);
    }
    sort(students.begin(), students.end(), greater<int>());
    map<int, int> ordering;
    j = 0;
    for(int i = 0; i < n; i++)
        ordering[students[i]] = (i && students[i] == students[i - 1])? ordering[students[i - 1]] : i;

    for(auto student: students_)
        printf("%d ", ordering[student] + 1);
    printf("\n");
    return 0;
}