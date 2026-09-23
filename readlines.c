#include <stdio.h>
#include <string.h>

/*Rewrite readlines to store lines in an array supplied by main, rather than calling alloc to mantain storage. How much faster is the program? */

#define MAXLEN 1000
#define MAX_LEN_PTR 5000
#define MAX_LINES 1000
#define STORAGE 10000
#define MAX_STORAGE 10000


int getline(char *, int);

int readlines(char *lineptr[], char *storage, int maxlines, int max_storage){
	
	int len, nlines;
	char *p, line[MAXLEN];
	
	nlines = 0;
	p = storage;
	
	while ((len= getline(line,MAXLEN))>0){ //getline always returns the len 
		
		/*no space left = p-storage is the space I already occupied , + len is the len of the new word. We have to ensure that the space  do not surpass the max_storage*/
		if( nlines>= maxlines || p-storage + len > max_storage){ return -1; } 
	
		line[len-1] = '\0';
		strcpy(p,line);
		lineptr[nlines++] = p;
		p += len;
		
	}
	return nlines;
}

int main(){
	
	char *lineptr[MAX_LEN_PTR];
	char storage[STORAGE];
	int max_lines = MAX_LINES;
	int max_storage = MAX_STORAGE;
	
	int result = readlines(lineptr, storage, max_lines,max_storage);
	printf("The lines are: %d\n",result);
}

/* K&R getline */
int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}