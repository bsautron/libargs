/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_usage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:32:11 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 18:34:15 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libargs.h>

void	add_usage(t_args *args, char *usage)
{
	ft_bzero(args->usage, sizeof(char) * ARGS_USAGE_LEN_MAX);
	ft_strcat(args->usage, usage);
}
