/*
** init_modules.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	"tserver.h"
#include	"zopt.h"
#include	"module.h"

static void	init_module_insert(void *data)
{
  mod_load((char *)data);
}

/*
**
** if a Module don't load - no prob.
** it'll just not register
** but it'l work if at least one module load successfully.
**
*/

bool		init_modules(t_zopt *optab)
{
  foreach_list(optab->module, init_module_insert);
  return (true);
}
