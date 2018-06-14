#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Book{
		char name[30];
		char author[30];
		unsigned int pages;
		char isbn[20];
}Book;

int compar1(const void* val2,const void* val1){
		int a;
		if((a=strcmp(((Book*)val1)->name,((Book*)val2)->name))!=0){
				return a;
		}
		else if((a=strcmp(((Book*)val1)->author,((Book*)val2)->author))!=0){
				return a;
		}
		else{
				return ((Book*)val1)->pages-((Book*)val2)->pages;
		}
}

int main(){
		int N;
		scanf("%d",&N);
		Book *array=(Book*)malloc(N*sizeof(Book));
		int i;
		for(i=0;i<N;i++){
				scanf("%s",array[i].name);
				scanf("%s",array[i].author);
				scanf("%u",&array[i].pages);
				scanf("%s",array[i].isbn);
		}
		qsort(array,N,sizeof(Book),compar1);
		for(i=0;i<N;i++){
				printf("%s %s %d %s ",array[i].name,array[i].author,array[i].pages,array[i].isbn);
		}
		return 0;
}
