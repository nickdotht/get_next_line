#include "get_next_line.h"
#include <fcntl.h>

int        main(int argc, char **argv)
{
  int         fd;
  int         fd2;
  int					fd3;
  char					*line;

  argc = 0;
  argv = NULL;

  fd = open("1", O_RDONLY);
  fd2 = open("2", O_RDONLY);
  fd3 = open("3", O_RDONLY);

  printf("%d\n", get_next_line(fd, &line));
  printf("%d\n", get_next_line(fd3, &line));
  printf("%d\n", get_next_line(fd, &line));
  printf("%d\n", get_next_line(fd3, &line));
  printf("%d\n", get_next_line(fd2, &line));
  printf("%d\n", get_next_line(fd, &line));
  printf("%d\n", get_next_line(fd3, &line));
  printf("%d\n", get_next_line(fd2, &line));
  // printf("\nStatus is %d\n", status);
}
