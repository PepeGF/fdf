#include "../inc/fdf.h"

void	ft_error_manage(int argc, char *argv[])
{
	int	len;

	len = ft_strlen(argv[1]);
	if (argc < 2)
	{
		errno = 5;
		perror ("Too few arguments, map route required");
	}
	if (argc > 2)
	{
		errno = 5;
		perror ("Too many arguments");
	}
	if (argv[1][0] != 'm' || argv[1][1] != 'a' || argv[1][2] != 'p'
		|| argv[1][3] != 's' || argv[1][len - 1] != 'f' ||
		argv[1][len - 2] != 'd' || argv[1][len - 3] != 'f' ||
		argv[1][len - 4] != '.')
	{
		errno = 14;
		perror ("Invalid map route");
	}
}
