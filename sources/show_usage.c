/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_usage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:46:27 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 19:09:14 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libargs.h>

static void	show_descs(t_commander_desc *desc)
{
	t_commander_desc	*tmp;

	tmp = desc;
	while (tmp)
	{
		ft_putstr("\t");
		ft_putstr(tmp->value);
		if (tmp->next)
			ft_putstr("\n");
		tmp = tmp->next;
	}
}

static void	show_options(t_list_man_option *mans)
{
	t_list_man_option	*tmp;
	int					len_max;
	int					len;

	len_max = 0;
	tmp = mans;
	while (tmp)
	{
		if (tmp->man->large
			&& (len = ft_strlen(tmp->man->large)) > len_max)
			len_max = len;
		tmp = tmp->next;
	}
	tmp = mans;
	while (tmp)
	{
		print_option_line(tmp->man->brief, tmp->man->large, tmp->man->desc, len_max);
		tmp = tmp->next;
	}
}

void		show_usage(t_args args)
{
	ft_putstr("NAME:\n\t");
	ft_putstr(args.name);
	ft_putstr("\n\nDESCRIPTION:\n");
	show_descs(args.desc);
	ft_putstr("\n\nUSAGE:\n\t");
	ft_putstr(args.usage);
	ft_putstr("\n\nOPTIONS:\n");
	show_options(args.mans);
}
