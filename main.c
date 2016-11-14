#include "get_next_line.h"
#include <fcntl.h>

int        main(int argc, char **argv)
{
  int					fd;
  int					status;
  char				*line;

  if (argc == 1)
    fd = 0;
  else if (argc == 2)
    fd = open(argv[1], O_RDONLY);
  else
    return (2);
  printf("------BEFORE THE FILE------\n");
  while ((status = get_next_line(fd, &line)) == 1)
  {
    ft_putendl(line);
    free(line);
  }
  printf("------AFTER THE FILE------\n");
  if (argc == 2)
    close(fd);
}
