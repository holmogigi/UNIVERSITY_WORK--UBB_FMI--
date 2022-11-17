bits 32

global start        

extern exit               
import exit msvcrt.dll   

segment data use32 class=data
a db 01;
b dw 8;
c db 03;
d dd 04;
x dq 12;
a1 dd 2;
a2 dd 7;
a3 dd 6;

segment code use32 class=code
    start:
        ;d-(7-a*b+c)/a-6+x/2 (a,c-byte; b-word; d-doubleword; x-qword, unsigned)
        mov Al, 0;
        mov Al, [a]; Al = a;
        mov Ah, 0; AX = a;
        mul word[b]; DX:AX = a*b;
        push DX;
        push AX;
        pop EAX; EAX = a*b;
        mov EDX,0;
        mov EDX, [a2]; EDX = 7
        sub EDX,EAX; EDX = 7-a*b
        mov EBX, EDX; EBX = 7-a*b;
        mov EDX, 0; EDX = 0;
        mov Al, 0;
        mov Al, [c]; Al = c;
        mov Ah, 0; AX = c;
        mov DX, 0; DX:AX = c;
        push DX;
        push AX;
        pop EAX; EAX = c;
        add EBX, EAX; EBX = 7-a*b+c
        mov Al, 0;
        mov Al, [a]; Al = a;
        mov Ah, 0; AX = a;
        mov CX, AX; CX = a;
        mov EAX, 0;
        mov EAX, EBX; EAX = 7- a*b +c;
        push EAX;
        pop AX; 
        pop DX; DX:AX = 7- a*b +c
        div CX; AX = cat(7- a*b +c)/a, DX = rest(7- a*b +c)/a;
        mov EBX, 0;
        mov EBX, [d]; EBX = d;
        mov DX, 0; DX:AX = (7- a*b +c)/a
        push DX;
        push AX;    
        pop EAX; EAX = (7- a*b +c)/a
        sub EBX, EAX; EBX = d - (7- a*b +c)/a
        sub EBX, [a3]; EBX = d - (7- a*b +c)/a - 6
        mov EAX, 0;
        mov EDX, 0;
        mov EAX, [x];
        mov EDX, [x+4]; EDX:EAX = x 
        div dword[a1]; EAX = cat(x/2), EDX = rest(x/2)
        add EBX, EAX; EBX = d-(7-a*b+c)/a-6+x/2

        push    dword 0      
        call    [exit]       
