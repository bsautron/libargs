#include <libargs.h>

void add_option(t_options **options, char *brief, char *large, char *desc)
{
	t_options		*new;

	if (brief || large)
	{
		new = LIST_NEW(t_options);
		new->brief = (brief) ? brief[1] : 0;
		new->large = (large) ? ft_strdup(&large[2]) : NULL;
		new->desc = (desc) ? ft_strdup(desc) : NULL;
		new->set = 0;
		new->values = NULL;
		LIST_PUSH_BACK(options, new);
	}
}
