/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soahn <soahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:28:18 by soahn             #+#    #+#             */
/*   Updated: 2022/03/26 03:56:49 by soahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*wrap_xpm_to_img(t_game *game, char *filename)
{
	char	*path;
	void	*img_ptr;
	int		width;
	int		height;

	path = ft_strjoin(ASSET_PATH, filename);
	img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, path, &width, &height); // Q. xpm으로 꼭 바꿔서 쓰는 이유? A. 안그러면 오류 난다고 슬랙에서 얼핏 봄;
	free(path);
	if (!img_ptr)
		exit_msg("xpm to image fail\n");
	return (img_ptr);
}

void	put_img(t_game *game, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img_ptr, x, y);
}