#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

void cacthnumbers(char *str,long long int *start_range,long long int *max_range);
int eprimo(long long int p);
void fileprint(long long int);

int main(){
	FILE *arq = NULL;
	long long int num,lmt;
	char *str;
	str = (char*)malloc(sizeof(char)*70);
	str[69]='\0';
	arq = fopen("primarylist.txt","w");
	if(arq==NULL) {return 0;}
	fclose(arq);
	printf("numeros: ");
	fgets(str,70,stdin);
	cacthnumbers(str,&num,&lmt);
	printf("\ncalculando...\n");
	while(num<lmt){
		if(eprimo(num)){fileprint(num);}
		num++;
	}
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

void cacthnumbers(char * str,long long int * start_range, long long int *max_range){
	long long int aux,walker=0;
	*start_range = atoll(str);
	while(isdigit(str[walker]) && walker<70){
		walker++;
	}
	*max_range = atoll(&str[walker+1]);
	if((*max_range)<(*start_range)){
		aux=*max_range;
		*max_range=*start_range;
		*start_range=aux;
	}
	if((*start_range)<2) *start_range =2;
}
