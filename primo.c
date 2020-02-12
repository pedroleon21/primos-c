#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int eprimo(long long int p);
void fileprint(long long int);

int main(){
	FILE *arq = NULL;
	long long int num;
	arq = fopen("primarylist.txt","w");
	if(arq==NULL) {return 0;}
	else {printf("calculando");}
	fclose(arq);
	for(num=2;num;num++){
		if(eprimo(num)){fileprint(num);}
	}printf("\nend\n");
	return 0;
}

void fileprint(long long int num){
	FILE *arq;
	arq = fopen("primarylist.txt","a");
         fprintf(arq,"%lli \n",num);
        fclose(arq);
}
int eprimo(long long int p){
	long long int i;
	
	for(i=2;i<p;i++){
		if( !(p % i)) return 0;
	}
	return 1;
}
