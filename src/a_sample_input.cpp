/*MACROS_BEGIN

defmacro macro1 {a b c} {
   //This is just a test. The arguments are $a $b and $c.
   int i$a = get_value("$a");
   int i$b = get_value("$b");
   int i$c = get_value("$c");
}

# Procedural macro - compute the expansion
def_p_macro macro2 {args} {
    foreach arg $args {
    append code "\nBEGIN $arg";
    }
    foreach arg [lreverse $args] {
    append code "\nEND $arg";
    }
}

def_p_macro macro3 {args} {
    foreach p [permutations $args] {
        append code "\ninstantiate(" [comma_separate $p] ");"
    }
   
}


def_p_macro macro4 {args} {
    foreach c [combinations $args 3] {
        foreach p [permutations $c] {
            append code "\nINSTANTIATE(" [comma_separate $p] ");"
        }
    }
}

expand_macro macro1 P Q R
expand_macro macro2 A B C D E F G
expand_macro macro2 "first argument" "second argument" "1,2,3,4" {if (this) then (that)} "hello world"
expand_macro macro3 A B C D
expand_macro macro4 A B C D E
MACROS_END*/

//begin_macro_expansion : macro1 P Q R {{{1
#pragma region macro expansion

   //This is just a test. The arguments are P Q and R.
   int iP = get_value("P");
   int iQ = get_value("Q");
   int iR = get_value("R");

#pragma endregion macro1 P Q R
//end_macro_expansion }}}1

//begin_macro_expansion : macro2 A B C D E F G {{{1
#pragma region macro expansion

BEGIN A
BEGIN B
BEGIN C
BEGIN D
BEGIN E
BEGIN F
BEGIN G
END G
END F
END E
END D
END C
END B
END A
#pragma endregion macro2 A B C D E F G
//end_macro_expansion }}}1

//begin_macro_expansion : macro2 {first argument} {second argument} 1,2,3,4 {if (this) then (that)} {hello world} {{{1
#pragma region macro expansion

BEGIN first argument
BEGIN second argument
BEGIN 1,2,3,4
BEGIN if (this) then (that)
BEGIN hello world
END hello world
END if (this) then (that)
END 1,2,3,4
END second argument
END first argument
#pragma endregion macro2 {first argument} {second argument} 1,2,3,4 {if (this) then (that)} {hello world}
//end_macro_expansion }}}1

//begin_macro_expansion : macro3 A B C D {{{1
#pragma region macro expansion

instantiate(A,B,C,D);
instantiate(A,B,D,C);
instantiate(A,C,B,D);
instantiate(A,C,D,B);
instantiate(A,D,B,C);
instantiate(A,D,C,B);
instantiate(B,A,C,D);
instantiate(B,A,D,C);
instantiate(B,C,A,D);
instantiate(B,C,D,A);
instantiate(B,D,A,C);
instantiate(B,D,C,A);
instantiate(C,A,B,D);
instantiate(C,A,D,B);
instantiate(C,B,A,D);
instantiate(C,B,D,A);
instantiate(C,D,A,B);
instantiate(C,D,B,A);
instantiate(D,A,B,C);
instantiate(D,A,C,B);
instantiate(D,B,A,C);
instantiate(D,B,C,A);
instantiate(D,C,A,B);
instantiate(D,C,B,A);
#pragma endregion macro3 A B C D
//end_macro_expansion }}}1

//begin_macro_expansion : macro4 A B C D E {{{1
#pragma region macro expansion

INSTANTIATE(A,B,C);
INSTANTIATE(A,C,B);
INSTANTIATE(B,A,C);
INSTANTIATE(B,C,A);
INSTANTIATE(C,A,B);
INSTANTIATE(C,B,A);
INSTANTIATE(A,B,D);
INSTANTIATE(A,D,B);
INSTANTIATE(B,A,D);
INSTANTIATE(B,D,A);
INSTANTIATE(D,A,B);
INSTANTIATE(D,B,A);
INSTANTIATE(A,B,E);
INSTANTIATE(A,E,B);
INSTANTIATE(B,A,E);
INSTANTIATE(B,E,A);
INSTANTIATE(E,A,B);
INSTANTIATE(E,B,A);
INSTANTIATE(A,C,D);
INSTANTIATE(A,D,C);
INSTANTIATE(C,A,D);
INSTANTIATE(C,D,A);
INSTANTIATE(D,A,C);
INSTANTIATE(D,C,A);
INSTANTIATE(A,C,E);
INSTANTIATE(A,E,C);
INSTANTIATE(C,A,E);
INSTANTIATE(C,E,A);
INSTANTIATE(E,A,C);
INSTANTIATE(E,C,A);
INSTANTIATE(A,D,E);
INSTANTIATE(A,E,D);
INSTANTIATE(D,A,E);
INSTANTIATE(D,E,A);
INSTANTIATE(E,A,D);
INSTANTIATE(E,D,A);
INSTANTIATE(B,C,D);
INSTANTIATE(B,D,C);
INSTANTIATE(C,B,D);
INSTANTIATE(C,D,B);
INSTANTIATE(D,B,C);
INSTANTIATE(D,C,B);
INSTANTIATE(B,C,E);
INSTANTIATE(B,E,C);
INSTANTIATE(C,B,E);
INSTANTIATE(C,E,B);
INSTANTIATE(E,B,C);
INSTANTIATE(E,C,B);
INSTANTIATE(B,D,E);
INSTANTIATE(B,E,D);
INSTANTIATE(D,B,E);
INSTANTIATE(D,E,B);
INSTANTIATE(E,B,D);
INSTANTIATE(E,D,B);
INSTANTIATE(C,D,E);
INSTANTIATE(C,E,D);
INSTANTIATE(D,C,E);
INSTANTIATE(D,E,C);
INSTANTIATE(E,C,D);
INSTANTIATE(E,D,C);
#pragma endregion macro4 A B C D E
//end_macro_expansion }}}1





























