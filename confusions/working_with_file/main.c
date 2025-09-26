#include <stdio.h>

// struct Record {
//     int id;
//     char name[50];
// };

// typedef struct Record Record;

typedef struct {
    int id;
    char name[50];
} Record;

int main(void) {
    FILE *out_file;

    out_file = fopen("records.bin", "wb");

    if (out_file == NULL) {
        fprintf(stderr, "Error opening file for writing\n");
        return 1;
    }

    Record r1 = {1, "R1"};
    Record r2 = {2, "R2"};

    fprintf(stdout, "Writing records to file...\n");

    fwrite(&r1, sizeof(Record), 1, out_file);
    fwrite(&r2, sizeof(Record), 1, out_file);

    fclose(out_file);

    FILE *in_file;

    in_file = fopen("records.bin", "rb");
    if (in_file == NULL) {
        fprintf(stderr, "Error opening file for reading\n");
        return 1;
    }

    Record tmp;

    while(fread(&tmp, sizeof(Record), 1, in_file)) {
        printf("%d, %s\n", tmp.id, tmp.name);
    }

    fclose(in_file);

    return 0;
}