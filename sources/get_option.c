#include <libargs.h>

t_option  *get_option(t_args args, char *key)
{
  return (HTAB_GET(args.options, t_option, key));
}
