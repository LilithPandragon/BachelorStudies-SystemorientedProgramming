// --------------------------------------------------------------------------------
// Berechnen Sie die Anzahl der Elemente in einem Array
// und geben Sie jedes Element innerhalb einer Schleife einzeln aus.
// Berechnen Sie weiters auch den Minimal- und Maximalwert des Arrays.
//
// Verwenden Sie dafür folgendes float Array:
//
//    float weights[5]={1.34,4.567,56.55,33.44,782.00};
//
// Damit die Validierung korrekt erfolgen kann, bitte folgendes
// Output Format verwenden:
// Anzahl: 5
// 1.34
// 4.57
// ...
// Min: 1.34
// Max: 782.00
// ----------------------------------------------------------------
// Systemnahe Programmierung 6. Semester
//
// Susanne Peer SWD21

#include <stdio.h>

int main() {
    float weights[5] = {1.34, 4.567, 56.55, 33.44, 782.00};
    int size = sizeof(weights) / sizeof(weights[0]);

    printf("Anzahl: %d\n", size);

    printf("Elemente:\n");

    for (float *pointi = weights; pointi < weights + size; pointi++) {
        printf("%.2f\n", *pointi);
    }

    float mini = *weights;
    for (float *pointi = weights + 1; pointi < weights + size; pointi++) {
        if (*pointi < mini) {
            mini = *pointi;
        }
    }
    printf("Min: %.2f\n", mini);

    float maxi = *weights;
    for (float *pointi = weights + 1; pointi < weights + size; pointi++) {
        if (*pointi > maxi) {
            maxi = *pointi;
        }
    }
    printf("Max: %.2f\n", maxi);

    return 0;
}
