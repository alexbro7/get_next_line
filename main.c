#include <fcntl.h>
#include "get_next_line.h"

int		main(int ac, char **av)
{
	int fd;
	char *line;
	int ret;

	fd = open(av[1], O_RDONLY);
	ret = 1;	
	while (ret)
	{
		if ((ret = get_next_line(fd, &line)))
		{
			printf("ret:%d--%s--\n", ret, line);
			free(line);
		}
	}
			printf("ret:%d--%s--\n", ret, line);
	return (0);
}
/*
int		main(int ac, char **av)
{
	int fd;
	char *line;
	const char filet[] = "__________________________________________________________________________________\n";
	int ret;
	int	i;

	fd = open(av[1], O_RDONLY);
	i = 1;
	while ((ret = get_next_line(fd, &line)))
	{
		printf("ret: %d, line %d\n%s$\n%s", ret, i, line, filet);
		i++;
	}
	printf("ret: %d, line %d\n%s$\n%s", ret, i, line, filet);
	return (0);
}*/
