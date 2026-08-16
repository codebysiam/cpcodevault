#include <bits/stdc++.h>
using namespace std;

/* ----------------------------- Hoare's Partition -----------------------------*/
/*
    In Hoare's Partition, we choose the first element as the pivot value.
    We use two pointers, i and j. i starts from one index before the first
    element, and j starts from one index after the last element. Then we
    repeatedly move the two pointers toward each other. i keeps increasing by
    1 until it finds an element greater than or equal to the pivot, and j
    keeps decreasing by 1 until it finds an element less than or equal to the
    pivot. Then we swap them, like trading the greater element for the lesser
    element. We keep doing this until i and j point to the same index or
    i > j. When we reach i >= j, our partitioning is complete, and all
    elements in the array are arranged around the partition such that every
    element on the left is less than or equal to the pivot, and every element
    on the right is greater than or equal to the pivot.

    Unlike Lomuto's Partition, Hoare's Partition does not place the pivot into
    its final sorted position. Instead, it only guarantees that the array is
    divided into two partitions around the pivot value.
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& x : a){
        cin >> x;
    }
    int pivot = a[0];
    int i = -1;
    int j = n;
    while(true){
        do{
            i++;
        }while(a[i] < pivot);
        do{
            j--;
        }while(a[j] > pivot);
        if(i >= j) break;
        swap(a[i], a[j]);
    }
    for(int x: a){
        cout << x << ' ';
    }
    return 0;
}