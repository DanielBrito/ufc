#include<stdio.h>
#include<math.h>

void calc_esfera(float r, float *area, float *volume){
	
    *area = 4*(pow(r,2));
    *volume = 4*(pow(r,3))/3.0;
}

int main(){
	
    float raio=3, area=0, volume=0;

    calc_esfera(raio, &area, &volume);

    printf("Area: %.2f\n", area);
    printf("Volume: %.2f", volume);

    printf("\n\n");

    return 0;
}
