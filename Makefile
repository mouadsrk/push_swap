
NAME = push_swap

NAMEAR = push_swap.a

NAMEB = checker

NAMEBAR = checker.a

NAMELIB = libft.a

FILES = basic_sort.c parse_utils.c  parse.c sort_100.c sort_utils.c sort_utils2.c stack_b_utils.c stack_b_utils2.c stack_operation.c stack_operation2.c

BONUSRC = parse_utils.c parse.c   stack_operation.c stack_operation2.c

CC = cc
FLG = -Wall -Wextra -Werror 
AR = ar r
RM = rm -f

OBJ = $(FILES:.c=.o)

BBJ= $(BONUSRC:.c=.o)
		
all : $(NAME)

$(NAME) : $(NAMEAR) $(NAMELIB) push_swap.c
	$(CC) $(FLG) -fsanitize=address push_swap.c $(NAMEAR)  $(NAMELIB) -o $(NAME)

$(NAMEAR) : $(OBJ)
	$(AR)  $(NAMEAR)  $(OBJ)

$(NAMELIB) :
	cd libft && make
	cd libft && make bonus

bonus : $(NAMEB) 

$(NAMEB) : $(NAMEBAR) $(NAMELIB) checker.c 
	$(CC) $(FLG) checker.c $(NAMEBAR)  $(NAMELIB) -o $(NAMEB)

$(NAMEBAR) : $(BBJ)
	$(AR)  $(NAMEBAR)  $(BBJ)

%.o :%.c 
	$(CC) $(FLG)  -c $<

clean :
	$(RM) $(OBJ)  $(BBJ)

fclean : clean
	$(RM) $(NAME) $(BBJ) $(NAMELIB) $(NAMEAR) $(NAMEBAR) $(NAMEB)

re : clean all bonus

.PHONY: clean  fclean bonus




