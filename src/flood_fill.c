/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:35:51 by ashirzad          #+#    #+#             */
/*   Updated: 2024/04/04 17:31:04 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int		valid_path(t_data *data);
char	**copy_map(t_data *data);
void	flood_fill(char **map, int y, int x);
int		check_map(char **ptr);
void	free_ptr(char **ptr);

int	valid_path(t_data *data)
{
	char	**ptr;

	ptr = copy_map(data);
	flood_fill(ptr, data->map.p_y, data->map.p_x);
	if (!check_map(ptr))
	{
		free_ptr(ptr);
		return (0);
	}
	free_ptr(ptr);
	return (1);
}

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'f')
		return ;
	map[y][x] = 'f';
	flood_fill(map, y, x + 1);
	flood_fill(map, y, x - 1);
	flood_fill(map, y - 1, x);
	flood_fill(map, y + 1, x);
}

char	**copy_map(t_data *data)
{
	char	**str;
	int		i;

	i = 0;
	str = malloc(sizeof(char *) * ((data->map.height / SIZE_IMG) + 1));
	while (data->map.line[i])
	{
		str[i] = ft_strdup(data->map.line[i]);
		i++;
	}
	str[i] = NULL;
	return (str);
}

int	check_map(char **ptr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ptr[i])
	{
		j = 0;
		while (ptr[i][j])
		{
			if (ptr[i][j] == 'E' || ptr[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
