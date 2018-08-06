#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
#define uIndex(x, v)     (upper_bound(all(v), x) - v.begin())
#define lIndex(x, v)     (lower_bound(all(v), x) - v.begin())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<pair<int, ii>> vpii;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<string> vs;

int merge(int, int, int, vi&);
int mergeSort(int, int, vi&);

int merge(int l, int m, int r, vi& numbers){
    int ans = 0;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = numbers[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = numbers[m + 1 + j];

    int i = 0, j = 0, k = l;
    for(; i < n1 && j < n2; k++){
        if (L[i] <= R[j])
            numbers[k] = L[i++];
        else
            numbers[k] = R[j++], ans++;
    }
    while (i < n1)
        numbers[k++] = L[i++];
    while (j < n2)
        numbers[k++] = R[j++];
    return ans;
}

int mergeSort(int l, int r, vi& numbers){
    if(!(l < r))
        return 0;

    int ans = 0;
    int middle = l + (r - l) / 2;
    ans += mergeSort(l, middle, numbers);
    ans += mergeSort(middle + 1, r, numbers);
    ans += merge(l, middle, r, numbers);
    return ans;
}

int main(){
    int n;
    while(true){
        scanf("%d", &n);
        if(n == 0)
            break;
        vi numbers;
        for (int i = 0; i < n; i++){
            int aux;
            scanf("%d", &aux);
            numbers.push_back(aux);         
        }
        printf("%s\n", !(mergeSort(0, n - 1, numbers) & 1)? "Carlos" : "Marcelo");
    }
    return 0;
}