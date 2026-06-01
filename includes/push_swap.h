#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

int		parser_numbers(char *arg);
int		parser_range(char *arg);
int		parser_int(char *arg, int *number);
int		len_args(int argc, char **argv);
char	*join_args(int argc, char **argv);
char	**get_tokens(int argc, char **argv);
void	free_tokens(char **tokens);
int		print_error(void);

#endif
