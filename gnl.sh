# make -C libft/ fclean && make -C libft/
gcc -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
gcc -Wall -Wextra -Werror -Ilibft/includes -o main.o -c gnl_main.c
gcc -o test_gnl -fsanitize=address main.o get_next_line.o -Ilibft/includes/ -Llibft/ -lft #-fsanitize=address
./test_gnl 10 3
