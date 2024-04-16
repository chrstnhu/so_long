/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:26:46 by chrhu             #+#    #+#             */
/*   Updated: 2024/02/09 14:26:48 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	check_extension(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (len < 5)
	{
		ft_printf("%sError\n", RED);
		ft_printf("Please enter a valid filename%s\n", DEFAULT);
		return (0);
	}
	else if (ft_strstr(argv + len - 4, ".ber") == 0)
	{
		ft_printf("%sError\nPlease enter a filename ", RED);
		ft_printf("with extension .ber %s\n", DEFAULT);
		return (0);
	}
	return (1);
}
