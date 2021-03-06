/*
** foreach_list.c for Zappy in ./lib/List/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	"list.h"

void		foreach_list(t_list * list, void (*function)(void *))
{
  if (list)
    {
      list->cur = list->begin;
      while (list->cur)
	{
	  function(list->cur->data);
	  list->cur = list->cur->next;
	}
    }
}

