#include <cstdio>

using namespace std;

int main(){
	int set[100]={-8, 1, 7, 17, 21, 54}, casos, num, i, j, cont=0, valor, l=0, arr[100], jei=6, q;
	scanf ("%d", &casos);
		for (i=0; i<casos; i++){
			scanf ("%d", &num);
				for (j=0; j<jei; j++){
					if (cont==0){
						if (num < set[j]){
							for (q=j; q<jei; q++){
								arr[l]=set[j+l];
								l++;
							}
							set[j]=num;
							valor=j+1;
							cont++;
						}
						else if (num > set[jei-1]){
						arr[0]=num;
						l=1;
						valor=jei; 
						}
					}
					else if (cont==0 && j<jei){
						for (q=0; q<jei; q++){
							arr[q]=set[q];
						}
						set[0]=num;
						valor=0;
					}
				}
			for (j=0; j<valor; j++){
				printf ("%d ", set[j]);
			}
			for (j=0; j<l; j++){
				set[j+valor]=arr[j];
				printf ("%d ", arr[j]);
			}
				printf ("\n");
				jei++;
				cont=l=0;
		}
	return 0;
}
