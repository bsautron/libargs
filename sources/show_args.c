/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:33:03 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 18:41:40 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libargs.h>

static void		print_set(t_option *option)
{
	ft_putstr((option->set) ? "\e[0;0;42m" : "\e[0;0;41m");
	ft_putstr("    \e[0m");
	print_option_line(option->man->brief, option->man->large, option->man->desc, 15);
}

static void		print_values(t_option *option)
{
	t_options_value	*values;

	values = option->values;
	while (values)
	{
		ft_putstr("   =");
		ft_putstr(values->value);
		ft_putchar('\n');
		values = values->next;
	}
}

static void		print_argc(int argc)
{
	ft_putstr("argc: ");
	ft_putnbr(argc);
	ft_putchar('\n');
}

static void		print_argv(char **argv)
{
	ft_putstr("argv: ");
	ft_putstr_tab(argv);
}

void			show_args(t_args args)
{
	t_list_man_option	*list_man;
	t_option			*option;

	list_man = args.mans;
	while (list_man)
	{
		option = get_option(args, list_man->key);
		print_set(option);
		print_values(option);
		list_man = list_man->next;
	}
	print_argc(args.argc);
	print_argv(args.argv);
}
