#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void selection_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void quick_sort(int *arr, size_t size);
void quick_recursive(int *array, size_t size, int low, int high);
int lomuto(int arr[], size_t size, int low, int high);
void swap(int *var1, int *var2);
void swap_list(listint_t **list, listint_t *a, listint_t *b);
void cocktail_sort_list(listint_t **list);
void merge_sort(int *array, size_t size);
void mergetopdown(int *array, size_t left, size_t right, int *clone);
void merge(int *array, size_t left, size_t right, int *clone);
int get_digit(int number, int position);
int get_ldigits(int *array, size_t size);
void radix_sort(int *array, size_t size);
void swap_plus_print(int *array, size_t size, int *var1, int *var2);
void heap_struct(int *array, size_t size);
void heap_sort(int *array, size_t size);
void sift_down(int *array, size_t left, size_t right, size_t size);
void quick_sort_hoare(int *array, size_t size);
void recursive_quick(int *array, size_t size, int left, int right);
int hoare_part(int *array, size_t size, int left, int right);
void dynamic_print(int *array, int left, int lenght,
		int size, int pattern, int process);
void bit_merge(int *array, size_t left,
		size_t lenght, int pattern, size_t size);
void divide_sort(int *array, size_t left,
		size_t lenght, int pattern, size_t size);
void bitonic_sort(int *array, size_t size);

#endif
