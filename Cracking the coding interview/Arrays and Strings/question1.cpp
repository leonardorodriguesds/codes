#include <bits/stdc++.h>
using namespace std;

/** Solution 2:
 * That solution uses 2 steps.
 * 
 * The first one:
 *     First, the string was sorted by alphabetical order,
 *     Second, all character are sought by binary search.
 * */
int partition(char*, int, int);
void quicksort(char*, int, int);
bool search(char*, char, int, int);

void quicksort(char* str, int lo, int hi){
    /** The QuickSort algorithm:
     * The first time, the algorithm looks for a pivot,
     * After, the string was cut by middle,
     * The algorithm run by recursion.
     * */
    int p;
    if(lo < hi){
        p = partition(str, lo, hi); 
        quicksort(str, lo, p);
        quicksort(str, p + 1, hi);
    }
}
int partition(char* str, int lo, int hi){
    char pivot = str[(lo + hi) / 2];
    int i = lo - 1, j = hi + 1;
    do{
        do
            i++;
        while(str[i] < pivot);
        do
            j--;
        while(str[j] > pivot);
        if(i >= j)
            return j;
        swap(str[i], str[j]);
    } while(true);
}
bool search(char* str, char character, int i, int size){
    int left, right, middle;
    left = i + 1;
    right = size;
    while(left <= right){
        middle = (left + right) / 2;
        if(str[middle] > character)
            right = middle - 1;
        else if(str[middle] < character)
            left = middle + 1;
        else
            return false;
    }
    return true;
}
int main(){
    string str_;
    cin >> str_;
    bool ans = true;
    /** Solution 1.
     * That solution use data structures. 
     * */
    int j;
    int checker = 0;
    for(int i = 0; i < str_.size(); i++){
        j = str_[i] - 'a';
        if((checker & (1 << j)) > 0){
            ans = false;
            break;
        }
        checker = checker | (1 << j);
    }

    if(ans)
        printf("True\n");
    else
        printf("False\n");

    /** Solution 2.
     *  Noone data structure was used by implementing that code.
     *  
     *  Answer:
     *  Checked and corresponds for book solution.
     * */
    ans = true;
    char *str = new char[str_.length() + 1];
    strcpy(str, str_.c_str());
    quicksort(str, 0, str_.size() - 1); //QuickSort algorithm
    for(int i = 0; i < str_.size(); i++){
        if(!search(str, str[i], i, str_.size() - 1)){
            ans = false;
            break;
        }
    }
    if(ans)
        printf("True\n");
    else
        printf("False\n");
    return 0;
}