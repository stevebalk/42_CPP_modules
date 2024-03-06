NAME		= convert
CXX			= c++
CXXFLAGS	= -Werror -Wall -Wextra -Wpedantic -std=c++98
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

SRC_FILES	=	main \
				Convert \
				PrintHeader \

SRC				=	$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC_FILES)))
OBJ				=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJ_DIRS		=	$(addprefix $(OBJ_DIR), $(SRC_FILES))

#Debug 
ifeq ($(DEBUG), 1)
	OPTS = -g
endif

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(CXX) $(CXXFLAGS) $(OPTS) $(OBJ) -o $(NAME)
			@echo "$(GREEN)Created executable: $(WHITE)$(NAME)$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
			@mkdir -p $(OBJ_DIRS)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CXX) $(CXXFLAGS) $(OPTS) $(INCLUDE) -c $< -o $@

clean:
			@$(RM) -rf $(OBJ_DIR)
			@echo "$(BLUE)$(NAME) object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@echo "$(CYAN)$(NAME) executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for $(NAME)!$(DEF_COLOR)"

debug:		fclean
			@make DEBUG=1
			@echo "$(MAGENTA)Debug mode enabled for $(NAME)!$(DEF_COLOR)"

run: all clean
			./$(NAME) "DEBUG"

.PHONY:		all clean fclean re run debug