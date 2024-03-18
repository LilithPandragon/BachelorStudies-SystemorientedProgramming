//----------------------------------------------------------------
// VPL 04 - QuickSort Angabe:
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
//
// Frau Auger war so lieb mir die Unterlagen der
// VO zur Verfügung zu stellen, an Ihrem Bsp habe ich
// mich orientiert, welches Sie in der VO durchgegangen sind
//
// ----------------------------------------------------------------
// Systemnahe Programmierung 6. Semester
//
// Susanne Peer SWD21

#include <stdio.h>
#include <stdlib.h> //  qsort()

int asc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main(){
    
    int arr [] ={10,286,888,104,22,399,58,38,1,478,6,99};
    int arrLength = sizeof(arr) / sizeof(arr[0]);
    
    printf("Vor dem Sortieren: \n");
    
    for (int i = 0; i < arrLength; i++) {
        printf("%d\n", arr[i]); 
    }
    
    qsort(arr, arrLength, sizeof(int),asc);
    printf("\nAufsteigend: \n");
    for (int i = 0; i < arrLength; i++) {
        printf("%d\n", arr[i]); 
    }
    
    qsort(arr, arrLength, sizeof(int),desc);
    printf("\nAbsteigend: \n");
    for (int i = 0; i < arrLength; i++) {
        printf("%d\n", arr[i]); 
    }
    
}
