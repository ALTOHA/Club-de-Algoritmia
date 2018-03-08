#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 10;
int tree[maxn];
int sz = 0;

int getParent(int index){
	return (index-1)/2;	
}

int getLeftChild(int index){
	return (index*2)+1;
}

int getRightChild(int index){
	return (index*2)+2;
}

bool hasParent(int index){
	return getParent(index) >= 0;
}

bool hasLeftChild(int index){
	return getLeftChild(index) < sz;
}
bool size(int sz){
	if(sz == 0)
		return 1;
	else return 0;
}

bool hasRightChild(int index){
	return getRightChild(index) < sz;
}

int min(int val1, int val2){
	return (val1 < val2) ? val1 : val2; 
}

void getMin(){
	if(sz == 0){
		printf("Esta vacio\n"); 
	}
	else
		printf("%d\n", tree[0]);
}

void Swapping(int parent, int child){
	int temp;
	temp = tree[parent];
	tree[parent] = tree[child];
	tree[child] = temp;
}

void insertar(int value){
	int index = sz;
	tree[sz] = value;
	while(hasParent(index)){
		if(tree[getParent(index)] > tree[index]){
			Swapping(getParent(index), index);
			index = getParent(index);
		}
		else
			break;
	}	
	sz++;
}

int pop(){
	int temp = tree[0], index = 0, min;
	tree[0] = tree[--sz];

	while(hasLeftChild(index)){
		min = getLeftChild(index);

		if(hasRightChild(index) && tree[getRightChild(index)] < tree[min])
			min = getRightChild(index);

		if(tree[min] < tree[index])
			Swapping(index, min);

		else 
			break;
			
		index = min;
	}
	return temp;
}

int main(){
	int valor, i;
	
	for(i=0; i<10; i++){
		scanf("%d", &valor);
		
		insertar(valor);
	}
	
	for(i = 0; i<10; i++){
		if(size(10) == 0)
			printf("%d\n", pop());
	}
	
	return 0;
}
