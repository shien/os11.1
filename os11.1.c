#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long
read_char_num(char *argv[])
{
    if (argv[1] == NULL) {
        fprintf(stderr, "no input option\n");
        exit(1);
    }

    if (strncmp(argv[1], "-s", 2) != 0) {
        fprintf(stderr, "no have this option: %s\n", argv[1]);
        exit(1);
    }

    if (argv[2] == NULL) {
        fprintf(stderr, "no input number\n");
        exit(1);
    }

    long long num = atoi(argv[2]);
    if (num == 0) {
        fprintf(stderr, "this is not number: %s\n", argv[2]);
        exit(1);
    }

    return num;
}

void 
write_chars(long long num)
{
    FILE *fp = NULL;

    if ((fp = fopen("os11.1.txt", "w")) == NULL) {
        fprintf(stderr, "open error\n");
        exit(1);
    }

    for (int i = 0; i < num; i++) {
        fputc('a', fp);
    }

    fclose(fp);
}

void 
read_chars()
{
    FILE *fp = NULL;

    if ((fp = fopen("os11.1.txt", "r")) == NULL) {
        fprintf(stderr, "open error\n");
        exit(1);
    }

    int c = 0; 
    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }

    fclose(fp);
}

int
main(int argc, char *argv[])
{
    long long num = read_char_num(argv);

    write_chars(num);

    read_chars();

    return 0;
}
