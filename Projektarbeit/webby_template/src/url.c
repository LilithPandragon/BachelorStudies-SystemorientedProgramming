/*
 * url.c
 * handle urls and uri parameters
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <url.h>

static char hex2Char(char ch) {
  return isdigit(ch) ? ch - '0' : tolower(ch) - 'a' + 10;
}

/*
 * decode an URL/URI
 * Return Value: decoded url string or NULL if an error occurred.
 *   you must free the memory allocated by the returned pointer. 
 */
char *decodeUri(char *uri) {
  char *buffer = NULL;
  char *ptr;

  if ((buffer = malloc(strlen(uri) + 1)) == NULL) 
    return NULL;

  ptr = buffer;
  while (*uri) {
    // avoid to go over the end of the string
    if (*uri == '%' &&  *(uri+1) && *(uri+2)) {
        *ptr++ = hex2Char(*(uri+1)) << 4 | hex2Char(*(uri+2));
        uri += 2;
    }
    // handle old mime-type space symbol
    else if (*uri == '+') { 
      *ptr++ = ' ';
    }
    else {
      *ptr++ = *uri;
    }
    uri++;
  }
  *ptr = '\0';
  return buffer;
}


