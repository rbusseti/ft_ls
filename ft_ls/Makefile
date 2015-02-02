NAME = ft_ls

SRC = 

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o:%.c
	$(CC) $(FLAGS) -c -o $@ $^ -I includes/