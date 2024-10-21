# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 14:29:53 by mikferna          #+#    #+#              #
#    Updated: 2024/10/07 14:40:33 by mikferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
DOCKER_COMPOSE := docker-compose

# Comandos Makefile
all: build run

# Construir la imagen usando docker-compose
build:
	$(DOCKER_COMPOSE) build

# Ejecutar el contenedor usando docker-compose
run: stop
	$(DOCKER_COMPOSE) up -d

# Detener y eliminar los contenedores
stop:
	$(DOCKER_COMPOSE) down

# Limpiar: eliminar las imágenes creadas
clean: stop
	$(DOCKER_COMPOSE) down --rmi all
