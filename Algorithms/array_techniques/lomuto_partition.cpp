#include <bits/stdc++.h>
using namespace std;

/* ---------------------------- Lomuto Partition ---------------------------- */
/*
    In the Lomuto partition scheme, we choose the last element of the array as
    the pivot.

    We use two variables:
    - i: represents the boundary of elements that are <= pivot.
    - j: traverses the array from left to right.

    Initially, i is one position before the beginning of the subarray because
    we have not found any element that is <= pivot yet.

    As j traverses the array, whenever we find an element a[j] <= pivot, we
    first increment i. Since i marks the end of the <= pivot region, i + 1 was
    previously the first element of the > pivot region. By incrementing i, we
    expand the <= pivot region by one position. We then swap a[i] with a[j] so
    that the newly found smaller element becomes part of the <= pivot region.

    After traversing the entire array, every element from low to i is <= pivot,
    while every element from i + 1 to high - 1 is > pivot. Finally, we swap
    a[i + 1] with the pivot, placing the pivot between the two regions.

    The final arrangement is:
        [ elements <= pivot ] [ pivot ] [ elements > pivot ]
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> a = {3, 4, 0, 1, 3, 2};
    int n = a.size();
    int low = 0;
    int high = n-1;
    int pivot = a[high];
    int i = low-1;
    for(int j = low; j<high; j++){
        if(a[j] <= pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[high]);
    for(int x: a){
        cout << x << ' ';
    }
    return 0;
}