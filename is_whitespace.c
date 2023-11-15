#include "main.h"

/**
 * is_whitespace - is white space function
 *
 * @str: comman
 */
int is_whitespace(const char *str) {
    while (*str != '\0') {
        if (!isspace((unsigned char)*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}
