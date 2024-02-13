NAME		= megaphone
CC			= c++
CFLAGS		= -Werror -Wall -Wextra -Wpedantic -std=c++98 -fsanitize=address
RM			= rm
SRC_DIR		= src/
OBJ_DIR		= obj/

INCLUDE		= -I include

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRC_FILES	=	megaphone \

SRC				=	$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC_FILES)))
OBJ				=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJ_DIRS		=	$(addprefix $(OBJ_DIR), $(SRC_FILES))

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
			@mkdir -p $(OBJ_DIRS)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
			@$(RM) -rf $(OBJ_DIR)
			@echo "$(BLUE)$(NAME) object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@echo "$(CYAN)$(NAME) executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for $(NAME)!$(DEF_COLOR)"

run: all clean
			./$(NAME)

.PHONY:		all clean fclean re run