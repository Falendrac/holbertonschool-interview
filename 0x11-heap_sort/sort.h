#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void make_heap(int *array, size_t size);
void sift_down(int *prmArray, size_t prmRoot, size_t prmEnd, size_t prmSize);
void swap(int *prmArray, size_t prmSize, size_t prmIndex1, size_t prmIndex2);
size_t get_parent_index(size_t child_index);

#endif
