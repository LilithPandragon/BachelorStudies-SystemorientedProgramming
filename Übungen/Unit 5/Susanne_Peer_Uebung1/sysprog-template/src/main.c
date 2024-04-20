#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <config.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  if (argc != 2) {
      fprintf(stderr, "wrong argument please use:  %s <filename>\n", argv[0]);
      return EXIT_FAILURE;
  }


  char buffer[1024];
  int bytesRead;

  int fd = open(argv[1], O_RDONLY);

  while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
      if (write(STDERR_FILENO, buffer, bytesRead) != bytesRead) {
          perror("write");
          close(fd);
          exit(EXIT_FAILURE);
      }
  }


  close(fd);
  return EXIT_SUCCESS;
}