#include <stdio.h>
#include <math.h> /

float calcular_seno(float angulo);
float valor_h(float v, float angulo, float g);

int main() {
    int n; 
    printf("¿Cuántos conjuntos de datos desea ingresar? ");
    scanf("%d", &n);

    float v, angulo, g, altura;

    printf("\n%-15s %-15s %-15s %-15s\n", "Velocidad (m/s)", "Ángulo (rad)", "Gravedad (m/s^2)", "Altura (m)");
    printf("-------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("\nConjunto %d:\n", i + 1);

        printf("Velocidad de proyección (m/s): ");
        scanf("%f", &v);

        printf("Ángulo de proyección (radianes): ");
        scanf("%f", &angulo);

        printf("Aceleración gravitacional (m/s^2): ");
        scanf("%f", &g);

        altura = valor_h(v, angulo, g);

        printf("%-15.2f %-15.2f %-15.2f %-15.2f\n", v, angulo, g, altura);
    }

    return 0;
}

float calcular_seno(float angulo) {
    float seno = angulo; 
    float term = angulo; 
    int n = 1;

    for (int i = 1; i <= 10; i++) { 
        n += 2;
        term *= -1 * angulo * angulo / (n * (n - 1)); 
    }

    return seno;
}

float valor_h(float v, float angulo, float g) {
    float seno = calcular_seno(angulo);
    return (pow(v, 2) * pow(seno, 2)) / (2 * g);
}




