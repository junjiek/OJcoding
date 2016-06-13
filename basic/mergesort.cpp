template <typename T>
void Vector<T>::mergeSort(int lo, int hi) { // [lo, hi)
    if (hi - lo < 2) return;
    int mi = (hi + lo) / 2;
    mergeSort(lo, mi);
    mergeSort(mi, hi);
    merge(lo, mi, hi);
}

template <typename T>
void Vector<T>::merge(int lo, int mi, int hi) {
    T* A = _elem + lo;
    int lb = mi - lo;
    T* B = new T[lb];
    for (int i = 0; i < lb; i++)
        B[i] = A[i];
    int lc = hi - mi;
    T* C = _elem + mi;
    for (int i = 0, j = 0, k = 0; (j < lb) || (k < lc); ) {
        if ((j < lb) && (lc <= k || B[j] < C[k]))
            A[i++] = B[j++];
        if ((k < lc) && (lb <= j || C[k] < B[j]))
            A[i++] = C[k++];            
    }

}


// improved
for (int i = 0, j = 0, k = 0; (j < lb) || (k < lc); ) {
    if ((k < lc) && (j >= lb || C[k] < B[j]))
        A[i++] = C[k++];
    if ((j < lb) && (k >= lc || B[j] <= C[k]))
        A[i++] = B[j++];
}

// ---------- List ----------

template <typename T>
void List<T>::mergeSort(Posi(T)& p, int n) {
    if (n < 2) return;
    Posi(T) q = p;
    int m = n >> 1;
    for (int i = 0; i < m; i ++)
        q = q->succ;
    mergeSort(p, m);
    mergeSort(q, n-m);
    merge(p, m, *this, q, n-m);
}

template <typename T>
void List<T>::merge(Posi(T)& p, int n, List<T>& L, Posi(T) q, int m) {
    while (0 < m) {
        if ((n > 0) && (p->data <= q->data)) {
            if (q == (p = p->succ))
                break;
            n--;
        } else {
            insertBefore(p, L.remove((q = q->succ)->pred));
            m--;
        }

    }
}