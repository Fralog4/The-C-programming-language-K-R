#include <stdio.h>

/*Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C comments doesn't nest.*/

//constants dictionary of possible encounters inside a block of code, imagine this as boolean check
#define NORMAL_STATE 0
#define STATE_IN_LINE_COMMENT 1
#define STATE_MULTI_LINE_COMMENT 2
#define STATE_MULTI_LINE_STAR 3
#define STATE_IN_STRING 4
#define STATE_IN_CHAR 5

//Prototypes of State Handlers
int handle_normal_state(int c);
int handle_potential_comment(void); //c is not required we already know c=='/'
int handle_line_comment(int c);
int handle_multi_line_comment(int c);
int handle_multi_line_star(int c);
int handle_in_string(int c);
int handle_in_char(int c);

/*Refactor 23.06.2026 State Handler pattern check the commit before this for reference*/

int main(){
	
	int c;
	int state= NORMAL_STATE;
	
	while((c=getchar())!= EOF){
		
		switch(state){
			
			case NORMAL_STATE:
			state = handle_normal_state(c);
			break;
			
			case STATE_IN_LINE_COMMENT:
			state = handle_line_comment(c);
			break;
			
			case STATE_MULTI_LINE_COMMENT:
			state = handle_multi_line_comment(c);
			break;
			
			case STATE_MULTI_LINE_STAR:
			state = handle_multi_line_star(c);
			break;
			
			case STATE_IN_STRING:
			state= handle_in_string(c);
			break;
			
			case STATE_IN_CHAR:
			state= handle_in_char(c);
			break;
		}

	}	
}


int handle_line_comment(int c){
	
	if(c=='\n'){
		printf("%c",c);
		return NORMAL_STATE;
	}
	
	return STATE_IN_LINE_COMMENT; //if we didn't encountered '\n' that means we are still inside an in line comment 
}


int handle_in_string(int c){
	
	printf("%c",c);
	
	if(c=='\\'){ 
		int next_to_c = getchar();
		printf("%c",next_to_c);
		
	}else if(c=='"'){return NORMAL_STATE;}
	
	return STATE_IN_STRING; //string is not finished yet
}

int handle_in_char(int c){
	printf("%c",c);
	
	if(c=='\\'){
		
		int next_to_c= getchar();
		printf("%c",next_to_c);
		
	}else if(c=='\''){return NORMAL_STATE;}
	
	return STATE_IN_CHAR;
}


int handle_multi_line_comment(int c){
	
	if(c=='*'){	return STATE_MULTI_LINE_STAR;}
	
	return STATE_MULTI_LINE_COMMENT;
}


int handle_multi_line_star(int c){
	
	switch(c){
		
		case '/':
			return NORMAL_STATE;

		case '*':
			return STATE_MULTI_LINE_STAR;
		
		default:
			return STATE_MULTI_LINE_COMMENT;
	}

}

int handle_normal_state(int c){
	
	switch (c){
		case '"': 
			return STATE_IN_STRING;
			
		case '\'':
			return STATE_IN_CHAR;
			
		case '/':
		return handle_potential_comment();
		
		default:
		printf("%c",c);
		return NORMAL_STATE;
	}
	
}

int handle_potential_comment(){
	
	int next_to_c= getchar();
	
	switch(next_to_c){
		
		case '/':
			return STATE_IN_LINE_COMMENT;
			
		case '*':
			return STATE_MULTI_LINE_COMMENT;
			
		default:
		printf("/"); //at this point we are already sure that c is equal to / so just print it
		//for such cases like: result = a / "divisor"; 
		ungetc(next_to_c,stdin);
		return NORMAL_STATE;
	}
}