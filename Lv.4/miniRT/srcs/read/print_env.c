/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:37:06 by dtakamat          #+#    #+#             */
/*   Updated: 2024/06/14 12:37:15 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/read.h"

// void	print_color(t_rgb color)
// {
// 	printf("color b=%d g=%d r=%d",color.b, color.g, color.r);
// }
// void	print_vec3(t_vec3 vec)
// {
// 	printf("x=%f y=%f z=%f", vec.x, vec.y, vec.z);
// }

// void	print_amb(t_ambient *amb)
// {
// 	printf("ambient ");
// 	printf("raito=%f ", amb->ratio);
// 	print_color(amb->color);
// 	printf("\n");
// }
// void	print_light(t_light *light)
// {
// 	printf("light ");
// 	printf("pos ");
// 	print_vec3(light->pos);
// 	printf(" raito=%f ", light->ratio);
// 	print_color(light->color);
// 	printf("\n");
// 	if (light->next)
// 		print_light(light->next);
// }

// void	print_cam(t_camera *cam)
// {
// 	printf("cam ");
// 	printf("pos ");
// 	print_vec3(cam->pos);
// 	printf(" ori ");
// 	print_vec3(cam->ori);
// 	printf(" fov=%d\n",cam->fov);
// }

// void	print_sphere(t_sphere *sp)
// {
// 	printf("sp center ");
// 	print_vec3(sp->center);
// 	printf(" diameter=%f ", sp->r);
// 	print_color(sp->color);
// 	printf("\n");
// }

// void	print_plane(t_plane *pl)
// {
// 	printf("pl point ");
// 	print_vec3(pl->point);
// 	printf(" norm ");
// 	print_vec3(pl->norm);
// 	printf(" ");
// 	print_color(pl->color);
// 	printf("\n");
// }

// void	print_cylinder(t_cylinder *cy)
// {
// 	printf("cy center ");
// 	print_vec3(cy->center);
// 	printf(" norm ");
// 	print_vec3(cy->axis);
// 	printf(" diameter=%f hight=%f ",cy->diameter, cy->height);
// 	print_color(cy->color);
// 	printf("\n");
// }

// void	print_obj(t_obj *obj)
// {
// 	if (obj->type == 's')
// 		print_sphere(obj->obj);
// 	else if (obj->type == 'p')
// 		print_plane(obj->obj);
// 	else if (obj->type == 'c')
// 		print_cylinder(obj->obj);
// 	if (obj->next)
// 		print_obj(obj->next);
// }

// void	print_env(t_environment *env)
// {
// 	printf("\n-------env--------\n");
// 	print_amb(env->ambient);
// 	print_light(env->light);
// 	print_cam(env->cam);
// 	print_obj(env->obj);
// }