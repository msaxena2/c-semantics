/* Generated by CIL v. 1.3.7 */
/* print_CIL_Input is true */

int ( __attribute__((__noinline__)) f)(int **ipp , int *i1p , int *i2p , int **i3 ,
                                       int **i4 ) ;
int ( __attribute__((__noinline__)) f)(int **ipp , int *i1p , int *i2p , int **i3 ,
                                       int **i4 ) 
{ 

  {
  *(*ipp) = *i1p;
  *ipp = i2p;
  *i3 = *i4;
  *(*ipp) = 99;
  return (3);
}
}
extern void exit(int  ) ;
extern void abort(void) ;
int main(void) 
{ int i ;
  int i1 ;
  int i2 ;
  int i3 ;
  int i4 ;
  int *ip ;
  int *i3p ;
  int *i4p ;

  {
  i = 42;
  i1 = 66;
  i2 = 1;
  i3 = -1;
  i4 = 55;
  ip = & i;
  i3p = & i3;
  i4p = & i4;
  f(& ip, & i1, & i2, & i3p, & i4p);
  if (i != 66) {
    abort();
  } else {
    if ((unsigned long )ip != (unsigned long )(& i2)) {
      abort();
    } else {
      if (i2 != 99) {
        abort();
      } else {
        if (i3 != -1) {
          abort();
        } else {
          if ((unsigned long )i3p != (unsigned long )i4p) {
            abort();
          } else {
            if (i4 != 55) {
              abort();
            }
          }
        }
      }
    }
  }
  exit(0);
}
}