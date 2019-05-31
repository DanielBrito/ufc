%fatos
gerou(ana, eva).
gerou(ivo, eva).
gerou(bia, rai).
gerou(bia, clo).
gerou(bia, ary).
gerou(gil, rai).
gerou(gil, clo).
gerou(gil, ary).
gerou(eva, noe).
gerou(rai, noe).
gerou(ary, gal).
gerou(lia, gal).

feminino(ana).
feminino(eva).
feminino(bia).
feminino(clo).
feminino(lia).
feminino(gal).
masculino(ivo).
masculino(rai).
masculino(ary).
masculino(gil).
masculino(noe).

%regras
mae(X, Y):-
    gerou(X, Y),
    feminino(X).

pai(X, Y) :-
    gerou(X, Y),
    masculino(X).

irma(X, Y) :-
    gerou(M, X),
    gerou(H, X),
    gerou(M, Y),
    gerou(H, Y),
    feminino(X),
    feminino(Y).

irmao(X, Y) :-
    gerou(M, X),
    gerou(H, X),
    gerou(M, Y),
    gerou(H, Y),
    masculino(X),
    masculino(Y).

avoM(X, Z) :-
    gerou(X, Y),
    gerou(Y, Z),
    masculino(X).

avoF(X, Z) :-
    gerou(X, Y),
    gerou(Y, Z),
    feminino(X).

tio(X, Y) :-
    irmao(X, Z),
    pai(Z, Y);
    irma(X, Z),
    mae(Z, Y).

primo(X, Y) :-
    irmao(A, B),
    gerou(A, X),
    gerou(B, Y),
    X\==Y.

primo(X, Y) :-
    irma(A, B),
    gerou(A, X),
    gerou(B, Y),
    X\==Y.

descendente(X, Y) :-
    gerou(X, Y).

descendente(X, Y) :-
    gerou(X, A),
    descendente(A, Y).
