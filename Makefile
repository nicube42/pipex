RED = \033[0;31m
NOCOLOR = \033[0m
GREEN = \033[0;32m
RED = \033[1;31m

PATH_SRC =			./srcs/
PATH_LIBFT =		./libft_printf/
PATH_OBJS =			./objs/

LIBFT = $(PATH_LIBFT)libftprintf.a
NAME = pipex

FILES = $(PATH_SRC)main.c $(PATH_SRC)pipex.c $(PATH_SRC)utils.c
OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(FILES))

CC = clang
CFLAGS = -Wextra -Werror -Wall
RM = rm -rf

all: logo $(NAME)

logo :
			@tput setaf 2; cat ascii_art/42pipex; tput setaf default

$(NAME): $(OBJS)
	@$(MAKE) -C $(PATH_LIBFT)
	@echo "Assembling $(NAME)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "${GREEN}✓${NOCOLOR}"
	@echo "$(GREEN)Compilation is done$(NOCOLOR)"

$(PATH_OBJS)%.o:	$(PATH_SRC)%.c
	@echo "Compiling $^: "
	@mkdir -p $(PATH_OBJS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "${GREEN}✓${NOCOLOR}"

clean:
	@echo "${RED}Cleaning objects in pipex: ${NOCOLOR}"
	@$(RM) $(PATH_OBJS)
	@echo "${GREEN}✓${NOCOLOR}"

fclean: clean
	@make fclean -C $(PATH_LIBFT)
	@echo "${RED}Cleaning all in pipex: ${NOCOLOR}"
	@$(RM) $(NAME)
	@echo "${GREEN}✓${NOCOLOR}"

re: fclean all

norme: 
	norminette $(PATH_SRC) $(PATH_LIBFT) ./includes

.PHONY: re all fclean clean norme