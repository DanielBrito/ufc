% consultas
% 1+2 == +(1,2). % true
% 1+2 == 2+1. % false
% 1+2 == 1+X. % false
% 1+2 = X. % X=2
% 1+2 = 2+X. % false
% 1+2 =:= 2+1. % true
% 1+2 =:= 2+X. % error
% X = 1+2. % X = 1+2
% 1+2 = X. % X = 1+2

%regras
maiorIgual(X, Y) :-
    X>=Y.

menorIgual(X, Y) :-
    X=<Y.

entre(X, A, B) :-
    maiorIgual(X, A),
    menorIgual(X, B).

par(X) :-
    X mod 2 =:= 0.

impar(X) :-
    X mod 2 =:= 1.

fatorial(0, 1).

fatorial(N, F) :-
    N > 0,
    N1 is N - 1,
    fatorial(N1, F1),
    F is N * F1.

sucessor(X, Y) :-
    X =:= Y+1.
