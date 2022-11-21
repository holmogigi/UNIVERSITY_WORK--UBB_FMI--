%For a given n, positive, determine all decomposition of n as a sum of consecutive natural numbers
%
%one_solution(s, n){
%                   [], if s=0
%
%                   n + one_solution(s-n, n+1), otherwise
%                  }
%flow model: (i ,i, o)

one_solution(0,_,[]).
one_solution(S,N,[N|R]):-
    S >= N,
    NS is S - N,
    NN is N + 1,
    one_solution(NS,NN,R).

%decomposition(s, n){
%                    one_solution(s, n), if s>n
%
%                    decomposition(s, n+1), if s>n
%                   }
%flow model: (i, i, o)

decomposition(S,N,R):-
    N < S,
    one_solution(S,N,R).
decomposition(S,N,R):-
    N < S,
    NN is N + 1,
    decomposition(S,NN,R).

%all_solutions(N, R)
%flow model: (i, o)

all_solutions(N, R):-
    findall(RPartial, decomposition(N, 1, RPartial), R).

