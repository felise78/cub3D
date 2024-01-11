#include "cub3D.h"

int init_map_test(t_cub *cub3D)
{
	const char *map[] = {"111111111111111111111111", "100000000000000000000001", "100N00000000000000000001", "100000000000000000000001", "100000111110000101010001", "100000100010000000000001", "100000100010000100010001", "100000100010000000000001", "100000110110000101010001", "100000000000000000000001", "100000000000000000000001", "111111111111111111111111", NULL};
	
	int i = 0;
	int j;
	cub3D->map = malloc(13 * sizeof(char*));
	if (!cub3D->map)
		return(printf("erreur malloc\n"), 0);
	
	i = 0;
	while (map[i] && i < 12)
	{
		j = 0;
		cub3D->map[i] = malloc(25);
		if (!cub3D->map[i])
			return(printf("erreur malloc n* %d\n", i), 0);
		while (map[i][j])
		{
			cub3D->map[i][j] = map[i][j];
			j++;	
		}
		cub3D->map[i][j] = '\0';
		i++;
	}
	cub3D->map[i] = NULL;
	set_first_position(cub3D);
	return (1);
}