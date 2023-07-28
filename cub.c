/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:34:57 by aech-che          #+#    #+#             */
/*   Updated: 2023/07/28 18:52:27 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
    t_cub_data cb_data;

    if(ac > 2)    
    {
        show_errors("Too many arguments\n");
        return(2);
    }

    if(ac < 2)    
    {
        show_errors("Too few arguments\n");
        return(2);
    }
    cb_data.map_name = av[1];
    if (start_game(&cb_data) == -1)
        return (2);
    
}