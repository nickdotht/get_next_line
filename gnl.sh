# make -C libft/ fclean && make -C libft/
clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
clang -Wall -Wextra -Werror -Ilibft/includes -o main.o -c main.c
clang -o test_gnl -fsanitize=address main.o get_next_line.o -Ilibft/includes/ -Llibft/ -lft #-fsanitize=address
./test_gnl m83.txt
