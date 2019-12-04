NAME = pathfinder

INCI = ./inc/pathfinder.h ./inc/libmx.h
INC = ./pathfinder.h ./libmx.h

SRC = ./main.c \
./mx_printerr.c \
./mx_first_line_not_valid.c \
./mx_line_not_valid.c \
./mx_not_exist_or_empty.c \
./mx_invalid_number.c \
./mx_new_list.c \
./mx_push_list.c \
./mx_arr_to_list.c \

SRCS = ./src/main.c \
./src/mx_printerr.c \
./src/mx_first_line_not_valid.c \
./src/mx_line_not_valid.c \
./src/mx_not_exist_or_empty.c \
./src/mx_invalid_number.c \
./src/mx_new_list.c \
./src/mx_push_list.c \
./src/mx_arr_to_list.c \

POBJ = ./main.o \
./mx_printerr.o \
./mx_first_line_not_valid.o \
./mx_line_not_valid.o \
./mx_not_exist_or_empty.o \
./mx_invalid_number.o \
./mx_new_list.o \
./mx_push_list.o \
./mx_arr_to_list.o \

LOBJ = ./mx_printchar.o \
./mx_print_unicode.o \
./mx_printstr.o \
./mx_print_strarr.o \
./mx_printint.o \
./mx_pow.o \
./mx_sqrt.o \
./mx_nbr_to_hex.o \
./mx_hex_to_nbr.o \
./mx_itoa.o \
./mx_foreach.o \
./mx_binary_search.o \
./mx_bubble_sort.o \
./mx_quicksort.o \
\
./mx_strlen.o \
./mx_swap_char.o \
./mx_str_reverse.o \
./mx_strdel.o \
./mx_del_strarr.o \
./mx_get_char_index.o \
./mx_strdup.o \
./mx_strndup.o \
./mx_strcpy.o \
./mx_strncpy.o \
./mx_strcmp.o \
./mx_strcat.o \
./mx_strstr.o \
./mx_get_substr_index.o \
./mx_count_substr.o \
./mx_count_words.o \
./mx_strnew.o \
./mx_strtrim.o \
./mx_del_extra_spaces.o \
./mx_strsplit.o \
./mx_strjoin.o \
./mx_file_to_str.o \
./mx_read_line.o \
./mx_replace_substr.o \
\
./mx_memset.o \
./mx_memcpy.o \
./mx_memccpy.o \
./mx_memcmp.o \
./mx_memchr.o \
./mx_memrchr.o \
./mx_memmem.o \
./mx_memmove.o \
./mx_realloc.o \
\
./mx_create_node.o \
./mx_pop_back.o \
./mx_pop_front.o \
./mx_push_back.o \
./mx_push_front.o \
./mx_list_size.o \
./mx_sort_list.o \
\
./mx_isspace.o \
./mx_isdigit.o \
./mx_isalpha.o \
./mx_swap_str.o \
./mx_strlen_my.o \

LIBL = ./libmx/libmx.a
LIB = ./libmx.a

CFLGS = -std=c11 -Wall -Wextra -Wpedantic -Werror 

all: install uninstall launch

launch: 
	@./pathfinder i.txt | cat -e

install:
	@cd libmx && make -f Makefile install
	@cp $(INCI) $(SRCS) $(LIBL) .
	@ar x $(LIB)
	@clang $(CFLGS) -c $(SRC) -I $(INC)
	@clang $(CFLGS) -o $(NAME) $(LOBJ) $(POBJ)
	@mkdir  obj
	@mv $(POBJ) $(LOBJ) ./obj

uninstall:
	@cd libmx && make -f Makefile uninstall
	@rm -rf $(SRC) $(INC)
	@rm -rf ./obj libmx.a __.SYMDEF\ SORTED libmx.h.gch

clean: uninstall
	@cd libmx && make -f Makefile clean
	@rm -rf $(NAME)

reinstall: clean all
