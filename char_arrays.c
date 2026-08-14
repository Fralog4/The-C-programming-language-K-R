#include <stdio.h>
/*Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input line at a time*/

#define LEN 100

void reverse(char s[], int ind){
	
	int i= 0;
	int j= ind-2; //last letter of the word
	char box = 0; //variable used for the exchange between i and j
	
	while(i<j){
		
		box = s[i]; //C
		s[i] = s[j]; //C -> O
		s[j] = box; //O -> C
		
		i++;
		j--;
		
	}
}

int main(){
	
	char sentence[LEN] = {0}; //array of defined lenght in which I will put my chars 
	int c;  //char
	
	int index;
	
	index=0;
	
	while( (c= getchar()) != EOF){	
		
		/*what if the input chars are > LEN? We have to avoid that situation, we must put a limit on when we are storing chars inside the array otherwise we will never now when the ENTER keyboard is pressed, the '\n' will be stored outside of our LEN cells -> Segmentation Fault or worse broken data and unexpected behaviour we will store those chars who knows where*/
		if(index<=98){ //98 places for chars, 2 for '\n' and '\0' on a LEN of 100
			sentence[index]=c; //put the index so whenever I put a char it progressively grows 0-A,1-B,ecc...
			index++;
		}
		
		if(c =='\n'){ //insert keyboard (if it won't be stored inside the array because of a input>LEN you will have all the sentence attached at every stamp that's why we put an if below to check if it's contained as the last char of the array)
			reverse(sentence,index);
		
			sentence[index] = '\0'; //In C an array is just an empty box with a prefixed lenght, you don't know which cells are used and which not, '\0' is Null Terminator you are saying here that the word stops here
			//for example [C,I,A,O]+'\n' index is 4 at '\n' we increment it at line 37 so it becames 5, we are "appending" after the '\n' the Null Terminator so the word becomes: [C,I,A,O,'\n','\0',trash that will not be printed...]

			printf("%s",sentence); //%s doesn't know when to stop it relies on the null terminator
			
			if(sentence[index-1]!='\n'){ //index is the very first empty cell so index-1 is the last char of the word
				printf("\n"); //I prefered to just print a new line instead of checking if the last char is exactly '\n' and if not to put it inside the array
			}
			
			index=0; //reset, the next line will overwrite the array from 0
		}
	}
}