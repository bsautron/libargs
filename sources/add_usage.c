#include <libargs.h>

void add_usage(t_args *args, char *usage)
{
	ft_bzero(args->usage, sizeof(char) * ARGS_USAGE_LEN_MAX);
	ft_strcat(args->usage, usage);
}
