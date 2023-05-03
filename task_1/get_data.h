//
// Created by mac on 15.04.2023.
//

#ifndef TASK_1_GET_DATA_H
#define TASK_1_GET_DATA_H
#include <stdio.h>
#include <string.h>
void checkData(char *path);

typedef struct line_t{
    int arr_size;
    int arr_id;
}line_t;

typedef struct data_size_t{
    int line_count;
    struct line_t *array;
}data_size_t;

#endif //TASK_1_GET_DATA_H
