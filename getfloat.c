#include <stdio.h>
#include <ctype.h>

/*K&R code copy pasted*/
#define BUFSIZE 100

char buf[BUFSIZE];    /* buffer per ungetch */
int bufp = 0;         /* prossima posizione libera in buf */

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/*Write getfloat, the floating-point analog of getint. What type does getfloat return as its function value?*/

int getfloat(float *p){
	
	int c, sign;
	
	int is_sign;
	int is_valid_start;
	int check_letter;
	
	while (isspace(c= getch())); //skip white spaces
	
	is_sign = (c=='+'||c=='-');
	is_valid_start = (isdigit(c) || is_sign || c == '.');
	
	if (!is_valid_start&&c!=EOF) { 
		ungetch(c); //not a number
		return 0;
	}
	
	sign = (c=='-') ? -1 : 1;
	
	if(c =='-' || c == '+'){ 
	
		int char_sign = c;  
		c = getch();        

		if(!isdigit(c) && c != '.') {
			if (c != EOF) {	ungetch(c); }
			ungetch(char_sign);     
			return 0;
		}
	}
	
	for(*p=0;isdigit(c); c= getch()){
		*p = 10 * *p + (c - '0');  // 0 = 48 in ASCII we use this trick to get the real number from a char
	}
	
	if(c=='.'){ c = getch(); } //in case of 12.34 we have to consume the dot .

	float divisor = 1.0;
	for(;isdigit(c);c=getch()){ //we have to read the decimals now p = 12
		divisor *= 10;
		*p= 10 * *p + (c - '0');
	}
	
	*p= *p /divisor * sign;
	if(c!= EOF){ ungetch(c);}
	return c;
}

int main(){
	
	float pn;
	getfloat(&pn); //pass the memory address to the function
	
}