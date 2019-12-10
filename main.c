#include <fcntl.h>
#include "get_next_line.h"

int		main(int ac, char **av)
{
	int fd;
	char *line;
	int ret;
	int	i;

	fd = open(av[1], O_RDONLY);
	i = 1;
	while ((ret = get_next_line(fd, &line)))
	{
		printf("ret: %d, line %d\n %s\n\n", ret, i, line);
		i++;
	}
	return (0);
}
