bits 32 

global start        

extern exit               
import exit msvcrt.dll    
                          
segment data use32 class=data
a db 1;
b dw 2;
c dd 3;
d dq 4;

segment code use32 class=code
    start:
        ;(a + b + c) - (d + d) + (b + c) (a - byte, b - word, c - double word, d - qword - Unsigned representation)
        mov ECX, 0; ECX = 0;
        mov ECX, [c]; ECX = c
        mov AX, 0; AX = 0
        mov AX, [b]; AX = b
        mov DX, 0; DX = 0
        push DX;
        push AX;
        pop EAX; EAX = b
        add ECX, EAX; ECX = b+c
        push ECX; We have b + c on the stack
        mov Al, 0; Al = 0
        mov Al, [a]; Al = a
        mov Ah, 0; AX = a
        mov DX, 0; DX:AX = a
        push DX;
        push AX;
        pop EAX; EAX = a
        add EAX, ECX; EAX = a + b + c
        mov EDX, 0; EDX:EAX = a + b +c
        mov ECX, 0; ECX = 0
        mov EBX, 0; EBX = 0
        mov EBX, [d]; 
        mov ECX, [d+4]; ECX:EBX = d
        sub EAX, EBX;
        sbb EDX, ECX; EDX:EAX = (a+b+c) - d
        sub EAX, EBX;
        sbb EDX, ECX; EDX:EAX = (a+b+c) - (d+d)
        mov EBX, 0; EBX = 0
        pop EBX; EBX = b+c
        mov ECX, 0; ECX:EBX = b+c
        add EAX, EBX;
        adc EDX, ECX; EDX:EAX = (a+b+c) - (d+d) + (b + c)

        push    dword 0     
        call    [exit]       
