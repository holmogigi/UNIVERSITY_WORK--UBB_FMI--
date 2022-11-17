%Define a predicate to add after every element from a list, the divisors of that number
%
%getDivisor(l1,l2,...,ln, nr, div)
%                                {
%                                 l1,l2,...,ln, if nr=div or nr<=1
%
%                                 div U getDivisor(l1,l2,...,ln, nr,
%                                 div+1), if nr%div=0
%
%                                 getDivisor(l1,l2,...,ln, nr, div+1),
%                                 otherwise
%                                }
%flow model: (i,i,i,o)
%
%addDivisors(l1,l2,...,ln), where n=lenght of list
%                        {
%                         {}, if n=0
%
%                         l1 U getDivisor(l1) U
%                         addDivisors(l2,...,ln), otherwise
%                        }
%flow model: (i,o)

getDivisor(N,N,L,L).
getDivisor(N,_,L,L):- N =< 1.
getDivisor(N,D,L,[D|R]):-
    N mod D =:=0,!,
    D1 is D + 1,
    getDivisor(N,D1,L,R).
getDivisor(N,D,L,R):-
    D1 is D + 1,
    getDivisor(N,D1,L,R).

addDivisors([],[]).
addDivisors([H|T],[H|R]):-
    addDivisors(T,RD),
    getDivisor(H,2,RD,R).


%For a heterogeneous list, formed from integer numbers and list of numbers,
%define a predicate to add in every sublist the divisors of every element.
%Eg: [1, [2, 5, 7], 4, 5, [1, 4], 3, 2, [6, 2, 1], 4, [7, 2, 8, 1], 2] =>
%[1, [2, 5, 7], 4, 5, [1, 4, 2], 3, 2, [6, 2, 3, 2, 1], 4, [7, 2, 8, 2, 4, 1], 2]
%
%heteroList(l1,l2,...ln), where n=lenght of list
%                     {
%                      {}, if n=0
%
%                      addDivisors(l1) U hererolist(l2,...,ln), if
%                      is_list(1) is true
%
%                      l1 U heterolist(l2,...,ln), otherwise
%                     }
%flow model: (i,o)

heteroList([],[]).
heteroList([H|T],[RD|R]):-
    is_list(H),
    !,
    addDivisors(H,RD),
    heteroList(T,R).
heteroList([H|T],[H|R]):-
    heteroList(T,R).
