//Egy magot nullan!

#include <stdio.h>
int
main ()
{
  while(true){
	sleep(100);
    
  return 0;
}




//Egy magot szazon!

#include <stdio.h>

int main(){
  while(true){
	}
	return 0;
}




//Minden magot szazon!

#include <stdio.h>
#include <omp.h>

int main(void)
{
	#pragma omp parallel
	{
		for(;;)
		{

		}
	}
	return 0;
}
