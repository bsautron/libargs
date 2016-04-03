/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:32:19 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 18:36:56 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libargs.h>

t_option	*get_option(t_args args, char *key)
{
	return (HTAB_GET(args.options, t_option, key));
}
