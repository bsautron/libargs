#include <libargs.h>
#include <stdio.h>

static int   treat_large(t_option *option, char const *argv)
{
  char              **data;
  t_options_value   *new;

  data = ft_strsplit(argv, '=');
  if (ft_strequ(option->man->large, &data[0][2]))
  {
    if (data[1])
    {
      new = LIST_NEW(t_options_value);
      new->value = ft_strdup(data[1]);
      LIST_PUSH_BACK(&option->values, new);
    }
    free(data[0]);
    free(data[1]);
    free(data);
    return (1);
  }
  free(data[0]);
  free(data[1]);
  free(data);
  return (0);
}

static int   treat_brief(t_option *option, char const *argv)
{
  size_t            i;

  i = 1;
  while (i < ft_strlen(argv))
  {
    if (argv[i] == option->man->brief)
      return (1);
    i++;
  }
  return (0);
}

static int   treat_option(t_option *option, char const *argv)
{

  if (ft_strlen(argv) > 2 && argv[0] == '-' && argv[1] == '-' && argv[2] != '-')
  {
    if (treat_large(option, argv))
      return (1);
  }
  else if (ft_strlen(argv) > 1 && argv[0] == '-' && argv[1] != '-')
  {
    if (treat_brief(option, argv))
      return (1);
  }
  return (0);
}

static int   find_option_in_args(t_option *option, int *setting, int argc, char const **argv)
{
  int   i;
  int   find;

  find = 0;
  i = 0;
  while (i < argc && !(ft_strlen(argv[i]) == 2 && argv[i][0] == '-' && argv[i][1] == '-'))
  {
    if (treat_option(option, argv[i]))
    {
      setting[i] = 1;
      find = 1;
    }
    i++;
  }
  return (find);
}
//
// static char     **get_args(int *setting, int argc, char const **argv)
// {
//   int             i;
//   int             j;
//   char            **args;
//
//   i = 0;
//   j = 0;
//   args = (char **)malloc(sizeof(char *) * (argc + 1));
//   while (argv[i])
//   {
//     if (setting[i] == 0)
//       args[j++] = ft_strdup(argv[i]);
//     i++;
//   }
//   args[j] = NULL;
//   free(setting);
//   return (args);
// }

void  parse_options(t_args *args, int argc, char const **argv)
{
  int                *setting;
  // int             new_argc;
  t_list_man_option  *list_man;
  t_option           *option;

  setting = (int *)malloc(sizeof(int) * argc);
  list_man = args->mans;
  while (list_man)
  {
    option = HTAB_GET(args->options, t_option, list_man->key);
    if (find_option_in_args(option, setting, argc, argv))
    {
      option->set = 1;
    }
    list_man = list_man->next;
  }
  (void)argc;
  (void)argv;
  // ft_bzero(setting, sizeof(int) * argc);
  // new_argc = argc;
  //
  // tmp = *options;
  // while (tmp)
  // {
  //   if (find_option_in_args(&tmp, setting, argc, argv))
  //   {
  //     tmp->set = 1;
  //     new_argc--;
  //   }
  //   tmp = tmp->next;
  // }
  // return (get_args(setting, new_argc, argv));
}