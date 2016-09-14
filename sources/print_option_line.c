#include <libft.h>

static void putstr_with_pad(char *str, int width)
{
	int	len;
	int	i;

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

void print_option_line(char brief, char *large, char *desc, int len)
{
	ft_putchar('\t');
	if (brief)
	{
		ft_putchar('-');
		ft_putchar(brief);
		ft_putstr(", ");
	}
	else
		ft_putstr("    ");
	if (large)
	{
		ft_putstr("--");
		putstr_with_pad(large, len);
	}
	else
		putstr_with_pad("", len);
	ft_putchar('\t');
	ft_putstr(desc);
	ft_putchar('\n');
}
