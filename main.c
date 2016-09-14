#include <libargs.h>
#include <stdio.h>

// ./a.out -nG --size=12 --soft_drink="Coca Cola" --soft_drink="Jus de pomme" --hard_drink="Rhum" --anonymous sources/* -g -- --help

int main(int argc, char const *argv[])
{
	t_args	args;

	init_options(&args, "Example");
	add_desc(&args, "This is an amazing lib to parse your argv !");
	add_usage(&args, "./a.out [options ...] [argv ...] [options ...] [ect...]");

	add_option(&args, "-v", "--version", "Display the version");
	add_option(&args, NULL, "--number", "Number of pizza");
	add_option(&args, NULL, "--size", "Size of you pizza");
	add_option(&args, NULL, "--soft_drink", "Name of a soft drink");
	add_option(&args, NULL, "--hard_drink", "Name of an alcool");
	add_option(&args, "-g", "--gift", "This is a gift");
	add_option(&args, "-G", NULL, "ORGASME!");
	add_option(&args, "-a", "--anonymous", "You don't know who I am");

	parse_options(&args, argc, argv);

	printf("-- Options representation --\n");
	show_args(args);

	return (0);
}
