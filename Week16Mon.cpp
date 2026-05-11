#include <iostream>
#include "MinHeap.hpp"
using namespace std;

// Use a MinHeap to sort ascending
template <typename T>
void heapsort(vector<T>& arr) {
    MinHeap<T> h;
    for (const T& e : arr){
        h.insert(e);
    }
    //for (int i = (arr.size()/2)-1; i >= 0; i--){
    //    h->siftDown(i);
    //}
    // TODO: Insert all elements into heap using sift-down insert from lecture

    int s = h.size();
    for (int j = 0; j < s; j++){
        arr[j] = h.removeRoot(); // least to greatest
    }
    // TODO: Repeatedly remove root and store back into array
}

int main() {
    vector<int> arr = {5, 1, 9, 3, 7, 4};
    cout << "Before Heapsort: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    heapsort(arr);
    cout << "After Heapsort: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
