/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values_option.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:32:37 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 18:37:19 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libargs.h>

char	**get_values_option(t_args args, char *key)
{
	t_options_value	*values;
	t_option		*option;
	char			**res;
	int				i;

	option = get_option(args, key);
	res = (char **)malloc(sizeof(char *) * (option->nb_values + 1));
	i = 0;
	values = option->values;
	while (values)
	{
		res[i] = values->value;
		values = values->next;
		i++;
	}
	res[i] = NULL;
	return (res);
}
