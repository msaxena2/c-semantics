/* Generated by CIL v. 1.3.7 */
/* print_CIL_Input is true */

extern  __attribute__((__nothrow__, __noreturn__)) void abort(void)  __attribute__((__leaf__)) ;
extern  __attribute__((__nothrow__, __noreturn__)) void exit(int __status )  __attribute__((__leaf__)) ;
static long l  ;
long baz1(void *a ) 
{ long tmp ;

  {
  tmp = l;
  l ++;
  return (tmp);
}
}
int baz2(char const   *a ) 
{ 

  {
  return (0);
}
}
int baz3(int i ) 
{ 

  {
  if (! i) {
    abort();
  }
  return (1);
}
}
void **bar  ;
int foo(void *a , long b , int c ) 
{ int d ;
  int e ;
  int f ;
  int i ;
  char g[256] ;
  void **h ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  long tmp___4 ;

  {
  d = 0;
  f = 0;
  g[0] = (char )'\n';
  g[1] = (char)0;
  while (1) {
    tmp___4 = baz1(a);
    if (! (tmp___4 < b)) {
      break;
    }
    if ((int )g[0] != 32) {
      if ((int )g[0] != 9) {
        f = 1;
        e = 0;
        if (! d) {
          tmp = baz2((char const   *)(g));
          if (tmp == 0) {
            if ((c & 16) == 0) {
              continue;
            }
            d = 1;
            e = d;
          }
        }
        if (c & 16) {
          if (c & 16384) {
            if (! e) {
              goto _L___0;
            }
          } else {
            goto _L___0;
          }
        } else {
          _L___0: /* CIL Label */ 
          if (c & 2) {
            continue;
          }
        }
        if (c & 8192) {
          tmp___0 = baz2((char const   *)(g));
          if (tmp___0 == 0) {
            continue;
          }
        }
        if (c & 5128) {
          tmp___1 = baz2((char const   *)(g));
          if (tmp___1 == 0) {
            continue;
          }
        }
        if (c & 512) {
          tmp___2 = baz2((char const   *)(g));
          if (tmp___2 == 0) {
            continue;
          }
        }
        if (c & 128) {
          h = bar;
          i = 0;
          while (h) {
            tmp___3 = baz3(i);
            if (tmp___3) {
              break;
            }
            h = (void **)*h;
            i ++;
          }
        }
        f = 0;
      }
    }
  }
  return (0);
}
}
int main(void) 
{ void *n ;

  {
  n = (void *)0;
  bar = & n;
  foo((void *)(& n), 1L, 51217);
  exit(0);
}
}