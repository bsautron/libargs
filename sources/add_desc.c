#include <libargs.h>

void add_desc(t_args *args, char *desc)
{
	t_commander_desc	*new;

	new = LIST_NEW(t_commander_desc);
	new->value = ft_strdup(desc);
	LIST_PUSH_BACK(&args->desc, new);
}
