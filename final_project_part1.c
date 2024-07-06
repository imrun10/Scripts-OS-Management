
// Read an data frm stadard input device (keyboard)
// Write it on the screen
// Data should be any length


#include <stdio.h> 
#include <stdlib.h> 

int main(){ 

    char data[2000];	//Initialising the string. However an infinte 
			//string is not possible so we use a large buffer
			//number instead

    printf("Enter anything:\n"); 
 
    scanf("%s", data);	//Takes input from user 
    printf("Output -> %s ", data);	//Prints said input
    return 0;
}
