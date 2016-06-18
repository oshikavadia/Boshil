#include <stdio.h>

int compile(FILE *in, FILE *out) {
    FILE *temp = fopen("bshil.tmp", "w+");
    int c;
    while ((c = fgetc(in)) != EOF)
        fputc(c, temp);
    fclose(in);
    fclose(out);
    fclose(temp);
    remove("bshil.tmp");
    return 0;
}

int main(int argc, char *argv[]) {
    if (argv[1] != NULL) {
        FILE *input = fopen(argv[1], "r");
        if (input != NULL) {
            FILE *output;

            if (argv[2] != NULL)
                output = fopen(argv[2], "w");
            else
                output = fopen("a.out", "w");

            if (output != NULL)
                return compile(input, output);
            else
                puts("Failed to Open an Output File");
        } else
            puts("Failed to Open an Input File");
    } else
        puts("No Input File Specified");
    return -1;
}
