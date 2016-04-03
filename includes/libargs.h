#ifndef LIBARGS_H
# define LIBARGS_H

# include <libft.h>
# include <liblist.h>
# include <libhtab.h>

# define	ARGS_NAME_LEN_MAX		255
# define	ARGS_USAGE_LEN_MAX		1024

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

typedef	struct	s_commander_desc
{
	void 		*next;
	char		*value;
}				t_commander_desc;

typedef struct  s_args
{
	char				name[ARGS_NAME_LEN_MAX];
	char				usage[ARGS_USAGE_LEN_MAX];
	t_commander_desc	*desc;
	char				**examples;
	t_list_man_option	*mans;
	t_htab           	options;
	int              	argc;
	char              	**argv;
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
	int             nb_values;
	t_man_option    *man;
	t_options_value *values;
}               t_option;

void      init_options(t_args *args, char *name);
void      add_option(t_args *args, char *brief, char *large, char *desc);
int      parse_options(t_args *args, int argc, char const **argv);
t_option  *get_option(t_args args, char *key);
void      show_args(t_args args);
void 		show_usage(t_args args);
int       option_is_set(t_args args, char *key);
char      **get_values_option(t_args args, char *key);
void 		add_desc(t_args *args, char *desc);
void 		add_usage(t_args *args, char *usage);
int				treat_option(t_option *option, char const *argv);

#endif
