#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void importArray(int A[], int n)
{
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "A[" << i << "]: ";
        cin >> A[i];
    }
}

void exportArray(int A[], int n)
{
    cout << "Mang da nhap:\n";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int divArray(int A[], int left, int right)
{
    int pivot = A[right];
    int i = left - 1;
    for (int j = left; j <= right - 1; j++)
    {
        if (A[j] < pivot)
        {
        }
    }
}

// Hàm sắp xếp nhanh
void QuickSort(int A[], int left, int right)
{
    if (left < right)
    {
        int pi = divArray(A, left, right);

        QuickSort(A, left, pi - 1);
        QuickSort(A, pi + 1, right);
    }
}

void Merge(int A[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = A[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = A[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}
int main()
{
    int n;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;

    int *arr = new int[n];

    // Sinh ngẫu nhiên các số trong mảng
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }

    // Xuất mảng trước khi sắp xếp
    exportArray(arr, n);

    // Sắp xếp nhanh và đo thời gian
    clock_t start = clock();
    QuickSort(arr, 0, n - 1);
    clock_t end = clock();
    double quicksort_time = double(end - start) / CLOCKS_PER_SEC;
}