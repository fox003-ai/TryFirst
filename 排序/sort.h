#ifndef _SORT_H
#define _SORT_H

#define ElemType int
void swap (ElemType& a,ElemType& b);
void BubbleSort (ElemType* a,int n);
void SelectSort (ElemType* a,int n);
void InsertSort (ElemType* a,int n);
void quicksort (ElemType* a,int left,int right);
void QuickSort (ElemType* a,int n);
void mergesort (ElemType* a,ElemType* tmp,int L,int R,int RightEnd);
void Merge (ElemType* a,ElemType* tmp,int L,int RightEnd);
void MergeSort (ElemType* a,int n);
void RadixSort (ElemType* a,int n);
#endif 
