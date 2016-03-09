#include <libargs.h>

void  init_options(t_args *args)
{
  args->mans = NULL;
  args->options = HTAB_CREATE(1024, &hash_pour_les_nuls);
}
