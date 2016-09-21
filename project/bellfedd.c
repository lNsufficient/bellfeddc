#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static unsigned long long	fm_count;
static volatile bool		proceed = false;

static void done(int unused)
{
	proceed = false;
	unused = unused;
}

static int fm_elim(rows, cols, a, c){
    //kan förekomma att matrisen är större än den ska vara, därför är 
    //rows och cols mycket viktigt för att hålla koll på vilka element
    //som egentligen finns i matrisen. 
    if (cols == 0){
        return 0;
    }
    int i;
    if (cols == 1){
        double smallestUpperBound = DBL_MAX;
        double largestLowerBound = DBL_MIN;
        double cdiva;
        for(i=0;i<rows;i +=1){
            if(a[i][0] == 0){
                if(b[i] <0) {
                    return 0;
                }
            } 
            else {
                cdiva = c[i]/(double)a[i][0];
                printf("b(i)/A(i,1) = %f \n", cdiva)
                if(a[i][0] < 0){
                    if(cdiva > largestLowerBound){
                        largestLowerBound = cdiva;
                    }
                }
                else if(a[i][0]>0){
                    if(cdiva < smallestUpperBound){
                        smallestUpperBound = cdiva;
                    }
                }
            }
        }
        if(largestLowerBound <= smallestUpperBound) {
            return 1;
        }
    } else {
        int* newC;
        int** newA;
        int newRows=rows, newCols=cols; //de skapas att vara lika stora som innan.
        newA = calloc(newRows, sizeof(int*));
        for(i=0; i<newRows;i+=1){
            newA[i] = calloc(newCols, sizeof(int));
        }
        newC = calloc(newRows, sizeof(int));
        
        //Fixa for-loopen, se till att hålla koll på hur newRows och newCols ändras.

        for(i = 0; i<rows; i+=1){
            
        }
        if(newRows == 0 && newCols == 0){
            return 1;
        }
        return fm_elim(newRows, newCols, newA, newC);
    }
}
unsigned long long bellfedd(char* aname, char* cname, int seconds)
{
	FILE*		afile = fopen(aname, "r");
	FILE*		cfile = fopen(cname, "r");

	fm_count = 0;

	if (afile == NULL) {
		fprintf(stderr, "could not open file A\n");
		exit(1);
	}

	if (cfile == NULL) {
		fprintf(stderr, "could not open file c\n");
		exit(1);
	}

    /* read A and c files.[A - matris, c - less than] */
    int Arows, Acols, crows;
    fscanf(afile, "%d %d", &Arows, &Acols);
    fscanf(cfile, "%d", &crows); /*should be the same as Arows*/
    printf("Rows = %d, Cols = %d\n", Arows, Acols);
    int** Amatrix;
    int* cmatrix;
    Amatrix = calloc(Arows, sizeof(int*));
    cmatrix = calloc(crows, sizeof(int));
    int i;
    for(i = 0; i<Arows; i+=1)
        Amatrix[i] = calloc(Acols, sizeof(int));

    int j, val;
    for(i = 0; i<Arows;i = i+1){
        for(j = 0; j<Acols; j = j+1) {
            fscanf(afile, "%d", &val);
            Amatrix[i][j] = val;
            printf("Matrix value %d, %d, = %d,\n", i, j, Amatrix[i][j]);
        }
    }

    for(i = 0; i<crows;i += 1){
        fscanf(cfile, "%d", &val);
        cmatrix[i] = val;
        printf("C matrix value %d = %d \n", i, cmatrix[i]);
    }
    
    
	fclose(afile);
	fclose(cfile);

	if (seconds == 0) {
       printf("inne i if seconds == 0 \n"); 
		/* Just run once for validation. */
			
		// Uncomment when your function and variables exist...
		return fm_elim(Arows, Acols, Amatrix, cmatrix);
		//return 1; // return one, i.e. has a solution for now...
	}

	/* Tell operating system to call function DONE when an ALARM comes. */
	signal(SIGALRM, done);
	alarm(seconds);

	/* Now loop until the alarm comes... */
	proceed = true;
	while (proceed) {
		// Uncomment when your function and variables exist...
		// fm_elim(rows, cols, a, c);

		fm_count++;
	}

	return fm_count;
}
