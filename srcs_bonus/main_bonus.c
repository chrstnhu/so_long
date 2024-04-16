/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:26:46 by chrhu             #+#    #+#             */
/*   Updated: 2024/02/09 14:26:48 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		init_value(&game);
		if (!check_extension(argv[1]))
			return (1);
		if (open_map(argv[1], &game))
		{
			init_game(&game);
			free_exit_prog(&game);
		}	
	}
	else
	{
		ft_printf("%sError\n", RED);
		ft_printf("Please insert 2 arguments [./so_long  ___.ber]%s\n", DEFAULT);
	}
	return (0);
}
