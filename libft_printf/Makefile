RED = \033[0;31m
NOCOLOR = \033[0m
GREEN = \033[0;32m
RED = \033[1;31m

NAME		=	libftprintf.a

SRC_DIR			=	srcs
HDR_DIR			=	includes
OBJ_DIR			=	objs
LIBFT_DIR		=	libft
PRINTF_DIR		=	ft_printf

SRC_FILES		=	$(LIBFT_FILES) \
					$(FT_PRINTF_FILES) \

LIBFT_FILES		=	$(LIBFT_DIR)/ft_atof.c \
					$(LIBFT_DIR)/ft_atoi.c \
					$(LIBFT_DIR)/ft_atol.c \
					$(LIBFT_DIR)/ft_bzero.c \
					$(LIBFT_DIR)/ft_calloc.c \
					$(LIBFT_DIR)/ft_isalnum.c \
					$(LIBFT_DIR)/ft_isalpha.c \
					$(LIBFT_DIR)/ft_isascii.c \
					$(LIBFT_DIR)/ft_isdigit.c \
					$(LIBFT_DIR)/ft_isprint.c \
					$(LIBFT_DIR)/ft_itoa.c \
					$(LIBFT_DIR)/ft_memchr.c \
					$(LIBFT_DIR)/ft_memcmp.c \
					$(LIBFT_DIR)/ft_memcpy.c \
					$(LIBFT_DIR)/ft_memmove.c \
					$(LIBFT_DIR)/ft_memset.c \
					$(LIBFT_DIR)/ft_putchar_fd.c \
					$(LIBFT_DIR)/ft_putendl_fd.c \
					$(LIBFT_DIR)/ft_putnbr_fd.c \
					$(LIBFT_DIR)/ft_putstr_fd.c \
					$(LIBFT_DIR)/ft_split.c \
					$(LIBFT_DIR)/ft_strchr.c \
					$(LIBFT_DIR)/ft_strdup.c \
					$(LIBFT_DIR)/ft_striteri.c \
					$(LIBFT_DIR)/ft_strjoin.c \
					$(LIBFT_DIR)/ft_strlcat.c \
					$(LIBFT_DIR)/ft_strlcpy.c \
					$(LIBFT_DIR)/ft_strlen.c \
					$(LIBFT_DIR)/ft_strmapi.c \
					$(LIBFT_DIR)/ft_strncmp.c \
					$(LIBFT_DIR)/ft_strnstr.c \
					$(LIBFT_DIR)/ft_strrchr.c \
					$(LIBFT_DIR)/ft_strtrim.c \
					$(LIBFT_DIR)/ft_substr.c \
					$(LIBFT_DIR)/ft_tolower.c \
					$(LIBFT_DIR)/ft_toupper.c \
					$(LIBFT_DIR)/ft_isduplicate.c \

FT_PRINTF_FILES	=	$(PRINTF_DIR)/ft_eval_format.c \
					$(PRINTF_DIR)/ft_format_specifiers.c \
					$(PRINTF_DIR)/ft_format_specifiers_2.c \
					$(PRINTF_DIR)/ft_printf.c \
					$(PRINTF_DIR)/ft_printf_utils.c \

SRCS			=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS			=	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRCS))
DEPS			=	$(OBJS:.o=.d)

CC				=	gcc
RM				=	rm -rf
CFLAGS			=	-Wall -Werror -Wextra
IFLAGS			=	-I $(HDR_DIR)
DFLAGS			=	-MMD -MP -O1

.PHONY: all clean fclean re

all: $(NAME)

-include $(DEPS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
		@$(CC) $(CFLAGS) $(DFLAGS) -c -o $@ $< $(IFLAGS)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@mkdir -p $(OBJ_DIR)/$(LIBFT_DIR)
		@mkdir -p $(OBJ_DIR)/$(PRINTF_DIR)

$(NAME): $(OBJS)
		@echo "Assembling $(NAME)"
		@ar rc $(NAME) $(OBJS)
		@ranlib	$(NAME)
		@echo "${GREEN}✓${NOCOLOR}"

clean:
		@echo "${RED}Cleaning objects in libftprintf: ${NOCOLOR}"
		@$(RM) $(OBJ_DIR)
		@echo "${GREEN}✓${NOCOLOR}"

fclean: clean
		@echo "${RED}Cleaning all in libftprintf: ${NOCOLOR}"
		@$(RM) $(NAME)
		@echo "${GREEN}✓${NOCOLOR}"

re: fclean all