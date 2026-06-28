#include <stdio.h>

void qSort(int *const, const size_t);
void quick(int *const, const long, const long);
long partition(int *const, long, long);
void printArr(const int *const, const size_t);
void swap(int *const, int *const);

int main(void) {
   int arr[] = {98, 5, 6, -9, 21, 13, 4, 87};
   const size_t length = sizeof(arr) / sizeof(int);

   printf("Antes da ordenação: ");
   printArr(arr, length);
   qSort(arr, length);
   printf("Depois da ordenação: ");
   printArr(arr, length);

   return 0;
}

void qSort(int *const arr, const size_t length) {
   if (length < 2) return;

   quick(arr, 0, length - 1);
}

void quick(int *const arr, const long start, const long end) {
   if (start < end) {
      long pivot = partition(arr, start, end);
      quick(arr, start, pivot);
      quick(arr, pivot + 1, end);
   }
}

long partition(int *const arr, long start, long end) {
   int pivot = arr[start + (end - start) / 2];

   while (1) {
      while (arr[start] < pivot) start++;
      while (arr[end] > pivot) end--;

      if (start >= end)
         return end;

      swap(&arr[start], &arr[end]);
      start++;
      end--;
   }
}

void printArr(const int *const arr, const size_t length) {
   for (size_t i = 0; i < length; i++)
      printf("%d ", arr[i]);
   putchar('\n');
}

void swap(int *const a, int *const b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}