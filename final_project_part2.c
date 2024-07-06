// print day of the week
// fork to print date

#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
    time_t systemCurrentTime;
    time(&systemCurrentTime); //get the date and time 
    
    //Parent process 
    if(fork() == 0)
      printf("Day: %.3s\n", ctime(&systemCurrentTime));
    
    //Child process 
    else
    {
        printf("Date : %.*s ", 6, ctime(&systemCurrentTime) + 4);
        printf("%.*s\n", 4, ctime(&systemCurrentTime) + 20);
    }

return 0;
}
