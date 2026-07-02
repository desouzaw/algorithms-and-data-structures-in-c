#include <stdio.h>

void printArr(const int *const, const size_t);
void i_sort(int *const, const size_t);
long binarySearch(const int *const, const size_t, const int) ;

int main(void) {
   int arr[] = {9, 7, 0, -4, 11, 32, -8, 67, 14};
   const size_t length = sizeof(arr) / sizeof(int);
   long result;
   int n;

   i_sort(arr, length);

   for (size_t i = 0; i < length; i++)
      printf("[%lu]  ", i);
   putchar('\n');

   printArr(arr, length);
   printf("\nQue número deseja buscar? ");
   scanf("%d", &n);

   result = binarySearch(arr, length, n);

   if (result != -1)
      printf("Número encontrado no índice %ld\n", result);
   else
      printf("Número não encontrado\n");

   return 0;
}

void printArr(const int *const arr, const size_t length) {
   for (size_t i = 0; i < length; i++)
      printf("%3d  ", arr[i]);
   putchar('\n');
}

void i_sort(int *const arr, const size_t length) {
   if (length < 2) return;

   for (size_t i = 1; i < length; i++) {
      int key = arr[i];
      long j = i - 1;

      while ((j >= 0) && arr[j] > key) {
         arr[j + 1] = arr[j];
         j--;
      }

      arr[j + 1] = key;
   }
}

long binarySearch(const int *const arr, const size_t length, const int n) {
   long start = 0, end = length;

   while (start <= end) {
      long middle = start + (end - start) / 2;

      if (arr[middle] == n)
         return middle;
      else if (arr[middle] < n)
         start = middle + 1;
      else
         end = middle - 1;
   }

   return -1;
}