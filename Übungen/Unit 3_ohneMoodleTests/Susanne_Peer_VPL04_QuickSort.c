//----------------------------------------------------------------
// Die Funktion qsort() ist in der Standardlibrary vorhanden,
// um Arrays oder Speicherbereiche zu sortieren.
// Schlagen Sie die Definition von qsort() in der entsprechenden
// man-Page nach.
//
// Schreiben Sie ein Programm, das ein int-Array mit 10 Werten
// zwischen 1 und 1000 definiert.
// Verwenden Sie dieses Array:
//    int arr [] ={10,286,888,104,22,399,58,38,1,478,6,99};
//
// Verwenden Sie die Funktion qsort() um das Array zuerst
// aufsteigend und dann absteigend zu sortieren.
// Definieren Sie dazu zwei Vergleichsfunktionen asc() und desc()
// die dem Funktionsprototypen oben entsprechen und jeweils eine
// aufsteigende oder absteigende Sortierreihenfolge implementieren.
// Geben Sie die sortierten Arrays auf stdout aus.
// Ausgabeformat:
// Aufsteigend:
// ...
// Absteigend:
//...
// ----------------------------------------------------------------
// Systemnahe Programmierung 6. Semester
//
// Susanne Peer SWD21

#include <stdio.h>
#include <stdlib.h>

int asc(const void *a, const void *b);
int desc(const void *a, const void *b);
void printArray(int arr[], int size);

int main() {
    int arr[] = {10, 286, 888, 104, 22, 399, 58, 38, 1, 478};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("###### QUICK SORT MAGIC ######\n\n");
    printf("Unsortiert:\n");
    printArray(arr, arr_size);

    // Sortieren aufwärts
    qsort(arr, arr_size, sizeof(int), asc);
    printf("\nAufsteigend:\n");
    printArray(arr, arr_size);

    // Sortieren abwärts
    // Speicherzuweisung für absteigendes Array
    // warum ? VS Code regt sich sonst über
    // arr_size --- expression must have a constant value
    // das ist mein workaround - bin mir nicht sicher aber
    // denke das fängt es ab, weil dynamische Größen in C
    // nicht erlaubt sind?? --> Lindner fragen!
    int *arr_desc = malloc(arr_size * sizeof(int));
    if (arr_desc == NULL) {
        printf("Leider konnte der Speicher nicht zugewiesen werden :( .\n");
        return 1;
    }

    for (int i = 0; i < arr_size; i++) {
        arr_desc[i] = arr[i];
    }

    qsort(arr_desc, arr_size, sizeof(int), desc);
    printf("\nAbsteigend:\n");
    printArray(arr_desc, arr_size);

    // Speicher freigeben
    free(arr_desc);

    return 0;
}

int asc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int desc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
