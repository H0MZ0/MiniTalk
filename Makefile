CC = cc
CFLAGS = -Wall -Wextra -Werror

CLN = client.c ft_atoi.c
SRV = server.c ft_putnbr.c

COBJ = $(CLN:.c=.o)
SOBJ = $(SRV:.c=.o)

NAME1 = client
NAME2 = server

all : $(NAME1)

$(NAME1): $(COBJ) $(NAME2)
	$(CC) $(COBJ) -o $(NAME1)

$(NAME2): $(SOBJ)
	$(CC) $(SOBJ) -o $(NAME2)

clean : 
	@rm $(COBJ) $(SOBJ)
fclean : clean
	@rm $(NAME1) $(NAME2)

re: fclean all

# .PHONY all clean fclean re
