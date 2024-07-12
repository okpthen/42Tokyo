/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:25:12 by dtakamat          #+#    #+#             */
/*   Updated: 2024/06/14 13:42:23 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	loop_something(t_mlx_data *data, t_environment *env);

int	main(int ac, char **av)
{
	t_environment	*env;
	t_mlx_data		mlx_data;

	if (ac != 2)
		return (write(2, "Error\ninput correct arg\n", 25), 1);
	env = make_env(av[1]);
	if (!env)
		return (write(2, "Error\ninput correct file\n", 26), 1);
	mlx_data.mlx_win = ft_mlx_struct_init(&(mlx_data.mlx), &(mlx_data.img));
	mlx_hook(mlx_data.mlx_win, 2, 1L << 0, handle_keypress, (void *)&mlx_data);
	mlx_hook(mlx_data.mlx_win, 17, 1L << 17, handle_close, (void *)&mlx_data);
	mlx_data.env = env;
	loop_something(&mlx_data, env);
	mlx_loop(mlx_data.mlx);
	free_env(env);
	exit(0);
}

void	loop_something(t_mlx_data *data, t_environment *env)
{
	double		fov_d;
	t_sqmatrix3	rotation_matrix;
	int			ij[2];
	t_vec3		ray;

	fov_d = (double)env->cam->fov * M_PI / 180.0f / 2;
	rotation_matrix = vec3_get_rotation_matrix(env);
	ij[0] = 0;
	while (ij[0] < HEIGHT)
	{
		ij[1] = 0;
		while (ij[1] < WIDTH)
		{
			ray.x = 2 * tan(fov_d * (double)(ij[1] - WIDTH / 2)
					/ (double)WIDTH);
			ray.y = 2 * tan(fov_d * (double)(ij[0] - HEIGHT / 2)
					/ (double)WIDTH);
			ray.z = 1;
			my_mlx_pixel_put(&data->img, ij[1], HEIGHT - 1 - ij[0],
				get_color4ray(rotate_matrix(rotation_matrix, ray), env));
			ij[1]++;
		}
		ij[0]++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
}
