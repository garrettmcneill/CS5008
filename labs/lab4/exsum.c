#include "exsum.h"

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


