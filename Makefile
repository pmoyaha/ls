NAME = ft_ls.a
EXE = ft_ls
MAIN = main.c
LIB = libft/libft.a 
CC = gcc
FLAG = -Wall -Werror -Wextra
ARC = ar rc
SRC = ft_addnames.c\
	  ft_callnames.c\
	  ft_checkflag.c\
	  ft_cmp.c\
	  ft_del.c\
	  ft_err.c\
	  ft_impliment.c\
	  ft_joint.c\
	  ft_makepath.c\
	  ft_names.c\
	  ft_newnames.c\
	  ft_printlong.c\
	  ft_printnames.c\
	  ft_printsub.c\
	  ft_recurse.c\
	  ft_sort.c\
	  ft_sortpath.c\
	  ft_type.c

OBJ =	ft_addnames.o\
		ft_cmp.o\
		ft_impliment.o\
		ft_names.o\
		ft_printnames.o\
		ft_sort.o\
		ft_callnames.o\
		ft_del.o\
		ft_joint.o\
		ft_newnames.o\
		ft_printsub.o\
		ft_sortpath.o\
		ft_checkflag.o\
		ft_err.o\
		ft_makepath.o\
		ft_printlong.o\
		ft_recurse.o\
		ft_type.o

# all: $(NAME)

$(NAME):
		$(CC) $(FLAG) -c $(SRC)
		$(ARC) $(NAME) $(OBJ)
		ranlib $(NAME)
		$(CC) $(FLAG) -o $(EXE) $(MAIN) $(NAME) $(LIB)

all: $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME) $(EXE)

re: fclean all
