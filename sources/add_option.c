/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:38:22 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 18:46:23 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libargs.h>

static t_list_man_option	*create_list_man_opt(t_man_option *man, char *key)
{
	t_list_man_option		*new;

	new = LIST_NEW(t_list_man_option);
	new->key = key;
	new->man = man;
	return (new);
}

static void					*create_man_opt(char *b, char *l, char *desc)
{
	t_man_option	*new;

	new = LIST_NEW(t_man_option);
	new->brief = (b) ? b[1] : 0;
	new->large = (l) ? ft_strdup(&l[2]) : NULL;
	new->desc = (desc) ? ft_strdup(desc) : NULL;
	return (new);
}

void						add_option(t_args *args, char *b, char *l, char *d)
{
	t_option		*new;
	t_man_option	*man;
	char			*key;

	if (b || l)
	{
		man = create_man_opt(b, l, d);
		new = LIST_NEW(t_option);
		if (!b && l)
			key = ft_strdup(l);
		else if (b && !l)
			key = ft_strdup(b);
		else
			key = ft_strjoin(b, l);
		new->key = key;
		new->man = man;
		new->set = 0;
		new->values = NULL;
		LIST_PUSH_BACK(&args->mans, create_list_man_opt(man, key));
		HTAB_SET(&args->options, new);
	}
}
