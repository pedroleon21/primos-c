#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int eprimo(long long int p);
void fileprint(long long int);

int main(){
	FILE *arq = NULL;
	long long int num,lmt;
	char str[128];
	arq = fopen("primarylist.txt","w");
	str[0] = '\0';
	if(arq==NULL) {return 0;}
	else {printf("range: ");scanf("%lli",&lmt);}
	printf("\ncalculando...\n");
	fclose(arq);
	for(num=2;num<lmt;num++){
		if(eprimo(num)){fileprint(num);}
	}printf("\nend\n");
	arq = fopen("primarylist.txt","r");
	while(fgets(str,128,arq) != NULL){
		//c = getc(arq);
		printf("%s",str);
	}
	fclose(arq);
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
