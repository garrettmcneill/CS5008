#include <stdio.h>
#include <stdlib.h>

#define VAL 5

// recursion example

int sum(int k) {
	
	if (k <= 1) {
		// base case - with error protection for <=0
		return(1);
	}
	else {
		// recursive case
		return(k + sum(k-1));
	}
}

int main() {
	
	printf("\nsum of %d = %d\n\n", VAL, sum(VAL));

	return(0);
}
