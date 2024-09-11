#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void createMain(int num, int fileRead, const char *inputFilename, int fileWrite, const char *outputFilename) {
    int i;
    FILE *outputFile;
    outputFile = fopen("feladatok.txt", "w");

    fprintf(outputFile, "#include <stdio.h>\n");
    fprintf(outputFile, "#include <stdlib.h> // system(\"cls\") miatt\n\n");

    // Fuggvenyek deklaralasa
    for (i = 1; i <= num; i++) {
        fprintf(outputFile, "\nvoid feladat%d();", i);
    }
    fprintf(outputFile, "\n\n");

    // main fuggveny generalasa
    fprintf(outputFile, "int main() {\n");
    fprintf(outputFile, "    int feladatszam;\n");
    fprintf(outputFile, "    char valasz;\n");
    fprintf(outputFile, "    int ujra;\n");

    // Fajlbeolvasas es fajlba kiiras opcio kezelese
    if (fileRead == 1) {
        fprintf(outputFile, "    FILE *inputFile = fopen(\"%s\", \"r\");\n", inputFilename);
        fprintf(outputFile, "    if (inputFile == NULL) {\n");
        fprintf(outputFile, "        printf(\"Hiba: Nem sikerult megnyitni a %s fajlt.\\n\");\n", inputFilename);
        fprintf(outputFile, "        return 1;\n");
        fprintf(outputFile, "    }\n");
    }
    if (fileWrite == 1) {
        fprintf(outputFile, "    FILE *outputFile = fopen(\"%s\", \"w\");\n", outputFilename);
        fprintf(outputFile, "    if (outputFile == NULL) {\n");
        fprintf(outputFile, "        printf(\"Hiba: Nem sikerult megnyitni a %s fajlt.\\n\");\n", outputFilename);
        fprintf(outputFile, "        return 1;\n");
        fprintf(outputFile, "    }\n");
        if (fileRead == 1) {
            fprintf(outputFile, "    char ch;\n");
            fprintf(outputFile, "    while ((ch = fgetc(inputFile)) != EOF) {\n");
            fprintf(outputFile, "        fputc(ch, outputFile);\n");
            fprintf(outputFile, "    }\n");
            fprintf(outputFile, "    fclose(inputFile);\n");
        }
        fprintf(outputFile, "    fclose(outputFile);\n");
    }

    fprintf(outputFile, "    do {\n");
    fprintf(outputFile, "        system(\"cls\"); // Konzol torlese\n");
    fprintf(outputFile, "        printf(\"Feladatok:\\n\");\n\n");

    for (i = 1; i <= num; i++) {
        fprintf(outputFile, "        printf(\"\\t%d.feladat: - \\n\");\n", i);
    }

    fprintf(outputFile, "\n        printf(\"Melyik feladatot szeretne megnezni?: \");\n");
    fprintf(outputFile, "        scanf(\"%%d\", &feladatszam);\n\n");

    fprintf(outputFile, "        if (feladatszam >= 1 && feladatszam <= %d) {\n", num);
    fprintf(outputFile, "            switch (feladatszam) {\n");
    for (i = 1; i <= num; i++) {
        fprintf(outputFile, "                case %d:\n", i);
        fprintf(outputFile, "                    feladat%d();\n", i);
        fprintf(outputFile, "                    break;\n");
    }
    fprintf(outputFile, "                default:\n");
    fprintf(outputFile, "                    printf(\"Nem letezik ilyen szamu feladat!\\n\");\n");
    fprintf(outputFile, "                    break;\n");
    fprintf(outputFile, "            }\n");
    fprintf(outputFile, "        } else {\n");
    fprintf(outputFile, "            printf(\"Nem letezik ilyen szamu feladat!\\n\");\n");
    fprintf(outputFile, "        }\n\n");

    fprintf(outputFile, "        while (1) {\n");
    fprintf(outputFile, "            printf(\"Szeretne egy masik feladatot megnezni? (y/n): \");\n");
    fprintf(outputFile, "            scanf(\" %%c\", &valasz);\n");
    fprintf(outputFile, "            if (valasz == 'y' || valasz == 'Y') {\n");
    fprintf(outputFile, "                ujra = 1;\n");
    fprintf(outputFile, "                break;\n");
    fprintf(outputFile, "            } else if (valasz == 'n' || valasz == 'N') {\n");
    fprintf(outputFile, "                ujra = 0;\n");
    fprintf(outputFile, "                break;\n");
    fprintf(outputFile, "            } else {\n");
    fprintf(outputFile, "                printf(\"Ervenytelen valasz! Kerem adjon meg 'y' vagy 'n'.\\n\");\n");
    fprintf(outputFile, "            }\n");
    fprintf(outputFile, "        }\n");
    fprintf(outputFile, "    } while (ujra);\n\n");

    fprintf(outputFile, "    printf(\"Program vege. Nyomjon meg egy gombot a kilepeshez...\\n\");\n");
    fprintf(outputFile, "    getchar(); getchar();\n"); // Elso getchar a maradek uj sor karakterhez, masodik a valos varakozashoz

    fprintf(outputFile, "    return 0;\n");
    fprintf(outputFile, "}\n");

    // Fuggvenyek definicioi
    for (i = 1; i <= num; i++) {
        fprintf(outputFile, "\nvoid feladat%d() {\n", i);
        fprintf(outputFile, "        system(\"cls\"); // Konzol torlese\n");
        fprintf(outputFile, "    printf(\"%d.feladat\\n\");\n", i);
        fprintf(outputFile, "    // Feladat %d megoldasa\n", i);
        fprintf(outputFile, "}\n");
    }

    fclose(outputFile);
}

int main() {
    char inputFilename[100];
    char outputFilename[100];
    int fileRead = 0;
    int fileWrite = 0;
    int num;

    // Kerdezze meg, hogy szeretne-e fajlbol beolvasni
    printf("Szeretne fajlbol beolvasast? (y/n): ");
    char c = getch();
    if (c == 'y' || c == 'Y') {
        fileRead = 1;
        printf("\nKerem adja meg a beolvasando fajl nevet (kiterjesztessel): ");
        scanf("%s", inputFilename);
    }

    // Kerdezze meg, hogy szeretne-e fajlba kiirni
    printf("\nSzeretne fajlba kiirni? (y/n): ");
    c = getch();
    if (c == 'y' || c == 'Y') {
        fileWrite = 1;
        printf("\nKerem adja meg a kiirando fajl nevet (kiterjesztessel): ");
        scanf("%s", outputFilename);
    }

    // Kerje be, hogy hany feladatot szeretne generalni
    printf("\nHany feladatot szeretne generalni? : ");
    scanf("%d", &num);

    if (num >= 1) {
        createMain(num, fileRead, inputFilename, fileWrite, outputFilename);
        printf("A fajl letrehozva: feladatok.txt\n");
        printf("Bezrahatja a programot (Nyomjon ENTER-t)...\n");
        getchar(); getchar(); // Elso getchar a maradek uj sor karakterhez, masodik a valos varakozashoz
    } else {
        printf("Ervenytelen bemenet! Adjon meg egy szamot ami 1-nel nagyobb.\n");
        printf("Bezrahatja a programot (Nyomjon ENTER-t)...\n");
        getchar(); getchar(); // Elso getchar a maradek uj sor karakterhez, masodik a valos varakozashoz
    }

    return 0;
}
