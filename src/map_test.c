#include "cub3D.h"

static void calculate_first_ray(t_cub *cub, float x, float y)
{
	if (y < 0)
	{
		while (cub->map->map_grid[cub->player->mapY + cub->player->dir.y][cub->player->mapX] != '1')
			y--;
	}
}

static void	set_dir_vector(t_cub *cub, char dir)
{
	if (dir == 'N')
	{
		//cub->player->ang = PI / 2; // 
		cub->player->dir.x = 0;
		cub->player->dir.y = -1;
	}	
	// else if (dir == 'W')
	// {
	// 	cub->player->dir.x = -1;
	// 	cub->player->dir.y = 0;
	// }	
	// else if (dir == 'E')
	// {
	// 	cub->player->dir.x = 1;
	// 	cub->player->dir.y = 0;
	// }	
	// else if (dir == 'S')
	// {
	// 	cub->player->dir.x = 0;
	// 	cub->player->dir.y = -1;
	// }	
	calculate_first_ray(cub, cub->player->pos.x, cub->player->pos.y);
}

static void    set_first_position(t_cub *cub3D)
{
    int x = 0;
    int y = 0;
    while (cub3D->map->map_grid[y])
    {
        x = 0;
        while(cub3D->map->map_grid[y][x])
        {
            if (cub3D->map->map_grid[y][x] == 'N' || cub3D->map->map_grid[y][x] == 'W' || cub3D->map->map_grid[y][x] == 'E' || cub3D->map->map_grid[y][x] == 'S')
            {
                cub3D->player->pos.x = x + 0.5;
                cub3D->player->pos.y = y + 0.5;
                cub3D->player->mapX = (int)cub3D->player->pos.x;
                cub3D->player->mapY = (int)cub3D->player->pos.y;
				set_dir_vector(cub3D, cub3D->map->map_grid[y][x]);
				//cub3D->player->fov = PI / 4; // a modifier 
				//cub3D->player->ang = 0.0f;
			   return ;
            }
            x++;
        }
        y++;
    }
}

int init_map_test(t_cub *cub3D)
{
	const char *map[] = {"111111111111111111111111", "100000000000000000000001", "100N00000000000000000001", "100000000000000000000001", "100000111110000101010001", "100000100010000000000001", "100000100010000100010001", "100000100010000000000001", "100000110110000101010001", "100000000000000000000001", "100000000000000000000001", "111111111111111111111111", NULL};
	
	int i = 0;
	int j;
	cub3D->map->map_grid = malloc(13 * sizeof(char*));
	if (!cub3D->map->map_grid)
		return(printf("erreur malloc\n"), 0);
	cub3D->map->map_width = 12;
	i = 0;
	while (map[i] && i < 12)
	{
		j = 0;
		cub3D->map->map_grid[i] = malloc(25);
		cub3D->map->map_len = 24;
		if (!cub3D->map->map_grid[i])
			return(printf("erreur malloc n* %d\n", i), 0);
		while (map[i][j])
		{
			cub3D->map->map_grid[i][j] = map[i][j];
			j++;	
		}
		cub3D->map->map_grid[i][j] = '\0';
		i++;
	}
	cub3D->map->map_grid[i] = NULL;
	set_first_position(cub3D);
	return (1);
}