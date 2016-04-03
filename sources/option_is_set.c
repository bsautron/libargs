/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_is_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:32:27 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 18:36:17 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libargs.h>

int		option_is_set(t_args args, char *key)
{
	t_option	*option;

	option = get_option(args, key);
	return (option->set);
}
