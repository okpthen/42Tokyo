/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:25:17 by dtakamat          #+#    #+#             */
/*   Updated: 2024/06/14 11:26:55 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	handle_keypress(int keycode, void *param)
{
	if (keycode == 53)
	{
		mlx_destroy_image(((t_mlx_data *)param)->mlx,
			((t_mlx_data *)param)->img.img);
		mlx_destroy_window(((t_mlx_data *)param)->mlx,
			((t_mlx_data *)param)->mlx_win);
		free_env(((t_mlx_data *)param)->env);
	}
	exit(0);
}

int	handle_close(void *param)
{
	mlx_destroy_image(((t_mlx_data *)param)->mlx,
		((t_mlx_data *)param)->img.img);
	mlx_destroy_window(((t_mlx_data *)param)->mlx,
		((t_mlx_data *)param)->mlx_win);
	free_env(((t_mlx_data *)param)->env);
	exit(0);
}

void	*ft_mlx_struct_init(void **mlx, t_data_img *img)
{
	void	*mlx_win;

	*mlx = mlx_init();
	if (*mlx == NULL)
		return (NULL);
	mlx_win = mlx_new_window(*mlx, (int)WIDTH, (int)HEIGHT, "miniRT");
	if (mlx_win == NULL)
		return (NULL);
	img->img = mlx_new_image(*mlx, (int)WIDTH, (int)HEIGHT);
	if (img->img == NULL)
		return (NULL);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (img->addr == NULL)
		return (NULL);
	return (mlx_win);
}

void	my_mlx_pixel_put(t_data_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
