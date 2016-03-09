#include <libargs.h>

static t_list_man_option	*create_list_man_option(t_man_option *man, char *key)
{
	t_list_man_option		*new;

	new = LIST_NEW(t_list_man_option);
	new->key = key;
	new->man = man;
	return (new);
}

static void *create_man_option(char *brief, char *large, char *desc)
{
	t_man_option  *new;

	new = LIST_NEW(t_man_option);
	new->brief = (brief) ? brief[1] : 0;
	new->large = (large) ? ft_strdup(&large[2]) : NULL;
	new->desc = (desc) ? ft_strdup(desc) : NULL;
	return (new);
}

void add_option(t_args *args, char *brief, char *large, char *desc)
{
	t_option			*new;
	t_man_option	*man;
	char					*key;

	if (brief || large)
	{
		man = create_man_option(brief, large, desc);
		new = LIST_NEW(t_option);
		if (!brief && large)
			key = ft_strdup(large);
		else if (brief && !large)
			key = ft_strdup(brief);
		else
			key = ft_strjoin(brief, large);
		new->key = key;
		new->man = man;
		new->set = 0;
		new->values = NULL;
		LIST_PUSH_BACK(&args->mans, create_list_man_option(man, key));
		HTAB_SET(&args->options, new);
	}
}
