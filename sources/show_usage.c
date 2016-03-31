#include <libargs.h>

static void putstr_with_pad(char *str, int width)
{
	int		len;
	int		i;

	len = ft_strlen(str);
	if (len > width)
		ft_putstr(str);
	else
	{
		i = 0;
		ft_putstr(str);
		while (i++ < width - len)
			ft_putchar(' ');
	}
}

static void show_descs(t_commander_desc *desc)
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

static void show_options(t_list_man_option *mans)
{
	t_list_man_option	*tmp;
	int					len_max_large;
	int					len;

	len_max_large = 0;
	tmp = mans;
	while (tmp)
	{
		if ((len = ft_strlen(tmp->man->large)) > len_max_large)
			len_max_large = len;
		tmp = tmp->next;
	}
	tmp = mans;
	while (tmp)
	{
		ft_putstr("\t-");
		ft_putchar(tmp->man->brief);
		ft_putstr(", --");
		putstr_with_pad(tmp->man->large, len_max_large);
		ft_putchar('\t');
		ft_putstr(tmp->man->desc);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

void show_usage(t_args args)
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
