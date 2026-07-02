#include <stdio.h>

void printArr(const int *const, const size_t);
long linearSearch(const int *const, const size_t, const int);

int main(void) {
   int arr[] = {6, 2, -8, 0, -6, 11, 67, 5, 21, 30};
   const size_t length = sizeof(arr) / sizeof(int);
   long result;
   int n;

   for (size_t i = 0; i < length; i++)
      printf("[%lu]  ", i);
   putchar('\n');

   printArr(arr, length);
   printf("\nQue número deseja buscar? ");
   scanf("%d", &n);

   result = linearSearch(arr, length, n);

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

long linearSearch(const int *const arr, const size_t length, const int n) {
   for (long i = 0; i < length; i++)
      if (arr[i] == n)
         return i;
   return -1;
}