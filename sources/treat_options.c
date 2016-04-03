/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:58:53 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 19:07:47 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libargs.h>

static int		treat_large(t_option *option, char const *argv)
{
	char				**data;
	t_options_value		*new;

	data = ft_strsplit(argv, '=');
	if (ft_strequ(option->man->large, &data[0][2]))
	{
		if (data[1])
		{
			new = LIST_NEW(t_options_value);
			new->value = ft_strdup(data[1]);
			option->nb_values++;
			LIST_PUSH_BACK(&option->values, new);
		}
		free(data[0]);
		free(data[1]);
		free(data);
		return (1);
	}
	free(data[0]);
	free(data[1]);
	free(data);
	return (0);
}

static int		treat_brief(t_option *option, char const *argv)
{
	size_t	i;

	i = 1;
	while (i < ft_strlen(argv))
	{
		if (argv[i] == option->man->brief)
			return (1);
		i++;
	}
	return (0);
}

int				treat_option(t_option *option, char const *argv)
{
	if (ft_strlen(argv) > 2
			&& argv[0] == '-' && argv[1] == '-' && argv[2] != '-')
	{
		if (treat_large(option, argv))
			return (1);
	}
	else if (ft_strlen(argv) > 1 && argv[0] == '-' && argv[1] != '-')
	{
		if (treat_brief(option, argv))
			return (1);
	}
	return (0);
}
