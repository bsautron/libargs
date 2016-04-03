/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:51:09 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 18:59:21 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libargs.h>

static int		find_option_in_args(t_option *o, int *s, int c, char const **a)
{
	int		i;
	int		find;

	find = 0;
	i = 0;
	while (i < c && !(ft_strlen(a[i]) == 2
			&& a[i][0] == '-' && a[i][1] == '-'))
	{
		if (treat_option(o, a[i]))
		{
			s[i] = 1;
			find = 1;
		}
		i++;
	}
	return (find);
}

static char		**get_args(int *setting, int argc, char const **argv)
{
	int				i;
	int				j;
	char			**args;

	i = 0;
	j = 0;
	args = (char **)malloc(sizeof(char *) * (argc + 1));
	while (argv[i])
	{
		if (setting[i] == 0)
			args[j++] = ft_strdup(argv[i]);
		i++;
	}
	args[j] = NULL;
	free(setting);
	return (args);
}

static int		count_not_option(int *setting, int argc)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < argc)
	{
		if (setting[i] == 0)
			count++;
		i++;
	}
	return (count);
}

int				parse_options(t_args *args, int argc, char const **argv)
{
	int					*setting;
	int					new_argc;
	t_list_man_option	*list_man;
	t_option			*option;

	new_argc = argc;
	setting = (int *)malloc(sizeof(int) * argc);
	ft_bzero(setting, sizeof(int) * argc);
	list_man = args->mans;
	while (list_man)
	{
		option = HTAB_GET(args->options, t_option, list_man->key);
		if (find_option_in_args(option, setting, argc, argv))
			option->set = 1;
		list_man = list_man->next;
	}
	args->argc = count_not_option(setting, argc);
	args->argv = get_args(setting, args->argc, argv);
	if (option_is_set(*args, "-h--help"))
	{
		show_usage(*args);
		return (0);
	}
	return (1);
}
