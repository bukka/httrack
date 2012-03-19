/* ------------------------------------------------------------ */
/*
HTTrack Website Copier, Offline Browser for Windows and Unix
Copyright (C) Xavier Roche and other contributors

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.


Important notes:

- We hereby ask people using this source NOT to use it in purpose of grabbing
emails addresses, or collecting any other private information on persons.
This would disgrace our work, and spoil the many hours we spent on it.


Please visit our Website: http://www.httrack.com
*/


/* ------------------------------------------------------------ */
/* File: Unpacking subroutines using Jean-loup Gailly's Zlib    */
/*       for http compressed data                               */
/* Author: Xavier Roche                                         */
/* ------------------------------------------------------------ */


#ifndef HTS_DEFZLIB
#define HTS_DEFZLIB

#if HTS_USEZLIB

int hts_zunpack(char* filename,char* newfile);

#define gzopen hts_ptrfunc_gzopen
#define gzread hts_ptrfunc_gzread
#define gzclose hts_ptrfunc_gzclose

#ifdef _WIN32
#define ZEXPORT WINAPI
#else
#define ZEXPORT 
#endif

typedef void* voidp;
typedef voidp gzFile;
typedef gzFile (ZEXPORT *t_gzopen)(const char *path, const char *mode);
typedef int (ZEXPORT *t_gzread)(gzFile file, voidp buf, unsigned len);
typedef int (ZEXPORT *t_gzclose)(gzFile file);

extern int gz_is_available;
extern t_gzopen gzopen;
extern t_gzread gzread;
extern t_gzclose gzclose;

#endif 

#endif

