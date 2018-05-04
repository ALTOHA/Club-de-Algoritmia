#include <bits/stdc++.h>

using namespace std;

void findAll(int arr[], int limit, int index, vector<int> subset ){
	
	if(index == limit){
		for(int i=0; i<subset.size();i++){
			cout << subset[i] << " ";
		}
		cout<<endl;
		return;
	}
	else{
		findAll(arr, limit, index+1, subset);
		subset.push_back(arr[index]);
		findAll(arr, limit, index+1, subset);		
	}
}

int main(){
	int arr[6] = {1,2,3,4, 5, 6};
	vector <int> subset;	
	
	
	findAll(arr, 6, 0, subset);
	
	return 0;
}
