/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:50:34 by hemottu           #+#    #+#             */
/*   Updated: 2024/01/17 13:00:35 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int hex_digit_to_int(char hex_digit) {
    if (hex_digit >= '0' && hex_digit <= '9')
        return hex_digit - '0';
    else if (hex_digit >= 'a' && hex_digit <= 'f')
        return hex_digit - 'a' + 10;
    else if (hex_digit >= 'A' && hex_digit <= 'F')
        return hex_digit - 'A' + 10;
    return -1;
}

void hex_string_to_color(const char *hex_string, t_pix *pixel) {
    pixel->R = hex_digit_to_int(hex_string[0]) * 16 + hex_digit_to_int(hex_string[1]);
    pixel->G = hex_digit_to_int(hex_string[2]) * 16 + hex_digit_to_int(hex_string[3]);
    pixel->B = hex_digit_to_int(hex_string[4]) * 16 + hex_digit_to_int(hex_string[5]);
    pixel->A = hex_digit_to_int(hex_string[6]) * 16 + hex_digit_to_int(hex_string[7]);
}

#include <string.h>

void set_pixel(t_cub *cub, int index, const char *value) {
    
    t_pix pixel;
    hex_string_to_color(value, &pixel);

    // static int i = 0;
    // if (i == 0 && (strcmp(value, "FFFFFFFF") == 0))
    // {
    //     printf("Blue : %u\n", pixel.B);
    //     printf("Green : %u\n", pixel.G);
    //     printf("Red : %u\n", pixel.R);
    //     printf("Alpha : %u\n", pixel.A);
    //     i++;
    // }
    cub->screen->addr[index * (cub->screen->bits_per_pixel / 8)] = pixel.B;
    cub->screen->addr[index * (cub->screen->bits_per_pixel / 8) + 1] = pixel.G;
    cub->screen->addr[index * (cub->screen->bits_per_pixel / 8) + 2] = pixel.R;
    cub->screen->addr[index * (cub->screen->bits_per_pixel / 8) + 3] = pixel.A;
}