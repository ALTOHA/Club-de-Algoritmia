#include <cstdio>
#include <cstdlib>

using namespace std;

int MaxTree[100000];
int mintree[100000];

int max(int n1, int n2){
    if(n1 > n2)
        return n1;
    else
        return n2;

}

 int BuildSegmentTreeMax(int arr[], int n_left, int n_right, int nodo){
    if(n_left == n_right){
        MaxTree[nodo] = arr[n_left];
        return arr[n_left];
    }
    int mid =(n_left + n_right)/2;
   return MaxTree[nodo] = max(BuildSegmentTreeMax(arr,n_left,mid,nodo*2+1),BuildSegmentTreeMax(arr,mid+1,n_right,nodo*2+2));

}


int maxQuerry(int arr[], int inf, int sup, int lim_inf, int lim_sup, int nodo){

    if(inf >= lim_inf && sup <= lim_sup){
        return MaxTree[nodo];
    }
    else if(sup < lim_inf || inf > lim_sup)
        return INT_MIN;
    else{
        return max(maxQuerry(arr, inf, sup,lim_inf,((lim_sup+lim_inf)/2),(nodo*2)+1),maxQuerry(arr, inf, sup, ((lim_sup+lim_inf)/2)+1, lim_sup ,(nodo*2)+2));
    }

}

int min(int num_1, int num_2){
    if(num_1 < num_2)
        return num_1;
    return num_2;
}

int BuildSegmentTreeMin(int arr[], int p_min, int p_max, int nodo){

    if(p_min == p_max){
        mintree[nodo] = arr[p_min];
        return mintree[nodo];
    }

    return mintree[nodo] = min(BuildSegmentTreeMin(arr, p_min, (p_min+p_max)/2, (nodo*2)+1), BuildSegmentTreeMin(arr, ((p_min+p_max)/2)+1, p_max, (nodo*2)+2));

}
int minQuery(int arr[],int inf,int sup,int lim_inf,int lim_sup,int nodo){
    
    if(inf <= lim_inf && sup >= lim_sup){
            return mintree[nodo];
    }
    else if(sup < lim_inf || inf > lim_sup){
            return INT_MAX;
    }
    else{   
            return min(minQuery(arr,inf,sup,lim_inf,(lim_inf+lim_sup)/2,(nodo*2)+1),minQuery(arr,inf,sup,((lim_inf+lim_sup)/2)+1,lim_sup,(nodo*2)+2));
    }
}
    
