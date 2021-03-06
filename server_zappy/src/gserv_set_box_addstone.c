/*
** gserv_set_box_addstone.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include		<stdlib.h>
#include		"stone.h"
#include		"tserver.h"
#include		"server_zappy.h"

extern t_server 	*gserv;

static t_stone		*new_stone(e_stone type, uint nb)
{
  t_stone 		*stone;

  if (!(stone = malloc(sizeof(*stone))))
    return (NULL);
  stone->type = type;
  stone->nb = nb;
  return (stone);
}

static bool		match_stone(void *data, void *stone)
{
  return (((t_stone *)data)->type == *((e_stone *)stone));
}

bool			set_box_addstone(uint x, uint y, e_stone type, uint nb)
{
  t_box 		*box;
  t_stone 		*stone;

  if (!(box = get_box(x, y)))
    return (false);
  if ((stone = get_data_as_arg(box->stones, match_stone, &type)))
    stone->nb += nb;
  else if (!(stone = new_stone(type, nb)) ||
	   !put_in_list(&(box->stones), stone))
    return (false);
  return (true);
}
