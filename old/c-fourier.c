//use fgetc to collect data from A. First, run to get rows, then cols, then make sure to create a
//matrix
int main(int argc, char* argv[]) 
 
	int m = 3;
	int n = 2;
	char solveable;
	int A[m][n] = {{1, 2},{3, 4},{5, 6}}
	int b[m] ={1,2,3};
	if (cols == 0) {
		solveable= 0;
		return solvable;
	}
	if (cols == 1) {
		int smallestUpperBound = INT_MAX;
		int largestLowerBound = INT_MIN;
		int i = 0; 
		while (i<m) {
			if(A[i][0] < 0)
				if(b[i]/A[i][0] > largestLowerBound)
					largestLowerBound = b[i]/A[i][0];
			else if (A[i][0] > 0) {
				if (b[i]/A[i][0] < smallestUpperBound)
					smallestUpperBound = b[i]/A[i][0];
			}
			else if (A[i][0] = 0) {
				if(b[i] < 0) {
					solveable = 0;
					return solveable;
				}
			}
			i = i+1;
		}
		if (largestLowerBound <= smallestUpperBound) {
			solveable = 1;
			return solveable;
		}
	} else {
		int k = 0;
		int c[n-1];
		int p = -1;
		int i = 0;
		for (i < m) {
			if(A[i][0] < 0) {
				int j = 0;
				while (j < m) {
					if 
				p = p + 1;
