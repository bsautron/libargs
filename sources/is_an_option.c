#include <libargs.h>

// static int   is_an_brief_option(t_options *options, char c)
// {
//   t_options   *tmp;
//
//   tmp = options;
//   while (tmp)
//   {
//     if (c == tmp->brief)
//       return (1);
//     tmp = tmp->next;
//   }
//   return (0);
// }
//
// static int   is_an_large_option(t_options *options, char const *argv)
// {
//   t_options   *tmp;
//
//   tmp = options;
//   while (tmp)
//   {
//     if (ft_strequ(argv, tmp->large))
//       return (1);
//     tmp = tmp->next;
//   }
//   return (0);
// }

int   is_an_option(t_option *option, char const *argv)
{
  (void)option;
  (void)argv;
  // if (ft_strlen(argv) == 1)
  //   return is_an_brief_option(options, argv[0]);
  // else if (ft_strlen(argv) > 1)
  //   return is_an_large_option(options, argv);
  return (0);
}
