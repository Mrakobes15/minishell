# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: risolon <risolon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 18:38:02 by risolon           #+#    #+#              #
#    Updated: 2022/10/29 18:58:02 by risolon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
GCC = gcc
LIBFT = ./LibFT/libft.a
LIB_BINARY = ./LibFT -lft -lreadline -ledit
CFLAGS = -Wall -Werror -Wextra
INCLUDE_SYS	= 
LIB_SYS	= 

SRCS = main.c \
		special_split.c \
		superspecial_split.c \
		utils_1.c \
		utils_2.c \
		utils_3.c \
		utils_4.c \
		utils_5.c \
		get_next_line.c \
		lexer.c \
		errors.c \
		lexer_utils_1.c \
		lexer_utils_2.c \
		lexer_utils_3.c \
		create_cmd.c \
		del_quot.c \
		env_utils.c \
		env_utils1.c \
		redir_utils.c \
		redir.c \
		pipex_utils_1.c \
		pipex_utils_2.c \
		pipex.c \
		execute.c \
		redir_utils_2.c \
		builtin_cd.c \
		builtin_echo.c \
		builtin_exit.c \
		builtin_export.c \
		builtin_pwd.c \
		builtin_unset.c \
		

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) ./LibFT/libft.a $(NAME)

$(NAME): $(OBJS) $(LIBFT) minishell.h Makefile
	$(GCC) $(CFLAGS) $(OBJS) -L $(LIB_BINARY) -o $(NAME)

%.o				:	%.c
					$(GCC) $(CFLAGS) -c $< -o $@ 
							
$(LIBFT):
	make -C ./LibFT/ bonus

clean:
	rm -f $(OBJS) $(OBJSB)
	make -C ./LibFT/ fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus