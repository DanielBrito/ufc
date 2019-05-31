%fatos
gerou(maria, joao).
gerou(maria, ana).
gerou(jose, joao).
gerou(jose, ana).
gerou(ana, helena).
gerou(ana, joana).
gerou(joao, mario).
gerou(helena, carlos).
gerou(mario, carlos).

sexo(ana, feminino).
sexo(maria, feminino).
sexo(joana, feminino).
sexo(helena, feminino).
sexo(mario, masculino).
sexo(joao, masculino).
sexo(jose, masculino).
sexo(carlos, masculino).

irma(X, Y) :-
    gerou(A, X),
    gerou(A, Y),
    X\==Y,
    sexo(X, feminino).

irmao(X, Y) :-
    gerou(A, X),
    gerou(A, Y),
    X\==Y,
    sexo(X, masculino).

descendente(X, Y) :-
    gerou(X, Y).

descendente(X, Y) :-
    gerou(X, A),
    descendente(A, Y).

mae(X, Y) :-
    gerou(X, Y),
    sexo(X, feminino).

pai(X, Y) :-
    gerou(X, Y),
    sexo(X, masculino).

filho(X, Y) :-
    gerou(Y, X).

% c) filho(joao, jose).
% c) irma(helena, X) ; irmao(helena, X).
