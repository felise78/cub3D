#include "cub3D.h"

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
		cub3D->map->map_width = 24;
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