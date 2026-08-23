#include <stdio.h>

/*Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C comments doesn't nest.*/

//constants dictionary of possible encounters inside a block of code, imagine this as boolean check
#define NORMAL_STATE 0
#define STATE_IN_LINE_COMMENT 1
#define STATE_MULTI_LINE_COMMENT 2
#define STATE_MULTI_LINE_STAR 3
#define STATE_IN_STRING 4
#define STATE_IN_CHAR 5



int main(){	
	
	int c;
	int state = NORMAL_STATE;
	
	while((c=getchar())!= EOF){

		switch(state){
			
			case NORMAL_STATE:
			
			if(c=='"'){
				state=STATE_IN_STRING;
			}else if(c=='\''){
				state= STATE_IN_CHAR;
			}
			
			if(c=='/'){
				int next_to_c=getchar();
				
				switch(next_to_c){
					case '/':
					state= STATE_IN_LINE_COMMENT;
					break;
					
					case '*':
					state= STATE_MULTI_LINE_COMMENT;
					break;
					
					default: //case in which you encounter a normal char 
					printf("%c",c);
					//for such cases like: result = a / "divisor"; 
					ungetc(next_to_c,stdin);
					break;
				}
				
			} else{
				printf("%c",c);
			}
			break;
			
			case STATE_IN_LINE_COMMENT:
			if(c=='\n'){
				state = NORMAL_STATE;
				printf("%c",c);
			}
			break;
			
			case STATE_MULTI_LINE_COMMENT:
			//devo capire quando finisce con */
			if(c=='*'){
				state= STATE_MULTI_LINE_STAR;
			}
			break;
			
			case STATE_MULTI_LINE_STAR:
			
			switch(c){
				
				case '/':
				state= NORMAL_STATE; //the comment is done == */
				break;
				
				case '*':
				state= STATE_MULTI_LINE_STAR;
				
				break;
				
				default:
				
				state= STATE_MULTI_LINE_COMMENT;
				
			}
			
			break;
			
			case STATE_IN_STRING:
			printf("%c",c);
			
			if(c=='\\'){
				int next_to_c=getchar();			
				printf("%c",next_to_c);
			} else if(c=='"'){
				state=NORMAL_STATE;
			}
			break;
			
			case STATE_IN_CHAR:
			printf("%c",c);
			
			if(c=='\\'){
				int next_to_c=getchar();			
				printf("%c",next_to_c);
			}else if(c=='\''){
				state=NORMAL_STATE;
			}
			break;
		}
		
	}
	
}