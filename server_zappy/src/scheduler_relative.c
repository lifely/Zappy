/*
** scheduler_relative.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>

#include	"scheduler.h"
#include	"client.h"
#include	"tserver.h"

static bool	scheduler_a(fds c, _time dt,
			   bool (*callb)(fds, void*), void *data)
{
  t_client	*info;
  t_scheduler	*schedule;

  if (!c || !callb || !(info = c->trick))
    return (false);
  schedule = &info->schedule;
  if ((schedule->state))
    return (false);
  memset(schedule, 0, sizeof(*schedule));
  schedule->state = (char)true;
  schedule->st = time_();
  schedule->lt = schedule->st;
  schedule->dt = dt;
  schedule->callback = callb;
  schedule->data = data;
  return (true);
}

bool		scheduler_action(fds c, _time dt,
				bool (*callb)(fds, void*), void *data)
{
  t_client	*info;
  t_scheduler	*schedule;

  if (!scheduler_a(c, dt, callb, data) || !c || !callb || !(info = c->trick))
    return (false);
  schedule = &info->schedule;
  scheduler_update(dt);
  return (true);
}

bool		scheduler_relative(fds c, _time dt,
				  bool (*cb)(fds, void*), void *data)
{
  t_client	*info;
  t_scheduler	*schedule;

  if (!scheduler_a(c, dt, cb, data))
    return (false);
  if (!c || !(info = c->trick))
    return (false);
  schedule = &info->schedule;
  schedule->relative = (char)true;
  scheduler_update(dt * (get_time() / get_delay()));
  return (true);
}

bool		scheduler_active(fds c)
{
  t_client	*info;
  t_scheduler	*schedule;

  if (!c || !(info = c->trick))
    return (false);
  schedule = &info->schedule;
   return ((bool)schedule->state);
}

bool		scheduler_free(fds c)
{
  t_client	*info;
  t_scheduler	*schedule;

  if (!c || !(info = c->trick))
    return (false);
  schedule = &info->schedule;
  schedule->free = true;
  return (true);
}
