#include <stdio.h>
/*Write a program to print a histogram of the frequencies of different characters in its input*/
#define LENGHT 256

void stamp_hist(int characters, int frequence){
	
	printf("%c: ",characters);
	
	for(int j=0;j<frequence;j++){
		
		printf("*");
	}
	printf("\n");
}

int main(){

	int array_char[LENGHT] = {0};
	int c; //char are numbers so we can check if a char is present using an int 'A' = 65
	
	while((c=getchar()) !=EOF){ //you pick up a letter perhaps 'A' c= 65
		array_char[c]++; // go to the index 65 and increment the value corresponding to the index 65 es: [65:0] ->[65 (index char):1 (frequence)]
	}		
	
	for(int i=0;i<LENGHT;i++){

		if(array_char[i]>0){ //the char is present inside the text
			stamp_hist(i, array_char[i]);	
		}
		
	}
}