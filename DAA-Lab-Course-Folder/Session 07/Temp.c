long int MergeSort(Record *A, int l, int r) {
  int T1, T2;
  if (l < r) {
      int m = l+(r-l)/2;
      T1 = MergeSort(A, l, m);
      T2 = MergeSort(A, m+1, r);
      return T1 + T2 + Merge(A, l, m, r);
  }
  return 0;
}

int Merge(Record* A, int l, int m, int r) {
    int i, j, k, count;
    int n1 = m - l + 1;
    int n2 =  r - m;

    Record L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = A[l + i];
    for (j = 0; j < n2; j++)
        R[j] = A[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i].serialnumber <= R[j].serialnumber) {
            A[k] = L[i];
            i++;
            count++;
        }
        else {
            A[k] = R[j];
            j++;
            count++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}
