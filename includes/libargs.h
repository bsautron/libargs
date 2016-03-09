#ifndef LIBARGS_H
# define LIBARGS_H

# include <libft.h>
# include <liblist.h>

typedef struct  s_options_value
{
  void    *next;
  char    *value;
}               t_options_value;

typedef struct  s_options
{
  void            *next;
  char            brief;
  char            *large;
  char            *desc;
  int             set;
  t_options_value *values;
}               t_options;

typedef struct  s_opt
{
  char          **(*parse)(int, char const **);
  t_options     *options;
}               t_opt;

void    add_option(t_options **options, char *brief, char *large, char *desc);
int     is_an_option(t_options *options, char const *argv);
char    **parse_options(t_options **options, int argc, char const **argv);
void    show_options(t_options *options);

#endif
