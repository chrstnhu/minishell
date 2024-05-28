#EXECUTE
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LDLIBS	= -lreadline -lft

#PATH
LIBFT_PATH = ./libft
LIBS_PATH = -L$(LIBFT_PATH)
OBJ_DIR	= obj

#SRCS
BUILTIN = cd.c echo.c env.c exit.c export.c pwd.c unset.c
EXECUTE = execute_builtin.c execute_external.c execute_multi_commands.c execute_one_command.c \
		get_path.c multi_commands_utils.c split_args.c split_commands.c split_args_utils.c \
		tilde.c wait.c
EXPAND = exit_status.c variable.c handle_expansion.c
MINIENV = minienv_str.c minienv_utils.c minienv.c
UTILS = error.c fd.c heredoc.c label_name.c pipe_quote.c redirect.c signal.c str.c syntax.c

SRCS = src/main.c $(BUILTIN:%=src/builtin/%) $(EXECUTE:%=src/execute/%) \
	   $(EXPAND:%=src/expand/%) $(MINIENV:%=src/minienv/%) $(UTILS:%=src/utils/%)


EXPAND_BONUS = exit_status.c variable.c 
BONUS = handle_expansion_bonus.c wildcard_bonus.c wildcard_value_bonus.c

SRCS_BONUS = src/main.c $(BUILTIN:%=src/builtin/%) $(EXECUTE:%=src/execute/%) \
	   $(EXPAND_BONUS:%=src/expand/%) $(MINIENV:%=src/minienv/%) $(UTILS:%=src/utils/%) \
	   $(BONUS:%=src/bonus/%)

NAME = minishell
NAME_BONUS = minishell_bonus

OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS = $(SRCS_BONUS:src/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: src/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ_DIR) $(OBJS) minishell.h 
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDLIBS) $(LIBS_PATH)

$(NAME_BONUS): $(OBJ_DIR) $(OBJS_BONUS) minishell.h
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS) $(LDLIBS) $(LIBS_PATH)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	make clean -C $(LIBFT_PATH)
	rm -rf $(OBJ_DIR)
	rm -f $(OBJ)
	rm -f $(OBJS_BONUS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
