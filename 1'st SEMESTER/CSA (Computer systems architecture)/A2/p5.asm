bits 32 

global start        

extern exit               
import exit msvcrt.dll    
                          
segment data use32 class=data
a db 01;
b db 02;
c db 03;
d db 04;
e dw 05;
f dw 06;
g dw 07;
h dw 08;

segment code use32 class=code
    start:
        ;a*d+b*c (a,b,c,d-byte, e,f,g,h-word)
        mov AX,0; Al = 0
        mov Al, [a]; Al = a
        mul byte[d]; AX = a*d
        mov BX, AX; BX = a*d
        mov AX, 0; AX = 0;
        mov Al, [b]; Al = b
        mul byte[c]; AX = b*c
        add AX, BX; AX = AX + BX
        
        push    dword 0      
        call    [exit]       
