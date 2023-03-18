# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imahri <imahri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 13:53:28 by imahri            #+#    #+#              #
#    Updated: 2023/01/18 19:40:33 by imahri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################### VAR ####################

NAME = minitalk
CC = cc
HEADER = minitalk.h
FLAGS = -Wall -Wextra -Werror
# MANDATORY
SSRC =	server.c
CSRC =	client.c
# BONUS
BSSRC =	server_bonus.c
BCSRC =	client_bonus.c
# MI
SRC = minitalk_utils.c

################### COLOR ###################

GREEN = \033[0;32m
RED = \033[0;31m
CEND = \033[0m

#################### RULL ###################

all: ${NAME}

${NAME}: server client

server : ${SSRC} ${HEADER}
	@${CC} ${FLAGS} minitalk_utils.c $< -o $@
	@echo "$(GREEN)Everyone say welcome to Server 🤩$(CEND)"

client : ${CSRC} ${HEADER}
	@${CC} ${FLAGS} minitalk_utils.c $< -o $@
	@echo "$(GREEN)Everyone say welcome to Client 🤩$(CEND)"

bonus : ${HEADER} server_bonus client_bonus

server_bonus : ${BSSRC} ${HEADER}
	@${CC} ${FLAGS} minitalk_utils.c $< -o $@
	@echo "$(GREEN)Everyone say welcome to Server_bonus 🤩$(CEND)"

client_bonus : ${BCSRC} ${HEADER}
	@${CC} ${FLAGS} minitalk_utils.c $< -o $@
	@echo "$(GREEN)Everyone say welcome to client_bonus 🤩$(CEND)"

clean :
	@rm -rf server client server_bonus client_bonus
	@echo "$(RED)See you soon 🤗$(CEND)"

re: fclean all

fclean : clean

.PHONY : clean