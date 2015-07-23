require "../semantics/c11.k"
require "../verification/lemmas.k"

module C-BMC
  imports C11
  imports C-CONFIGURATION
  imports LEMMAS

  // SV-COMP macros
  // __VERIFIER_assume(expression):
  //rule (.K => UNDEF("BMC1", "BMC error statement reached.", ""))
  //     ~> prepareBuiltin(Identifier("__VERIFIER_error"), .HeatList)
  //  [structural]
  rule prepareBuiltin(Identifier("__VERIFIER_nondet_char"), .HeatList)
    => tv(?I:Int, t(.Set, char))
    ensures min(t(.Set, char)) <=Int ?I
    andBool ?I <=Int max(t(.Set, char))
    [structural]
  rule prepareBuiltin(Identifier("__VERIFIER_nondet_uchar"), .HeatList)
    => tv(?I:Int, t(.Set, unsigned-char))
    ensures min(t(.Set, unsigned-char)) <=Int ?I
    andBool ?I <=Int max(t(.Set, unsigned-char))
    [structural]
  rule prepareBuiltin(Identifier("__VERIFIER_nondet_int"), .HeatList)
    => tv(?I:Int, t(.Set, int))
    ensures min(t(.Set, int)) <=Int ?I
    andBool ?I <=Int max(t(.Set, int))
    [structural]
  rule prepareBuiltin(Identifier("__VERIFIER_nondet_uint"), .HeatList)
    => tv(?I:Int, t(.Set, unsigned-int))
    ensures min(t(.Set, unsigned-int)) <=Int ?I
    andBool ?I <=Int max(t(.Set, unsigned-int))
    [structural]
endmodule
