#include <libargs.h>

void add_usage(t_args *args, char *usage)
{
	ft_strcat(args->usage, usage);
}
