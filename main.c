#include <stdio.h>
#include <conio.h>
#include <stdlib.h> // system("cls") miatt

void createMain(int num) {
    int i;
    FILE *file;
    file = fopen("feladatok.txt", "w");
    fprintf(file, "#include <stdio.h>\n");
    fprintf(file, "#include <stdlib.h> // system(\"cls\") miatt\n\n");

    // Függvények deklarálása
    for (i = 1; i <= num; i++) {
        fprintf(file, "\nvoid feladat%d();", i);
    }
    fprintf(file, "\n\n");

    // main függvény generálása
    fprintf(file, "int main() {\n");
    fprintf(file, "    int feladatszam;\n");
    fprintf(file, "    char valasz;\n");
    fprintf(file, "    int ujra;\n");
    fprintf(file, "    do {\n");
    fprintf(file, "        system(\"cls\"); // Konzol törlése\n");
    fprintf(file, "        printf(\"Feladatok:\\n\");\n\n");

    for (i = 1; i <= num; i++) {
        fprintf(file, "        printf(\"\\t%d.feladat: - \\n\");\n", i);
    }

    fprintf(file, "\n        printf(\"Melyik feladatot szeretne megnezni?: \");\n");
    fprintf(file, "        scanf(\"%%d\", &feladatszam);\n\n");

    fprintf(file, "        if (feladatszam >= 1 && feladatszam <= %d) {\n", num);
    fprintf(file, "            switch (feladatszam) {\n");
    for (i = 1; i <= num; i++) {
        fprintf(file, "                case %d:\n", i);
        fprintf(file, "                    feladat%d();\n", i);
        fprintf(file, "                    break;\n");
    }
    fprintf(file, "                default:\n");
    fprintf(file, "                    printf(\"Nem letezik ilyen szamu feladat!\\n\");\n");
    fprintf(file, "                    break;\n");
    fprintf(file, "            }\n");
    fprintf(file, "        } else {\n");
    fprintf(file, "            printf(\"Nem letezik ilyen szamu feladat!\\n\");\n");
    fprintf(file, "        }\n\n");

    fprintf(file, "        while (1) {\n");
    fprintf(file, "            printf(\"Szeretne egy masik feladatot megnezni? (y/n): \");\n");
    fprintf(file, "            scanf(\" %%c\", &valasz);\n");
    fprintf(file, "            if (valasz == 'y' || valasz == 'Y') {\n");
    fprintf(file, "                ujra = 1;\n");
    fprintf(file, "                break;\n");
    fprintf(file, "            } else if (valasz == 'n' || valasz == 'N') {\n");
    fprintf(file, "                ujra = 0;\n");
    fprintf(file, "                break;\n");
    fprintf(file, "            } else {\n");
    fprintf(file, "                printf(\"Ervenytelen valasz! Kerem adjon meg 'y' vagy 'n'.\\n\");\n");
    fprintf(file, "            }\n");
    fprintf(file, "        }\n");
    fprintf(file, "    } while (ujra);\n\n");

    fprintf(file, "    return 0;\n");
    fprintf(file, "}\n");

    // Függvények definíciói
    for (i = 1; i <= num; i++) {
        fprintf(file, "\nvoid feladat%d() {\n", i);
        fprintf(file, "        system(\"cls\"); // Konzol törlése\n");
        fprintf(file, "    printf(\"%d.feladat\\n\");\n", i);
        fprintf(file, "    // Feladat %d megoldasa\n", i);
        fprintf(file, "}\n");
    }

    fclose(file);
}

int main() {
    int num;
    printf("Hany feladatot szeretne generalni? : ");
    scanf("%d", &num);

    if (num >= 1) {
        createMain(num);
        printf("A fajl letrehozva: feladatok.txt\n");
        printf("Bezrahatja a programot (Nyomjon ENTER-t)...\n");
        _getch();
    } else {
        printf("Ervenytelen bemenet! Adjon meg egy szamot ami 1-nel nagyobb.\n");
        printf("Bezrahatja a programot (Nyomjon ENTER-t)...\n");
        _getch();
    }

    return 0;
}
