#include <stdio.h> 
#include <math.h>

void kiir (double tomb[], int db) 
{ 
    int k;
        for (k = 0; k < db; ++k) 
            printf ("%f\n", tomb[k]);
}

double tavolsag (double PageR[], double PageRmatrix[], int n) 
{ 
    double osszeg = 0.0; 
    int i;

        for (i = 0; i < n; ++i) 
	{
            osszeg += (PageRmatrix[i] - PageR[i]) * (PageRmatrix[i] - PageR[i]);
	}
    return sqrt(osszeg);
}

    int main (void) 
    {
        double Honlap[4][4] = { {0.0, 0.0, 1.0 / 3.0, 0.0}, 
                           	{1.0, 1.0 / 2.0, 1.0 / 3.0, 1.0}, 
                           	{0.0, 1.0 / 2.0, 0.0, 0.0}, 
                         	{0.0, 0.0, 1.0 / 3.0, 0.0} };
                        
        double PageR[4] = { 0.0, 0.0, 0.0, 0.0 }; 

        double PageRmatrix[4] = { 1.0 / 4.0, 1.0 / 4.0,
			  1.0 / 4.0, 1.0 / 4.0 };
        
    int i, j;

    for (;;)
    {
        for (i = 0; i < 4; ++i)
        {
            PageR[i] = 0.0;
	    for (j = 0; j < 4; ++j) 
		{
			PageR[i] += (Honlap[i][j] * PageRmatrix[j]);
		}        
	}

        if ( tavolsag (PageR, PageRmatrix, 4) < 0.00000001 ) 
	break;

        for ( i = 0; i < 4; ++i ) 
	{
		PageRmatrix[i] = PageR[i];
	}
    }

    kiir (PageR, 4);

return 0;
}
