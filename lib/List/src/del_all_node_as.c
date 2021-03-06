/*
** del_all_node_as.c for Zappy in ./lib/List/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdlib.h>
#include	"list.h"

void		del_all_node_as(t_list ** list,
				bool (*match_node)(void *),
				void (*destroy_data)(void *))
{
  void *	data;

  while ((data = del_node_as(list, match_node)))
    if (destroy_data)
      destroy_data(data);
}
