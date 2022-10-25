% Define a predicate to test if a list of an integer elements has a
% "valley" aspect (a set has a "valley" aspect if
% elements decreases up to a certain point, and then increases (10 8 6 9 11 13)
%
% valley(l1,l2,...,ln, type), n=lenght, type=0(inc), type=1(dec)
%                           {
%                             true, if n=1, type=0
%                             valley(l2,...,ln, 1), if l1>l2(type=1)
%                             valley(l2,...,ln, 0), if l1<l2
%                           }

valley([_], 0).
valley([H1,H2|T], TYPE):-
    H1 > H2,
    TYPE =:= 1,
    valley([H2|T], 1).
valley([H1,H2|T],_):-
    H1 < H2,
    valley([H2|T], 0).
mainvalley(L):-
    L=[H1,H2|_],
    H1 > H2,
    valley(L,1).



% Calculate the alternate sum of list’s elements (l1-l2+l3-l4+l5...)
%
% altsum(l1,l2,...,ln), where n=lenght of list
%                     {
%                       0, if n=0
%                       l1, if n=1
%                       l1-l2+altsum(l3,...,ln), otherwise
%                     }

altsum([], 0).
altsum([H], H).
altsum([H1,H2|T], SUM2):-
    altsum(T, SUM),
    SUM1 is H1-H2,
    SUM2 is SUM1+SUM.

