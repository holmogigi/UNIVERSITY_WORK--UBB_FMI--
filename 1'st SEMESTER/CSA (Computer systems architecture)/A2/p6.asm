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
a1 db 2;

segment code use32 class=code
    start:
        ;(e+g-2*b)/c (a,b,c,d-byte, e,f,g,h-word)
        mov AX, 0; AX = 0
        mov AX, [e]; AX = e
        add AX, [g]; AX = e+g
        mov BX, AX; BX = e+g
        mov AX, 0; AX = 0
        mov Al, [b]; Al = b
        mul byte[a1]; AX = 2*b
        sub BX, AX; BX = e+g-2*b
        mov AX, BX; AX = e+g-2*b
        div byte[c]; AX = (e+g-2*b)/c      
        
        push    dword 0      
        call    [exit]       
