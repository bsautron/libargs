#include <libargs.h>

int     option_is_set(t_args args, char *key)
{
  t_option  *option;

  option = get_option(args, key);
  return (option->set);
}
