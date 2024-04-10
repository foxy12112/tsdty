/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 07:44:08 by ashirzad          #+#    #+#             */
/*   Updated: 2024/04/09 12:53:25 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int args, char **argv)
{
	t_data	data;

	if (args != 2)
	{
		ft_printf("Error\n./so_long ./maps/<map_name>\n");
		return (1);
	}
	map_init(&data, argv[1]);
	if (!valid_map(&data))
		return (1);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data.mlx = mlx_init(data.map.width, data.map.height, "SO_LONG 42", 1);
	if (!data.mlx)
	{
		free_ptr(data.map.line);
		return (1);
	}
	ft_printf("GAME START!\n");
	image_struct(&data);
	display_map(&data);
	mlx_key_hook(data.mlx, key_hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	free_ptr(data.map.line);
	return (0);
}
