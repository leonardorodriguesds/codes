#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, last = 0;
    scanf("%d", &n);
    vector<pair<int, int>> ans;
    ans.push_back(make_pair(0, 0));
    ans.push_back(make_pair(0, 1));
    ans.push_back(make_pair(0, 2));
    for(int i = 0; i < n; i++){
        int aux;
        scanf("%d", &aux);
        ans[last].first += aux;
        last++;
        if(last == 3)
            last = 0;
    }
    sort(ans.begin(), ans.end(), greater<pair<int, int>>());
    if(ans[0].second == 0)
        printf("chest\n");
    else if(ans[0].second == 1)
        printf("biceps\n");
    else
        printf("back\n");
    return 0;
}