#include <iostream>

using namespace std;


// method 1
void bubbleSort1(int A[], int n) {
    for (bool sorted = false; sorted = !sorted; n--) {
        for (int i = 0; i < n; ++i) {
            if (A[i-1] > A[i]) {
                swap(A[i-1], A[i]);
                sorted = false;
            }
        }
    }
}

// method 2
template <typename T>
void Vector<T>::bubbleSort(int lo, int hi) {
    while (!bubble(lo, hi--));
}

template <typename T>
bool Vector<T>::bubble(int lo, int hi) {
    bool sorted = true;
    while(++lo < hi) {
        if (_elem[lo-1] > _elem[lo]) {
            sorted = false;
            swap(_elem[lo], _elem[lo-1]);
        }
    }
    return sorted;
}

// method 3

template <typename T>
void Vector<T>::bubbleSort(int lo, int hi) {
    while (lo < (hi = bubble(lo, hi)));
}

template <typename T>
bool Vector<T>::bubble(int lo, int hi) {
    int last = lo;
    while (++lo < hi) {
        if (_elem[lo - 1] > _elem[lo]) {
            last = lo;
            swap(_elem[lo - 1], _elem[lo]);
        }
    }
    return last;
}

int main() {

    return  0;
}