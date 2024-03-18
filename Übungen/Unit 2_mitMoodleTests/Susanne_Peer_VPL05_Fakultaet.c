// ---------------------------------------------------------
//  VPL 05 - Fakultät Angabe:
// Schreiben Sie ein Programm, das eine ganze Zahl einliest und
// deren Fakultät n! berechnet.
//
// Wobei:  n! = 1*2*3* ...n
// oder    n! = \prod_{k=1}^n k
// NOTE:
// wobei diese beiden Schreibweisen mathematisch äquivalent sind
// und das Produkt über alle ganzen Zahlen von 1 bis n bedeutet.
//
//
// Verwenden Sie eine for Schleife und scanf() dazu.
// ----------------------------------------------------------------
// Systemnahe Programmierung 6. Semester
//
// Susanne Peer SWD21

#include <stdio.h>

int main(){
    
    int zahl;
    unsigned long fakultaet = 1;
    
   
    
    scanf("%d", &zahl);
    
    for (int i=1; i<= zahl; i++){
        fakultaet *= i;
    }
    
    printf("%lu", fakultaet);
    
    return 0;
}

