### VARIABLES ###

NAMES = server
NAMEC = client
FT_PRINTF = libftprintf.a
DIR = src/
FILE_S = server.c
FILE_C = client.c
SRC_SERVER = $(addprefix $(DIR), $(FILE_S))
SRC_CLIENT = $(addprefix $(DIR), $(FILE_C))
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar rcs
INCLUDE = -I include

OBJ_S = $(SRC_SERVER:.c=.o)
OBJ_C = $(SRC_CLIENT:.c=.o)

### COLORS ###

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

### FUNCTIONS ###

all: $(NAMES) $(NAMEC)

$(NAMES): start $(OBJ_S)
	@make -C ft_printf
	$(CC) $(CFLAGS) $(OBJ_S) $(INCLUDE) ft_printf/$(FT_PRINTF) -o $(NAMES)

$(NAMEC): $(OBJ_C)
	@make -C ft_printf
	$(CC) $(CFLAGS) $(OBJ_C) $(INCLUDE) ft_printf/$(FT_PRINTF) -o $(NAMEC)

clean: 
	@echo "$(CYAN)Oh no, a lot of tr4sh!1!$(DEF_COLOR)"
	@sleep 1
	@make clean -C ft_printf
	$(RM) $(OBJ_C)
	$(RM) $(OBJ_S)
	@echo "$(RED)All objects removed!$(DEF_COLOR)"

fclean: clean
	@make fclean -C ft_printf
	$(RM) $(NAMES)
	$(RM) $(NAMEC)
	@echo "$(RED)And also executables!$(DEF_COLOR)"

re: fclean all

start: 
	@echo "$(YELLOW)Ok, let's compile!$(DEF_COLOR)"
	@sleep 1

.PHONY: all clean fclean re
