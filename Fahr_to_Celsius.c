#include <stdio.h>

/*write a program to print the corresponding Celsius to Fahreneit table*/

/*C°=5/9*°F -32 -> celsius = (5.0/9.0)*(fahr-32);
	function that contains the logic of the conversion
*/
float convert_temp(float f){
	return (5.0/9.0)*(f-32); //single responsability function
}

int main(){
	
	float fahr, cel;
	int step = 20;
	int limit = 200; //limite max temp Fahreneit
	fahr=0.0;
	
	//print header
	printf("Fahrenheit | Celsius\n--------------------\n");
	
	while(fahr<=limit){
		cel = convert_temp(fahr);
		
		printf("%3.0f %6.1f\n",fahr,cel);

		fahr += step;
	}
	
	return 0;
}