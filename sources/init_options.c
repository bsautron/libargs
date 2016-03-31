#include <libargs.h>

void  init_options(t_args *args, char *name)
{
  args->mans = NULL;
  args->desc = NULL;
  args->options = HTAB_CREATE(1024, &hash_pour_les_nuls);
  ft_bzero(args->name, sizeof(char) * (ARGS_NAME_LEN_MAX));
  ft_strcat(args->name, (name && ft_strlen(name)) ? name : "no_name");
  ft_bzero(args->usage, sizeof(char) * (ARGS_USAGE_LEN_MAX));
  ft_strcat(args->usage, "./");
  ft_strcat(args->usage, args->name);
  ft_strcat(args->usage, " [options ...] [argv ...]");
  add_option(args, "-h", "--help", "Display help");
}
