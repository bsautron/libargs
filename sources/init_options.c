/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:33:14 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 18:42:27 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libargs.h>
#include <libhash.h>

void	init_options(t_args *args, char *name)
{
	args->mans = NULL;
	args->desc = NULL;
	args->options = HTAB_CREATE(1024, &hash_pour_les_nuls);
	ft_bzero(args->name, sizeof(char) * (ARGS_NAME_LEN_MAX));
	ft_strcat(args->name, (name && ft_strlen(name)) ? name : "a.out");
	ft_bzero(args->usage, sizeof(char) * (ARGS_USAGE_LEN_MAX));
	ft_strcat(args->usage, "./");
	ft_strcat(args->usage, args->name);
	ft_strcat(args->usage, " [options ...] [argv ...]");
	add_option(args, "-h", "--help", "Display help");
}
