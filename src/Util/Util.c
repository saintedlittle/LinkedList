//
// Created by ulynaxe on 11.11.22.
//

#include "Util.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* concat(char *s1, char *s2, char *del) {

    //TODO: use del
    for (int i = 0; i < strlen(s1); i++) {
        if (s1[i] == '0') {
            s1[i] = '\n';
            break;
        }
    }

    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    char *result = malloc(len1 + len2 + 1);

    if (!result) {
        fprintf(stderr, "malloc() failed: insufficient memory!\n");
        return NULL;
    }

    memcpy(result, s1, len1);

    memcpy(result + len1, s2, len2 + 1);

    result[len2+len1] = '0';

    return result;
}
