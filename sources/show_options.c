#include <libargs.h>

void    show_options(t_options *options)
{
  while (options)
  {
    ft_putstr((options->set) ? "\e[0;0;42m" : "\e[0;0;41m");
    ft_putstr("    \e[0m");
    ft_putstr(" -");
    ft_putchar(options->brief);
    ft_putstr(", --");
    ft_putstr(options->large);
    ft_putchar('\n');
    while (options->values)
    {
      ft_putstr("   =");
      ft_putstr(options->values->value);
      ft_putchar('\n');
      options->values = options->values->next;
    }
    options = options->next;
  }
}
