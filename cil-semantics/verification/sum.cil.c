#pragma KCIL_TU "/Users/andrei/c-semantics/cil-semantics/verification/sum.c"
/* Generated by CIL v. 1.7.3 */
/* print_CIL_Input is true */

unsigned int sum(int n ) 
{ 
  unsigned int tmp ;

  {
  if (n) {
    tmp = sum(n - 1);
    return ((unsigned int )n + tmp);
  } else {
    return (0U);
  }
}
}
