#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

int getMax(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void merge(int a[], int l, int m, int r,int p)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    int L[n1], R[n2];
  
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];
  
    i = 0; 
    j = 0; 
    k = l;
    while (i < n1 && j < n2) {
        if ((L[i]/p)%10 <= (R[j]/p)%10) {
           a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
  
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
  
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}
  
void mergeSort(int a[], int l, int r,int p)
{
    if (l < r) {
        int m = l + (r - l) / 2;
  
        mergeSort(a, l, m,p);
        mergeSort(a, m + 1, r,p);
  
        merge(a, l, m, r,p);
    }
}

void countingSort(int array[], int size, int place)
{
    const int max = 10;
    int output[size];
    int count[max];

    for (int i = 0; i < max; ++i)
        count[i] = 0;

    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;

    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
        array[i] = output[i];
}

void radixsort(int a[], int size)
{
    auto start = high_resolution_clock::now();
    int max = getMax(a, size);

    for (int place = 1; max / place > 0; place *= 10)
        countingSort(a, size, place);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
}

void printArray(int a[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int a[1000];
    for (int i = 0; i < 1000; i++)
    {
        a[i] = (rand() % 100000) + 100000;
    }
    radixsort(a, 1000);
    printArray(a, 1000);
}
