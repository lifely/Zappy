/*
** print_error.c for My FTP in ./client/src/error
** 
** Made by lepage_b
** Login   <lepage_b@epitech.net>
** 
** Started on  Thu Mar 17 21:40:11 2011 lepage_b
** Last update Sun Apr 03 22:43:34 2011 lepage_b
*/

#include	<stdarg.h>
#include	<stdio.h>
#include	<stdbool.h>

bool		print_error(char *msg)
{
  fprintf(stderr, "Error: %s\n", msg);
  return (false);
}

bool		print_perror(char *cmd)
{
  perror(cmd);
  return (false);
}

bool		syntax_print_error(char const *format, ...)
{
   va_list arguments;

  va_start(arguments, format);
  fprintf(stderr, "Error: ");
  vfprintf(stderr, format, arguments);
  va_end(arguments);
  fprintf(stderr, "\n");
  return (false);
}
