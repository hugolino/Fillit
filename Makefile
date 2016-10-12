NAME = fillit

DIR_INC = ./includes/

DIR_SRC = ./srcs/

SRC_C = main.c \
	ft_bufcpy.c \
	ft_line_s_z.c \
	ft_pieces_l.c \
	ft_z_t.c \
	ft_check_valid.c \
	ft_map_creator.c \
	ft_pieces_revlsq.c \
	ft_errors.c \
	ft_parser.c \
	ft_manipulate_list.c \
	ft_trim.c

SRCS = $(addprefix $(DIR_SRC), $(SRC_C))

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT = ./Libft

LIB = -L$(LIBFT) -lft

all:	$(NAME)

$(NAME):
	@make -C $(LIBFT)
	@echo "Creating libft.a" "  \033[32m"OK"\033[00m"
	@$(CC) $(FLAGS) -o $(NAME) $(SRCS) -I $(DIR_INC) $(LIB)
	@echo "Compiling" ["Fillit"] "\033[32m"SUCCESS"\033[00m"
clean:
	@make clean -C $(LIBFT)
	@echo "Cleaning .O Libft" " \033[32m"OK"\033[00m"

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)
	@echo "Deleting fillit" "   \033[32m"OK"\033[00m"

re: fclean all
