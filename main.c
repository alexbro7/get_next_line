#include <fcntl.h>
#include "get_next_line.h"

void	ft_putendl(char *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1); 
}

int		main()
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
			ft_putendl(line);
			free(line);
		}
	}
	ft_putendl(line);
	free(line);
	return (0);
}
