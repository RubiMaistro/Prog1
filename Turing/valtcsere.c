#include <stdlib.h>
#include <stdio.h>

int main(){

	int x = 2, y = 3;

	printf("%s\n%d %d\n, "kulonbseggel:",x,y);

	x -= y;
	y += x;
	x = y-x;
	
	printf("%d %d\n",x,y);

return 0;
}
