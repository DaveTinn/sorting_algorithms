#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stddef.h>
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
/**
 * enum kind_e - Describes the suits of a deck of cards
 * @SPADE: Represents the suit Spade
 * @HEART: Represents the suit Heart
 * @CLUB: Represents the suit Club
 * @DIAMOND: Represents the suit Diamond
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap_array(int *array, size_t size, int *a, int *b);
size_t Lomuto_partitioner(int *array, size_t size, int start_idx, int end_idx);
void quicksorter(int *array, size_t size, ssize_t start_idx, ssize_t end_idx);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void sort_deck(deck_node_t **deck);
size_t Knuth_sequence(size_t size);
void swap_node(listint_t **list, listint_t *node1, listint_t *node2);
void merge(int *array, size_t start_idx, size_t end_idx, int *sub_arr);
void merge_top_down(int *array, size_t start_idx,
		size_t end_idx, int *sub_arr);
#endif
