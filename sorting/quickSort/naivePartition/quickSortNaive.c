#include <stdio.h>
#include <stdlib.h>

void qSort(int *const, const size_t);
void quick(int *const, const long, const long);
long partition(int *const, const long, const long);
void printArr(const int *const, const size_t);

int main(void) {
   int arr[] = {90, 87, 65, 89, -3, 11, 2, 3, 1, 1, 0, 45};
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

void quick(int *const arr, long start, long end) {
   if (start < end) {
      long pivot = partition(arr, start, end);
      
      quick(arr, start, pivot - 1);
      quick(arr, pivot + 1, end);
   }
}

long partition(int *const arr, const long start, const long end) {
   long pivot_index = start + (end - start) / 2;
   int pivot = arr[pivot_index];
   const size_t length = end - start + 1;

   int *smallest = (int *) malloc(length * sizeof(int));
   int *largest = (int *) malloc(length * sizeof(int));
   
   int count_smallest = 0;
   int count_largest = 0;

   for (size_t i = start; i <= end; i++) {
      if (i == pivot_index) continue;

      if (arr[i] <= pivot) {
         smallest[count_smallest] = arr[i];
         count_smallest++;
      } else {
         largest[count_largest] = arr[i];
         count_largest++;
      }
   }

   long k = start;

   for (long i = 0; i < count_smallest; i++)
      arr[k++] = smallest[i];

   pivot_index = k;
   arr[k++] = pivot;

   for (long i = 0; i < count_largest; i++)
      arr[k++] = largest[i];

   free(smallest);
   free(largest);

   return pivot_index;
}

void printArr(const int *const arr, const size_t length) {
   for (size_t i = 0; i < length; i++)
      printf("%d ", arr[i]);
   putchar('\n');
}