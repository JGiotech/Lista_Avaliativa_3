#include <stdio.h>
#include <math.h>

int main() {


    int meses;
    double aporte, taxa, montante = 0;

    
    scanf("%d %lf %lf", &meses, &aporte, &taxa);

   
    for (int mes = 1; mes <= meses; mes++) {
        montante = (montante + aporte) * (1 + taxa);
        printf("Montante ao fim do mes %d: R$ %.2f\n", mes, montante);
    }

    return 0;
}
