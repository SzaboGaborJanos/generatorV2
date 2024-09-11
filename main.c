#include <stdio.h>
#include <stdlib.h> // system("cls") miatt


void feladat1();
void feladat2();
void feladat3();
void feladat4();
void feladat5();

int main() {
    int feladatszam;
    char valasz;
    int ujra;
    do {
        system("cls"); // Konzol törlése
        printf("Feladatok:\n");

        printf("\t1.feladat: - \n");
        printf("\t2.feladat: - \n");
        printf("\t3.feladat: - \n");
        printf("\t4.feladat: - \n");
        printf("\t5.feladat: - \n");

        printf("Melyik feladatot szeretne megnezni?: ");
        scanf("%d", &feladatszam);

        if (feladatszam >= 1 && feladatszam <= 5) {
            switch (feladatszam) {
                case 1:
                    feladat1();
                    break;
                case 2:
                    feladat2();
                    break;
                case 3:
                    feladat3();
                    break;
                case 4:
                    feladat4();
                    break;
                case 5:
                    feladat5();
                    break;
                default:
                    printf("Nem letezik ilyen szamu feladat!\n");
                    break;
            }
        } else {
            printf("Nem letezik ilyen szamu feladat!\n");
        }

        while (1) {
            printf("Szeretne egy masik feladatot megnezni? (y/n): ");
            scanf(" %c", &valasz);
            if (valasz == 'y' || valasz == 'Y') {
                ujra = 1;
                break;
            } else if (valasz == 'n' || valasz == 'N') {
                ujra = 0;
                break;
            } else {
                printf("Ervenytelen valasz! Kerem adjon meg 'y' vagy 'n'.\n");
            }
        }
    } while (ujra);

    return 0;
}

void feladat1() {
        system("cls"); // Konzol törlése
    printf("1.feladat\n");
    // Feladat 1 megoldasa
}

void feladat2() {
        system("cls"); // Konzol törlése
    printf("2.feladat\n");
    // Feladat 2 megoldasa
}

void feladat3() {
        system("cls"); // Konzol törlése
    printf("3.feladat\n");
    // Feladat 3 megoldasa
}

void feladat4() {
        system("cls"); // Konzol törlése
    printf("4.feladat\n");
    // Feladat 4 megoldasa
}

void feladat5() {
        system("cls"); // Konzol törlése
    printf("5.feladat\n");
    // Feladat 5 megoldasa
}
