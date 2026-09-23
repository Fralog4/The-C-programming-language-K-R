#include <stdio.h>

/*Write the function strend(s,t), which returns 1 if the string t occurs at the end of the string s and zero otherwhise */


int strend(char *s,char *t){
	
	char *start_s = s; //bookmark save the original address before any operation
	char *start_t = t;
	
	
	while(*s){s++;}
	while(*t){t++;} //now both are placed to the '\0' end
	
	//t - start_t == lenght of t because it's final address minus the original address es: 1004-1000 = 4 is the lenght
	if( (t-start_t) > (s-start_s) ){ return 0; }
	
	for(;t>=start_t;t--,s--){
		if(*s!=*t){ //if there is a case in which the letters are not the same we do not have the same word so 
			return 0; //exit
		}
	}
	
	return 1; //otherwhise perfect match
}

int main(){
	
	char s[] = "programming";
	char t1[] = "ming";
    char t2[] = "cat";
    char t3[] = "superprogramming"; // t lenght > s lenght
	
	
	printf("Test 1('%s' at the end of '%s'): %d\n",t1,s,strend(s,t1)); //1
	printf("Test 2('%s' at the end of '%s'): %d\n",t2,s,strend(s,t2)); //0
	printf("Test 3('%s' at the end of '%s'): %d\n",t3,s,strend(s,t3)); //0
	
}