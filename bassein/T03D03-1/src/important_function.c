#include <stdio.h>
#include <math.h>

int main(){
    char tmp;
    int da;
    float x,y;
    da = scanf("%f%c",&x, &tmp);
    if (da == 2 && tmp == '\n'){
        y = 0.007*pow(x,4)+((22.8*pow(x,1/3)-1000)*x + 3) / (x*x/2)-x*pow(10+x, 2/x)-1.01;
        printf("%.1f",y);
    }
    else {
        printf("n/a");
    }

    return 0;
}