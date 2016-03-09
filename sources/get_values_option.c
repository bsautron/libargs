#include <libargs.h>

char    **get_values_option(t_args args, char *key)
{
  t_options_value   *values;
  t_option          *option;
  char              **res;
  int               i;

  option = get_option(args, key);
  res = (char **)malloc(sizeof(char *) * (option->nb_values + 1));
  i = 0;
  values = option->values;
  while (values)
  {
    res[i] = values->value;
    values = values->next;
    i++;
  }
  res[i] = NULL;
  return (res);
}
