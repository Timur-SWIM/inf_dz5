#include <stdio.h>
#include "fileProcessing.h"
int main(int argc, char *argv[]) {
    IndexError_t error = errorCheck(argc, argv);

    if (error != GOOD){
        exit(error);
    }
    FileParams_t *file = initFileParams();
    error = inputFilParams(file, argv[1]);

    if (error != GOOD){
        puts("ERROR: wrong file path or file cannot be opened");
        exit(error);
    }
    printFile(file);
    putchar('\n');
    printf("file->lineCount->%d", file->lineCount);
    putchar('\n');
    printNewCombination(file);
    freeFile(file);
    return 0;
}
