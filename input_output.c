#include <stdio.h>

/*Write a program to copy its input to is output, replacing each tab by \t, eache backspace by \b nad each backslash by \\*/

/*Check if getchar() is one of the case are we looking for and substitute it 
* in C the use of \ means ignore the previous so in order to get a '\' printed you have to multiply it by 2, two backslash = four \
*/
int check_letter_and_stamp(int c){
	switch (c){
		
		case '\t':
		printf("\\t");
		break;
		
		case '\b':
		printf("\\b");
		break;
		
		case '\\':
		printf("\\\\");
		break;
		
		default: printf("%c",c);
	}
	return c;
}


int main(){
	int c;	
	while((c=getchar()) !=EOF){ //EOF= end of the file, it's -1 value.
		check_letter_and_stamp(c);
		c = getchar(); //reassing c for the next letter after did ours check on the former one
	}
}