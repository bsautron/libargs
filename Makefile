# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsautron <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/03 19:00:18 by bsautron          #+#    #+#              #
#    Updated: 2016/04/03 19:25:16 by bsautron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libargs
DEPENDENCIES = libft \
								liblist \
								libhash \
								libhtab
SOURCES = add_option.c \
					parse_options.c \
					get_option.c \
					show_args.c \
					init_options.c \
					option_is_set.c \
					show_usage.c \
					print_option_line.c \
					add_desc.c \
					add_usage.c \
					treat_options.c \
					get_values_option.c

SOURCES_FOLDER = sources

CC = gcc
LIB_NAME = $(NAME).a
CFLAGS = -Wextra -Wall -Werror
TEST_FORDER = test
INCLUDES_FOLDER = includes
OBJECTS_FOLDER = ../.objects/$(NAME)
INCLUDES = $(NAME).h

SOURCES_DEPENDENCIES = $(foreach dep,$(DEPENDENCIES), ../$(dep)/$(dep).a)
LIBRARIES = $(foreach dep, $(DEPENDENCIES), -L../$(dep)/ -$(subst lib,l,$(dep)))
INCLUDES_LIBRARIES = $(foreach dep,$(DEPENDENCIES),-I ../$(dep)/includes)
HEADERS_LIBRARIES = $(foreach dep,$(DEPENDENCIES),../$(dep)/includes/$(dep).h)
MAKE_LIBRARIES = $(foreach dep,$(DEPENDENCIES),make -C ../$(dep);)
REBUILD_LIBRARIES = $(foreach dep,$(DEPENDENCIES),make re -C ../$(dep);)

OBJECTS = $(SOURCES:%.c=%.o)

MAIN = main.c
MAIN_OBJECT = $(MAIN:%.c=%.o)

.PHONY: main

all: init $(LIB_NAME)

main: all
	$(CC) $(MAIN) -I $(INCLUDES_FOLDER) $(INCLUDES_LIBRARIES) $(LIB_NAME) $(SOURCES_DEPENDENCIES)

ifdef DEPENDENCIES
init: $(SOURCES_DEPENDENCIES)
	$(MAKE_LIBRARIES)
	@mkdir -p $(OBJECTS_FOLDER)/$(SOURCES_FOLDER)

$(addprefix $(OBJECTS_FOLDER)/$(SOURCES_FOLDER)/, %.o): $(SOURCES_FOLDER)/%.c $(addprefix $(INCLUDES_FOLDER)/, $(INCLUDES))
	$(CC) $(CFLAGS) -I $(INCLUDES_FOLDER) $(INCLUDES_LIBRARIES) -o $@ -c $<
endif

ifndef DEPENDENCIES
init:
	@mkdir -p $(OBJECTS_FOLDER)/$(SOURCES_FOLDER)

$(addprefix $(OBJECTS_FOLDER)/$(SOURCES_FOLDER)/, %.o): $(SOURCES_FOLDER)/%.c $(addprefix $(INCLUDES_FOLDER)/, $(INCLUDES))
	$(CC) $(CFLAGS) -I $(INCLUDES_FOLDER) -o $@ -c $<
endif

$(MAIN_OBJECT): $(MAIN)
	$(CC) $(CFLAGS) -I $(INCLUDES_FOLDER) -o $(MAIN_OBJECT) -c $(MAIN)

$(LIB_NAME): $(addprefix $(OBJECTS_FOLDER)/$(SOURCES_FOLDER)/, $(OBJECTS))
	ar rc $(LIB_NAME) $(addprefix $(OBJECTS_FOLDER)/$(SOURCES_FOLDER)/, $(OBJECTS))
	ranlib $(LIB_NAME)

clean:
	rm -f $(addprefix $(OBJECTS_FOLDER)/$(SOURCES_FOLDER)/, $(OBJECTS))
	rm -f $(MAIN_OBJECT)
	rm -rf $(OBJECTS_FOLDER)

fclean: clean
	rm -f $(LIB_NAME)

re: fclean all
