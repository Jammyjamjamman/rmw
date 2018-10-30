/*
 * utils_rmw.c
 *
 * This file is part of rmw (https://github.com/andy5995/rmw/wiki)
 *
 *  Copyright (C) 2012-2017  Andy Alt (andy400-dev@yahoo.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

#ifndef INC_RMW_H
#define INC_RMW_H
  #include "rmw.h"
#endif

#include "utils_rmw.h"
#include "strings_rmw.h"

/**
 * make_dir()
 *
 * Check for the existence of a dir, and create it if not found.
 * Also creates parent directories.
 */
int
make_dir (const char *dir)
{
  if (exists (dir))
    return 0;

  char temp_dir[MP];
  strcpy (temp_dir, dir);

  char *tokenPtr;
  tokenPtr = strtok (temp_dir, "/");

  char add_to_path[MP];
  if (dir[0] == '/')
    add_to_path[0] = '/';

  add_to_path[1] = '\0';

  bool mk_err = 0;

  while (tokenPtr != NULL)
  {
    if (strlen (add_to_path) > 1 || *add_to_path == '.')
      strcat (add_to_path, "/");

    bufchk (tokenPtr, MP - strlen (add_to_path));
    strcat (add_to_path, tokenPtr);
    tokenPtr = strtok (NULL, "/");

    if (!exists (add_to_path))
    {
      mk_err = (mkdir (add_to_path, S_IRWXU));

      if (!mk_err)
        continue;
      else
        break;
    }
  }

  if (!mk_err)
  {
    printf (_("Created directory %s\n"), dir);
    return MAKE_DIR_SUCCESS;
  }

  printf (_("  :Error: while creating %s\n"), add_to_path);
  perror ("make_dir()");
  return MAKE_DIR_FAILURE;
}

/**
 * int exists (const char *filename);
 * Checks for the existence of *filename.
 */
int exists (const char *filename)
{
  static struct stat st;
  static ushort state = 0;
  state = (lstat (filename, &st));
  return state == 0 ? true : false;
}

void
dispose_waste (st_waste *node)
{
  if (node != NULL)
  {
    dispose_waste (node->next_node);
    node = NULL;
    free (node);
  }
}
