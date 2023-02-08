/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_terminal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:08:49 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/02/02 14:38:50 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include <stdio.h>

void	terminal_prompt(void)
{
	const char	*cyan = "\033[0;96m";

	printf("%s╔═══════════════════════════════════════════╗\n", cyan);
	printf("║          miniRT remote controler          ║\n");
	printf("╠═══════╦═══════════════════════════════════╣\n");
	printf("║ PRESS ║              CONTROL              ║\n");
	printf("╠═══════╬═══════════════════════════════════╣\n");
	printf("║   1   ║              CAMERA               ║\n");
	printf("╠═══════╬═══════════════════════════════════╣\n");
	printf("║   2   ║               LIGHT               ║\n");
	printf("╠═══════╬═══════════════════════════════════╣\n");
	printf("║   3   ║              OBJECT               ║\n");
	printf("╚═══════╩═══════════════════════════════════╝\n");
}

void	remote_controler(char *input)
{
	const char	*orange = "\033[38;5;208m";

	printf("%s╔═══════════════════════════════════════════╗\n", orange);
	printf("║          %s remote controler          ║\n", input);
	printf("╠═══════╦═══════════════════════════════════╣\n");
	printf("║ PRESS ║              CONTROL              ║\n");
	printf("╠═══════╬═══════════════════════════════════╣\n");
	printf("║   Q   ║            DOWN X AXIS            ║\n");
	printf("╠═══════╬═══════════════════════════════════╣\n");
	printf("║   W   ║             UP X AXIS             ║\n");
	printf("╠═══════╬═══════════════════════════════════╣\n");
	printf("║   A   ║            DOWN Y AXIS            ║\n");
	printf("╠═══════╬═══════════════════════════════════╣\n");
	printf("║   S   ║             UP Y AXIS             ║\n");
	printf("╠═══════╬═══════════════════════════════════╣\n");
	printf("║   Z   ║            DOWN Z AXIS            ║\n");
	printf("╠═══════╬═══════════════════════════════════╣\n");
	printf("║   X   ║             UP Z AXIS             ║\n");
	printf("╚═══════╩═══════════════════════════════════╝\n");
}

void	light_selector(void)
{
	const char	*green = "\033[0;92m";

	printf("%s╔═══════════════════════════════════════════╗\n", green);
	printf("║              LIGHT : TURN ON              ║\n");
	printf("╚═══════════════════════════════════════════╝\n");
	printf("╔═══════════════════════════════════════════╗\n");
	printf("║              LIGHT SELECTOR               ║\n");
	printf("╠══════════════╦══════════════╦═════════════╣\n");
	printf("║     BACK     ║     NEXT     ║     OKAY    ║\n");
	printf("╠══════════════╬══════════════╬═════════════╣\n");
	printf("║       B      ║       N      ║      O      ║\n");
	printf("╚══════════════╩══════════════╩═════════════╝\n");
	printf("To exit the light controler, PRESS the 2 key\n");
}

void	obj_selector(void)
{
	const char	*magenta = "\033[0;95m";

	printf("%s╔═══════════════════════════════════════════╗\n", magenta);
	printf("║              OBJECT : TURN ON             ║\n");
	printf("╚═══════════════════════════════════════════╝\n");
	printf("╔═══════════════════════════════════════════╗\n");
	printf("║              OBJECT SELECTOR              ║\n");
	printf("╠══════════════╦══════════════╦═════════════╣\n");
	printf("║     BACK     ║     NEXT     ║     OKAY    ║\n");
	printf("╠══════════════╬══════════════╬═════════════╣\n");
	printf("║       B      ║       N      ║      O      ║\n");
	printf("╚══════════════╩══════════════╩═════════════╝\n");
	printf("To exit the object controler, PRESS the 3 key\n");
}

void	print_turn_off(char *input)
{
	const char	*yellow = "\033[0;93m";

	printf("%s╔═══════════════════════════════════════════╗\n", yellow);
	printf("║              %s : TURN OFF            ║\n", input);
	printf("╚═══════════════════════════════════════════╝\n");
}
