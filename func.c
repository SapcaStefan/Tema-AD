#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func.h"


#define DIM 400000


char *random_string(int length)
{
    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!(){}`><-+@$%^&*~/:;\\";
    char *randomString = NULL;

    if (length)
    {
        randomString = malloc(length + 1);
        if (randomString)
        {
            for (int i = 0; i < length; i++)
            {
                int key = rand() % (sizeof(charset) - 1);
                randomString[i] = charset[key];
            }
            randomString[length] = '\0';
        }
    }

    return randomString;
}
