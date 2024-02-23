SRC = main.c printscore.c tests.c
OBJS = $(SRC:.c=.o)
C = gcc
FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
NAME = play
RM = rm -rf

all: draw $(NAME)
	@$(RM) $(OBJS)
# elimina .o

.SILENT: $(OBJS)

$(NAME): $(OBJS)
	@gcc $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean:
	@$(RM) $(NAME) $(OBJS)

re:	fclean all

draw: 
	@echo "\033[0;32m⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⣶⣆⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣤⣤⣤⣤⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⣠⣼⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⣠⣾⡟⠁⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠸⠛⠀⠀⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠻⣿⣧⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⡿⢿⣿⣿⣿⣿⣷⠀⠀⠀⠹⣿⣷⣀⣀⣀⠀⠀"
	@echo "⠀⠀⠀⣀⣤⣶⣾⣿⣿⣿⠿⠋⠀⠀⠸⣿⣿⣷⠀⠀⠀⠀⠀⠈⠙⠿⠿⠿⠀⠀"
	@echo "⢶⣿⣿⠿⣿⣿⡿⠛⠉⠀⠀⠀⠀⠀⠀⢿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠈⣿⡏⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⠀"
	@echo "⠀⠻⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⡁⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣷"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠿⣿⣿⣦⡄⠀⠀⠀⠀⠀⠻⢿⠿⠏\033[0m"
	@echo
	@echo
	@echo "\033[0;31m     LET'S PLAY BOWLING!\033[0m"
	@echo "Created by Marina Higueras (marinitx)"
	@echo
	@echo "\033[0;94mEnter './play' to start playing.\033[0m"
	@echo


.PHONY:	all clean fclean re 

