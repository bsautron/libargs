#ifndef LIBARGS_H
# define LIBARGS_H

# include <libft.h>
# include <liblist.h>
# include <libhtab.h>

typedef struct  s_man_option
{
  char      brief;
  char      *large;
  char      *desc;
}               t_man_option;

typedef struct  s_list_man_option
{
  void          *next;
  char          *key;
  t_man_option  *man;
}               t_list_man_option;

typedef struct  s_args
{
  t_list_man_option *mans;
  t_htab            options;
  int               argc;
  char              **argv;
}               t_args;

typedef struct  s_options_value
{
  void    *next;
  char    *value;
}               t_options_value;

typedef struct  s_option
{
  void            *next;
  char            *key;
  int             set;
  t_man_option    *man;
  t_options_value *values;
}               t_option;

void      init_options(t_args *args);
void      add_option(t_args *args, char *brief, char *large, char *desc);
int       is_an_option(t_option *options, char const *argv);
void      parse_options(t_args *args, int argc, char const **argv);
t_option  *get_option(t_args args, char *key);
void      show_args(t_args args);

#endif
