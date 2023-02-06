#pragma once
#define HASHDEL (void*) -1

void insert_elem(int n);
void insert_elem1(int n);
void PrintHeap1();
void PrintHeap();
void HeapOut();
void Heapify(int i);
void HeapifyUp(int i);
int DeleteMax();
int level();
int DeleteMin();
int DeleteI(int i);
void MergeHeaps();
#undef HASHDEL
