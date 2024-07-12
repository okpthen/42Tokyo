/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:25:36 by dtakamat          #+#    #+#             */
/*   Updated: 2024/06/14 11:25:39 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

# include <fcntl.h>
# include "minirt.h"

# define COLER_ERROR -1
# define FOV_ERROR -1
# define VEC_ERROR DBL_MAX

t_environment	*set_cylinder(t_environment *env, char **arr);
t_environment	*set_plane(t_environment *env, char **arr);
t_environment	*set_sphere(t_environment *env, char **arr);
t_environment	*set_light(t_environment *env, char **arr);
t_environment	*set_camera(t_environment *env, char **arr);
t_environment	*set_ambient(t_environment *env, char **arr);
void			free_env(t_environment *env);
double			ft_atod(char	*str);
bool			check_double(char *str);
int				ato_color(char	*str);
int				ato_fov(char	*str);
void			free_arr(char **arr);
t_rgb			ato_rgb(char *str);
t_vec3			ato_vec3(char *str);
void			print_env(t_environment *env);
bool			check_01(double num);
bool			check_coler(t_rgb rgb);
bool			check_norm(t_vec3 vet3);
bool			check_fov(double num);
bool			check_vec3(t_vec3 vec3);
bool			check_vec(char *str);
bool			check_double_3ele(char **arr);

#endif