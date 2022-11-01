//PLaying Around with floating points in for loops
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){

    float i;
    float increment = 0.001;   
    float n = 1.000000001; 
    int count = 0;

    for (i=0.0; i<n; i+=increment) {
        ++count;
        printf("Loop Count: %d\n", count);
    }

    return 0;
}
