cmake_minimum_required(VERSION 3.13)
project(Fillit C)

set(CMAKE_C_STANDARD 99)

add_executable(Fillit main.c checker.c error.c libft/ft_putstr.c libft/ft_putchar.c square.c libft/ft_memset.c)
