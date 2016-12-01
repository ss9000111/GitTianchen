
#include <iostream>
#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;
int main(int argc, char **argv){
	int fd;		// for the file descriptor of the special file we need to open.
	unsigned long *BasePtr;		// base pointer, for the beginning of the memory page (mmap)
	unsigned long *PBDR, *PBDDR;	// pointers for port B DR/DDR

    fd = open("/dev/mem", O_RDWR|O_SYNC);	// open the special file /dem/mem
	if(fd == -1){
		printf("\n error\n");
	    return(-1);  // failed open
	}
	// We need to map Address 0x80840000 (beginning of the page)
	BasePtr = (unsigned long*)mmap(NULL,4096,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0x80840000);
    if(BasePtr == MAP_FAILED){
    	printf("\n Unable to map memory space \n");
    	return(-2);
    }  // failed mmap

	// To access other registers in the page, we need to offset the base pointer to reach the
	// corresponding addresses. Those can be found in the board's manual.
	PBDR = BasePtr + 1;		// Address of port B DR is 0x80840004
    PBDDR = BasePtr + 5;	// Address of port B DDR is 0x80840014
    ////////put on main

    *PBDDR |= 0x80;//-------GREEN---------------
	*PBDDR &= 0xFFFFFFFE;

   	 *PBDR |= 0x80;
	sleep(1);
   	 *PBDR &= ~0x80;
  	  sleep(1);
  	  *PBDR |= 0x80;
	sleep(2);
   	 *PBDR &= ~0x80;

	 *PBDDR |= 0x40;//---------------YELLOW------------
	*PBDDR &= 0xFFFFFFFD;

    *PBDR |= 0x40;
	sleep(1);
    *PBDR &= ~0x40;
    sleep(1);
    *PBDR |= 0x40;
	sleep(2);
    *PBDR &= ~0x40;

    *PBDDR |= 0x20;//------------RED-------------
   	*PBDDR &= 0xFFFFFFFC;

       *PBDR |= 0x20;
   	sleep(1);
       *PBDR &= ~0x20;
       sleep(1);
       *PBDR |= 0x20;
   	sleep(2);
       *PBDR &= ~0x20;

	*PBDDR |= 0x20;//------------RED-------------
   	*PBDDR &= 0xFFFFFFFC;

       *PBDR |= 0x20;
   	sleep(1);
       *PBDR &= ~0x20;
       sleep(1);
       *PBDR |= 0x20;
   	sleep(2);
       *PBDR &= ~0x20;


    using namespace std;
    cout<<"entering morscode convertor, please enter a charactor a b or c"<<endl;
    char cha;
    cin>>cha;
    cout<<"a is .-,b is -..., c is -.-. RED is dot YELLOW is - and GREEN is end"<<endl;
    switch(cha)
    {
    case 'a':
    {
    	 *PBDDR |= 0x20;//------------RED-------------
    	   	*PBDDR &= 0xFFFFFFFC;

    	       *PBDR |= 0x20;
    	   	sleep(1);
    	       *PBDR &= ~0x20;
    	       sleep(1);
    	       *PBDDR |= 0x40;//---------------YELLOW------------
    	      	*PBDDR &= 0xFFFFFFFD;

    	          *PBDR |= 0x40;
    	      	sleep(1);
    	          *PBDR &= ~0x40;
    	          sleep(1);
    	          *PBDDR |= 0x80;//-------GREEN---------------
    	          	*PBDDR &= 0xFFFFFFFE;

    	             	 *PBDR |= 0x80;
    	          	sleep(1);
    	             	 *PBDR &= ~0x80;
    	            	  sleep(1);
    	break;
    }
    case 'b':
    {*PBDDR |= 0x40;//---------------YELLOW------------
  	*PBDDR &= 0xFFFFFFFD;

      *PBDR |= 0x40;
  	sleep(1);
      *PBDR &= ~0x40;
      sleep(1);
      *PBDDR |= 0x20;//------------RED-------------
          	   	*PBDDR &= 0xFFFFFFFC;

          	       *PBDR |= 0x20;
          	   	sleep(1);
          	       *PBDR &= ~0x20;
          	       sleep(1);
          	     *PBDDR |= 0x20;//------------RED-------------
          	         	   	*PBDDR &= 0xFFFFFFFC;

          	         	       *PBDR |= 0x20;
          	         	   	sleep(1);
          	         	       *PBDR &= ~0x20;
          	         	       sleep(1);
          	         	    *PBDDR |= 0x20;//------------RED-------------
          	         	        	   	*PBDDR &= 0xFFFFFFFC;

          	         	        	       *PBDR |= 0x20;
          	         	        	   	sleep(1);
          	         	        	       *PBDR &= ~0x20;
          	         	        	       sleep(1);
          	         	  	          *PBDDR |= 0x80;//-------GREEN---------------
          	         	      	          	*PBDDR &= 0xFFFFFFFE;

          	         	      	             	 *PBDR |= 0x80;
          	         	      	          	sleep(1);
          	         	      	             	 *PBDR &= ~0x80;
          	         	      	            	  sleep(1);
    	break;
    }
    case 'c':
    {
    	 {*PBDDR |= 0x40;//---------------YELLOW------------
    	  	*PBDDR &= 0xFFFFFFFD;

    	      *PBDR |= 0x40;
    	  	sleep(1);
    	      *PBDR &= ~0x40;
    	      sleep(1);
    	      *PBDDR |= 0x20;//------------RED-------------
    	          	   	*PBDDR &= 0xFFFFFFFC;

    	          	       *PBDR |= 0x20;
    	          	   	sleep(1);
    	          	       *PBDR &= ~0x20;
    	          	       sleep(1);
    	          	     *PBDDR |= 0x40;//---------------YELLOW------------
    	          	         	  	*PBDDR &= 0xFFFFFFFD;

    	          	         	      *PBDR |= 0x40;
    	          	         	  	sleep(1);
    	          	         	      *PBDR &= ~0x40;
    	          	         	      sleep(1);
    	          	                *PBDDR |= 0x80;//-------GREEN---------------
    	          	                  	         	      	          	*PBDDR &= 0xFFFFFFFE;

    	          	                  	         	      	             	 *PBDR |= 0x80;
    	          	                  	         	      	          	sleep(1);
    	          	                  	         	      	             	 *PBDR &= ~0x80;
    	          	                  	         	      	            	  sleep(1);
    break;
    }
    default:
    break;
    }
close(fd);
    return 0;
}
}




