%fatos
progenitor(maria, joao).
progenitor(maria, ana).
progenitor(jose, joao).
progenitor(jose, ana).
progenitor(ana, helena).
progenitor(ana, joana).
progenitor(joao, mario).
progenitor(helena, carlos).
progenitor(mario, carlos).

sexo(ana, feminino).
sexo(maria, feminino).
sexo(joana, feminino).
sexo(helena, feminino).
sexo(mario, masculino).
sexo(joao, masculino).
sexo(jose, masculino).
sexo(carlos, masculino).

irma(X, Y) :-
    progenitor(A, X),
    progenitor(A, Y),
    X\==Y,
    sexo(X, feminino).

irmao(X, Y) :-
    progenitor(A, X),
    progenitor(A, Y),
    X\==Y,
    sexo(X, masculino).

descendente(X, Y) :-
    progenitor(X, Y).

descendente(X, Y) :-
    progenitor(X, A),
    descendente(A, Y).

mae(X, Y) :-
    progenitor(X, Y),
    sexo(X, feminino).

pai(X, Y) :-
    progenitor(X, Y),
    sexo(X, masculino).

filho(X, Y) :-
    progenitor(Y, X).

% c) filho(joao, jose).
% c) irma(helena, X) ; irmao(helena, X).
