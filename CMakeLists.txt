cmake_minimum_required(VERSION 3.13)
project(Fillit C)

set(CMAKE_C_STANDARD 99)

add_executable(Fillit main.c libft/ft_strdel.c checker.c error.c libft/ft_putstr.c libft/ft_putchar.c root.c
        libft/ft_memset.c ./libft/ft_memalloc.c libft/ft_strnew.c libft/ft_bzero.c list_figurs.c create_area.c libft/ft_memset.c free_lst.c)
