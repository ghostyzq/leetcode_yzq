#include <stdio.h>

void swap(int arr[], int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void heapify(int tree[], int n, int i){
	int c1 = 2*i + 1;
	int c2 = 2*i + 2;
	int max = i;
	if (c1 < n && tree[c1] > tree[max]){
		max = c1;
}
	if (c2 < n && tree[c1] > tree[max]){
                max = c2;
}
	if (max != i ){
	swap(tree,max,i);
	heapify(tree,n,max);	
}
}



int main() {
	int tree[] = {4,10,3,5,1,2};
	int n = 6;
	heapify(tree,n,0);
	int i;
	for (i = 0; i<n;i++){
		printf("%d\n",tree[i]);
	}
	return 0;
}

