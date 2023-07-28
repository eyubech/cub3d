/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-che <aech-che@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:04:31 by aech-che          #+#    #+#             */
/*   Updated: 2023/07/28 18:14:40 by aech-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


void show_errors(char *message)
{
    int i;

    i = 0;
    write(STDERR_FILENO, "Error!!\n", 8);
    while (message[i])
    {
        write(2, &message[i], 1);
        i += 1;
    }
    
}