module C-ENV-SYNTAX
     imports C-SYNTAX
     imports C-SYMLOC-SYNTAX
     imports C-DYNAMIC-SYNTAX

     syntax KItem ::= addToEnv(CId, SymBase)
     syntax KItem ::= giveType(CId, Type)
     syntax KItem ::= addEnum(CId, Int)
     syntax KItem ::= "populateFromGlobal"
     syntax KItem ::= addToHistory(Int)

endmodule

module C-ENV
     imports C-ENV-SYNTAX
     imports C-BITSIZE-SYNTAX
     imports C-TYPING-SYNTAX

     imports C-CONFIGURATION

     rule <k> addToHistory(BlockNum:Int) => .K ...</k>
          <block-history> .List => ListItem(BlockNum) ...</block-history>

     rule <k> populateFromGlobal => .K ...</k>
          <curr-tu> Tu:String </curr-tu>
          <tu-id> Tu </tu-id>
          <genv> G:Map </genv>
          <gtypes> GT:Map </gtypes>
          <genums> GE:Map </genums>
          <env> _ => G </env>
          <types> _ => GT </types>
          <enums> _ => GE </enums>

     rule <k> addToEnv(X:CId, Base:SymBase) => addToGlobalEnv(X, Base) ...</k>
          <curr-scope> fileScope </curr-scope>
     rule <k> addToEnv(X:CId, Base:SymBase) => addToLocalEnv(X, Base) ...</k>
          <curr-scope> S:Scope </curr-scope>
          requires S =/=K fileScope

     syntax KItem ::= addToGlobalEnv(K, SymBase)
     rule <k> addToGlobalEnv(X:CId, Base:SymBase) => .K ...</k>
          <curr-tu> Tu:String </curr-tu>
          <tu-id> Tu </tu-id>
          <genv> G:Map => G[X <- Base] </genv>
          <env> E:Map => E[X <- Base] </env>

     syntax KItem ::= addToLocalEnv(K, SymBase)
     rule <k> addToLocalEnv(X:CId, Base:SymBase) => .K ...</k>
          <env> E:Map => E[X <- Base] </env>

     rule <k> addEnum(X:CId, Value:Int) => addGlobalEnum(X, Value) ...</k>
          <curr-scope> fileScope </curr-scope>
     rule <k> addEnum(X:CId, Value:Int) => addLocalEnum(X, Value) ...</k>
          <curr-scope> S:Scope </curr-scope>
          requires S =/=K fileScope

     syntax KItem ::= addGlobalEnum(K, Int)
     rule <k> addGlobalEnum(X:CId, Value:Int) => .K ...</k>
          <curr-tu> Tu:String </curr-tu>
          <tu-id> Tu </tu-id>
          <genums> G:Map => G[X <- Value] </genums>
          <enums> E:Map => E[X <- Value] </enums>

     syntax KItem ::= addLocalEnum(K, Int)
     rule <k> addLocalEnum(X:CId, Value:Int) => .K ...</k>
          <enums> E:Map => E[X <- Value] </enums>

     rule <k> giveType(X:CId, T:Type)
               => giveGlobalType(X, tagRestrict(fileScope, stripStorageSpecifiers(T)))
          ...</k>
          <curr-scope> fileScope </curr-scope>
     rule <k> giveType(X:CId, T:Type)
               => giveLocalType(X, tagRestrict(S, stripStorageSpecifiers(T)))
          ...</k>
          <curr-scope> S:Scope </curr-scope>
          requires S =/=K fileScope

     syntax KItem ::= giveGlobalType(K, Type)
     rule <k> giveGlobalType(X:CId, T:Type) => .K ...</k>
          <types> L:Map => L[X <- T] </types>
          <curr-tu> Tu:String </curr-tu>
          <tu-id> Tu </tu-id>
          <gtypes> G:Map => G[X <- T] </gtypes>

     syntax KItem ::= giveLocalType(K, Type)
     rule <k> giveLocalType(X:CId, T:Type) => .K ...</k>
          <types> L:Map => L[X <- T] </types>

endmodule
