bits 32 

global start        

extern exit              
import exit msvcrt.dll    

segment data use32 class=data
    s1 db 'a', 'b', 'c', 'd', 'e','f';
    l1 equ $ - s1;
    s2 db 'e', 'f', 'g', '1', '2';
    l2 equ $ - s2;
    d times l1 + l2 db 0;

segment code use32 class=code
    start:
        ;Two character strings S1 and S2 are given. Obtain the string D by concatenating the elements of S2 in reverse order and the elements found on even positions in S1.
        mov ecx, l2; ECX = length of s2
        mov esi, l2-1; in ESI we have the last position of s2
        mov ebx, 0; in EBX we have the position in d
        jecxz endFor1
        repeat1: ;in this loop we decrease the position in s2 by 1 completing d with the elements form s2
            mov Al, [s2+esi]
            mov [d+ebx], Al
            inc ebx
            dec esi
        loop repeat1       
        endFor1:

        mov ecx, l1/2; ECX = length of s1 / 2 because we take only the even numbers
        mov esi, 1;in ESI we have the first even position which is 1 because we start the index from 0
        jecxz endFor2
        repeat2:; in this loop we increase the position in s1 by 2 completing d with the elements from s1
            mov Al, [s1+esi]
            mov [d+ebx], Al
            add esi, 2
            inc ebx
        loop repeat2      
        endFor2:
        
        push    dword 0     
        call    [exit]      
