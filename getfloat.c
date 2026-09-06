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
	while (isspace(c= getch())); //skip whie spaces
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c!= '.') { //+A will pass, go for a refactor
		
		ungetch(c); //not a number
		return 0;
	}
	
	sign = (c=='-') ? -1 : 1;
	
	if(c =='-' || c == '+'){ c = getch(); }
	
	for(*p=0;isdigit(c); c= getch()){
		
		*p = 10 * *p + (c - '0');  // 0 = 48 in ASCII we use this trick to get the real number from a char
		
	}
	
	if(c=='.'){  c = getch();	} //in case of 12.34 we have to consume the dot .

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