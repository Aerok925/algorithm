MAIN_NAME = "push_swap cheker"

NAME = push_swap

NAME_BONUS = checker

SRCS =	main/create_stack.c	main/free_stack.c	main/ft_strlen.c	main/main.c	main/vizualization.c	main/cheking_argument.c \
	main/sa.c main/push_stack.c main/reverse_up.c main/flags_zero.c main/found_min.c main/is_sorted.c main/sorted_three.c \
	main/global_sorted.c main/help_for_index.c main/define_location.c main/found_min_number.c \
	main/found_max_min.c main/found_nbr_command.c main/global_sorted_begin.c main/sorted_five.c \
	main/ft_split.c main/ft_strlcpy.c

SRCS_BONUS = bonus/main.c bonus/cheking_argument.c bonus/create_stack.c bonus/helper_ft.c bonus/branch_ft.c \
	bonus/sa.c bonus/is_sorted.c bonus/push_stack.c bonus/reverse_up.c

CC = gcc 

FLAGS = -Wall -Wextra -Werror

INCLUDES = main/push_swap.h

INCLUDES_BONUS = bonus/checker.h

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

OBJS = ${SRCS:.c=.o}

.PHONY: all clean fclean re clean_main fclean_main clean_checker fclean_checker

.c.o:
	$(CC) -c ${FLAGS} $*.c -o $*.o 

$(MAIN_NAME): ${NAME} ${NAME_BONUS}

${NAME} : $(SRCS) $(OBJS) $(INCLUDES)
	$(CC) ${FLAGS} -I$(INCLUDES) -o $(NAME) $(OBJS)

${NAME_BONUS} : $(SRCS_BONUS) $(OBJS_BONUS) $(INCLUDES_BONUS)
	$(CC) ${FLAGS} -I$(INCLUDES_BONUS) -o $(NAME_BONUS) $(OBJS_BONUS)

all : $(NAME)

clean : clean_main clean_checker

clean_main : 
	rm -rf $(OBJS)

clean_checker : 
	rm -rf $(OBJS_BONUS)

fclean_main : clean_main
	rm -rf $(NAME)

fclean_checker : clean_checker
	rm -rf $(NAME_BONUS)

fclean : clean fclean_main fclean_checker

re : fclean all

