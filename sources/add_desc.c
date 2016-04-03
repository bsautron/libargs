/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_desc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:31:17 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 18:34:03 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libargs.h>

void	add_desc(t_args *args, char *desc)
{
	t_commander_desc	*new;

	new = LIST_NEW(t_commander_desc);
	new->value = ft_strdup(desc);
	LIST_PUSH_BACK(&args->desc, new);
}
