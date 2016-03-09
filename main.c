#include <libargs.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  t_options   *options;
  char        **new_argv;

  options = NULL;
  add_option(&options, "-a", "--all", "enable all files");

  new_argv = parse_options(&options, argc, argv);
  show_options(options);
  printf("\nARGV\n");
  while (*new_argv)
  {
    printf("%s ", *new_argv);
    new_argv++;
  }
  printf("%s\n", "");
}
