/*
 * primary_funcs.h
 *
 * This file is part of rmw (https://rmw.sf.net)
 *
 *  Copyright (C) 2012-2016  Andy Alt (andyqwerty@users.sourceforge.net)
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

#ifndef INC_PRIMARY_FUNCS_H
#define INC_PRIMARY_FUNCS_H

#include "rmw.h"
#include "str_funcs.h"
#include "primary_funcs.h"

void get_config (const char *alt_config);

bool pre_rmw_check (const char *cmdargv);

int remove_to_waste (void);

int mkinfo (bool dup_filename);

void Restore (int argc, char *argv[], int optind);

int purge (void);

bool purgeD (void);

void undo_last_rmw (void);

int getch (void);

/* reads from keypress, echoes */
int getche (void);

/* Before copying or catting strings, make sure str1 won't exceed
 * PATH_MAX + 1
 * */
bool buf_check_with_strop (char *s1, const char *s2, bool mode);

bool buf_check (const char *str, unsigned short boundary);

int rmdir_recursive (char *path, bool isTop);

void mkdirErr (const char *dirname, const char *text_string);

void waste_check (const char *p);

bool isProtected (void);

void restore_select (void);

bool file_exist (const char *filename);

void get_time_string (char *tm_str, unsigned short len, const char *format);

#endif