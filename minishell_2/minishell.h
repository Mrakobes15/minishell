/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:32:44 by risolon           #+#    #+#             */
/*   Updated: 2022/10/27 19:18:13 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/wait.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include <dirent.h>
# include <limits.h>
# include "LibFT/libft.h"



// # define EMPTY 0
// # define CMD 1
// # define ARG 2
// # define TRUNC 3
// # define APPEND 4
// # define INPUT 5
// # define PIPE 6
// # define END 7
// # define EOF -1
// # define ERRCHAR 0
// # define SRC_POS -2

// typedef struct s_source
// {
// 	char	*buffer;
// 	long	buff_size;
// 	long	current;
// 	char	*tok_buff;
// 	int		buff_size;
// 	int		buff_index;
// }	t_source;

// typedef struct s_token
// {
// 	t_source	*src;
// 	int			len;
// 	char		*text;
// }				t_token;

// typedef enum e_node_type
// {
// 	NODE_COMMAND,
// 	NODE_VAR,
// }	t_node_type;

// typedef enum e_val_type
// {
// 	VAL_SINT = 1,
// 	VAL_UINT,
// 	VAL_SLLONG,
// 	VAL_ULLONG,
// 	VAL_FLOAT,
// 	VAL_LDOUBLE,
// 	VAL_CHR,
// 	VAL_STR,
// }	t_val_type;

// typedef union u_symval
// {
// 	long				sint;
// 	unsigned long		uint;
// 	long long			sllong;
// 	unsigned long long	ullong;
// 	double				sfloat;
// 	long double			ldouble;
// 	char				chr;
// 	char				*str;
// }	t_symval;

// typedef struct s_node
// {
// 	t_node_type	type;
// 	t_val_type	val_type;
// 	t_symval	val;
// 	int			children;
// 	t_node		*first_child;
// 	t_node		*next_sibling;
// 	t_node		*prev_sibling;
// }			t_node;

/* Actual */
typedef struct s_pip
{
	int	lpipe[2];
	int	rpipe[2];
	int	in;
	int	curr_index;
	int	last_herdoc;
}	t_pip;

typedef struct s_info
{
	char	*line;
	char	**commands;
	char	***cmd;
	char	**splited;
	int		promptflag;
	int		argc;
	char	**argv;
	char	**env;
	int		exit;
	int		err;
	int		count;
	int		pid;
	int		*last_r;
	t_list	*vars;
	t_pip	pip;
}	t_info;

/* GNL */

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*get_line(char *buf, int j);
char	*make_line(char *buf, int i);
char	*check_line(char *line);
char	*ft_strdup(const char *s);
/* lexer_utils_1.c */
char	*read_cmd(char *buff);
int		ft_quot(char *s);
int		is_it_quot(char s, int code);
int		check_semicolon(char **str);
int		check_space_in_quot(t_info *info);
/* lexer_utils_2.c */
void	open_dollar(t_info *info);
int		redir_error(char *str, int i);
int		check_redir(t_info *info);
int		check_pipes(t_info *info);
void	ft_cutter(t_info *info);
/* lexer_utils_3.c */
char	**modified_arg(char **argv);
char	**ft_add_string(char **arr, char *str);
void	foo_helper(char *s, int *c, int *len);
char	**foo_bar(char **arr);
int		command_count(char **s);
/* lexer.c */
int		lexer(t_info *info);
/* create_cmd.c */
char	**ft_create_node(t_info *info, int *j);
char	***create_cmd(t_info *info);
/* utils_1.c */
void	ft_mshfree_helper(int exc, t_info *info);
int		ft_mshfree1(t_info *info, int code, int exc);
char	*add_semicolon(void);
int		add_pipe_helper(t_info	*info, char **newcom, int i, int j);
int		add_pipe(t_info *info);
/* utils_2.c */
char	*ft_gnlstrjoin(char *remains, char *buffer);
int		ft_strrchr_deep(char *s, int c);
void	last_redir_helper(t_info *info, char *s, int index);
void	last_redir(t_info *info, char **s);
/* utils_3.c */
char	*find_env(char *var, t_info *info);
void	set_shlvl(t_info *info);
void	init(t_info *info, int arg1, char **arg2, char **arg3);
int		ft_space_check(char *s);
/* errors.c */
int		ft_error(t_info *info, int code);
/* env_utils.c */
int		enver(t_info *info, int index, int i, int j);
char	*ft_import(char	*str1, char *str2, int i, int j);
int		ft_swap_env(t_info *info, int index, int i);
/* env_utils1.c */
int		set_envp(t_info *info);
void	get_env(t_info *info);
int		check_name_var_pars(char *str);
int		check_env_pars(char *s);
int		ft_swap_ask(t_info *info, int index, int i);
/* del_quot.c */
void	ft_delquot(char *s, char *nl);
void	ft_swap_string(t_info *info, int pos, char *src);
void	change_f_command(t_info *info);
/* special_split.c */
int		ft_parser_split_helper(char *s, int i, char *c, int code);
int		ft_parser_split_helper2(char *s, int i, char *c, int code);
size_t	ft_word_count_up(char *s, char *c, int code);
char	*ft_newword_up(char *s, char c, size_t *i);
char	**ft_split_up(char *s, char *c);
/* redir_utils.c */
int		helper(char *str, int *i);
void	skip_quot(char *str, int *i, int *j);
char	*skip_semic(char	*str);
int		find_name_len(char *str, int i, char c);
char	*rebuilder(t_info *info, int i, int len, int index);
/* redir.c */
int		ft_strrchr_upred(char *str, int c);
void	create_left(t_info *info, char *str, int index);
void	create_double_left(t_info *info, char *str, int index);
void	create_right(t_info	*info, char	*str, int in);
void	rebuild_redir(t_info *info);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
#endif
