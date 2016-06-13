template <typename T>
void Vector<T>::quickSort(int lo, int hi) {
    if (hi - lo < 2) return;
    int mi = partition(lo, hi - 1);
    quickSort(lo, mi);
    quickSort(mi + 1, hi);
}

// A
int Vector<T>::partition(int lo, int hi) {
    swap(_elem[lo], _elem[lo + rand() % (hi - lo + 1)]);
    T pivot = _elem[lo];
    while (lo < hi) {
        while ((lo < hi) && (pivot <= _elem[hi]))
            hi--;
        _elem[lo] = _elem[hi];
        while ((lo < hi) && (_elem[lo] <= pivot))
            lo ++;
        _elem[hi] = _elem[lo];
    }
    _elem[lo] = pivot;
    return lo;
}

// B1
int Vector<T>::partition(int lo, int hi) {
    swap(_elem[lo], _elem[lo + rand() % (hi - lo + 1)]);
    T pivot = _elem[lo];
    while (lo < hi) {
        while ((lo < hi) && (pivot < _elem[hi]))
            hi--;
        if (lo < hi)
            _elem[lo++] = _elem[hi];
        while ((lo < hi) && (_elem[lo] < pivot))
            lo ++;
        if (lo < hi)
            _elem[hi--] = _elem[lo];
    }
    _elem[lo] = pivot;
    return lo;
}

// B
int Vector<T>::partition(int lo, int hi) {
    swap(_elem[lo], _elem[lo + rand() % (hi - lo + 1)]);
    T pivot = _elem[lo];
    while (lo < hi) {
        while (lo < hi) {
            if (pivot < _elem[hi])
                hi--;
            else {
                _elem[lo++] = _elem[hi];
                break;
            }
        }
        while (lo < hi) {
            if (_elem[lo] < pivot)
                lo ++;
            else {
                _elem[hi--] = _elem[lo];
                break;
            }
        }
    }
    _elem[lo] = pivot;
    return lo;
}

// C
template <typename T>
int Vector<T>::partition(int lo, int hi) {
    swap(_elem[lo], _elem[lo + rand() % (hi - lo + 1)]);
    T pivot = _elem[lo];
    int mi = lo;
    for (int k = lo + 1; k <= hi; k++) {
        if (_elem[k] < pivot) {
            swap(_elem[++mi], _elem[k]);
        }
    }
    swap(_elem[lo], _elem[mi]);
    return mi;
}