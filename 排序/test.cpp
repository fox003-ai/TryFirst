#include <iostream>
#include "sort.h"


using namespace std;


int main () {
	int i;
	ElemType array[10] = {35,10,42,3,79,12,62,18,51,23};
	RadixSort(array,10);
	for (i=0;i<10;i++) {
		cout<<array[i]<<" ";
	}
}

void swap (ElemType& a,ElemType& b) {
	ElemType tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void BubbleSort (ElemType* a,int n) {
	int i,j;
	int flag;
	ElemType m;
	for (i=n-1;i>0;i--) {
		flag = 0;
		for (j=0;j<i;j++) {
			if (a[j]>a[j+1]) {
				swap (a[j],a[j+1]);
				flag = 1;
			}
		}
		if (flag==0) break;
	}
}

void SelectSort (ElemType* a,int n) {
	int i,j;
	ElemType tmp;
	for (i=0;i<n;i++) {
		for (j=i+1;j<n;j++) {
			if (a[i]>a[j]) {
				swap (a[i],a[j]);
			}
		}
	}
}

void InsertSort (ElemType* a,int n) {
	int i,j;
	for (i=0;i<n-1;i++) {
		for (j=i+1;j>0;j--) {
			if (a[j]<a[j-1]) {
				swap (a[j],a[j-1]);
			}
		}
	}
}

void quicksort (ElemType* a,int left,int right) {
	int i,j; 
	ElemType pivot;
	pivot = a[left];
	i = left + 1;
	j = right;
	while (1) {
	while (a[i]<pivot) i++;
	while (a[j]>pivot) j--;
	if (i<j) {
	swap (a[i],a[j]);
	}
	else {
		break;
	}	
	}
	swap (a[i-1],a[left]);
	if (left<i-1) quicksort (a,left,i-1);
	if (j+1<right) quicksort (a,j+1,right);
}

void QuickSort (ElemType* a,int n) {
	quicksort (a,0,n-1);
}

void mergesort (ElemType* a,ElemType* tmp,int L,int R,int RightEnd) {
	int i;
	int t = L;
	int LeftEnd = R - 1;
	int total = RightEnd - L + 1;
	while (L <= LeftEnd && R <= RightEnd) {
		if (a[L] < a[R]) {
			tmp[t] = a[L];
			L++;
		} else {
			tmp[t] = a[R];
			R++;
		}
		t++;
	}
	while (L <= LeftEnd) {
		tmp[t] = a[L];
			L++;
			t++;
	}
	while (R <= RightEnd) {
		tmp[t] = a[R];
		R++;
		t++;
	}
	for (i = 0;i<total;i++,RightEnd--) {
		a[RightEnd] = tmp[RightEnd];
	}
}

void Merge (ElemType* a,ElemType* tmp,int L,int RightEnd) {
	int Centre;
	if (L < RightEnd) {
		Centre = (L + RightEnd) / 2;
		Merge (a,tmp,L,Centre);
		Merge (a,tmp,Centre + 1,RightEnd);
		mergesort (a,tmp,L,Centre + 1,RightEnd);
	}
}

void MergeSort (ElemType* a,int n) {
	ElemType* tmp;
	tmp = new ElemType [n];
	Merge (a,tmp,0,n - 1);
}

void RadixSort (ElemType* a,int n) {
	int i = 1;
	int j,k,m,r;

	for (i=1;i<1000;i*=10) {
	ElemType tmp[10][10] = {0};
		for (k=0;k<n;k++) {
			m = (a[k]/i) % 10;
			tmp[m][k] = a[k]; 
	} 
	r = 0;
	for (j=0;j<10;j++) {
		for (k=0;k<n;k++) {
			if (tmp[j][k] != 0) {
				a[r] = tmp[j][k];
				r++;
			   }
		    }
	    }
    } 
}

