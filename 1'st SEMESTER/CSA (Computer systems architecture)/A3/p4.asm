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
        ;(a + b - c) + (a + b + d) - (a + b) (a - byte, b - word, c - double word, d - qword - Signed representation)
        mov Al, 0;
        mov Al, [a]; Al = a
        cbw; AX = a;
        mov BX, 0;
        mov BX, [b]; BX = b;
        add AX, BX; AX = a + b
        cwd; DX:AX = a+b
        cwde; EAX = a+ b;
        cdq; EDX:EAX = a+b;
        push EDX;
        push EAX; We have a+b as qword on the stack
        mov EAX, 0; EAX = 0;
        mov EAX, [c]; EAX = c;
        cdq; EDX:EAX = c;
        pop EBX; 
        pop ECX; ECX:EBX = a+b
        push ECX;
        push EBX; We have a+b as qword on the stack
        sub EBX, EAX;
        sbb ECX, EDX; ECX:EBX = a+b-c
        mov EAX,EBX;
        mov EDX,ECX; EDX:EAX = a+b-c;
        mov EBX,0;
        mov ECX,0;
        pop EBX;
        pop ECX; ECX:EBX = a+b;
        add EAX, EBX;
        adc EDX, ECX; EDX:EAX = (a+b-c) +(a+b)
        push ECX;
        push EBX; We have a+b as qword on the stack
        mov EBX,0;
        mov ECX,0;
        mov EBX, [d];
        mov ECX, [d+4]; ECX:EBX = d;
        add EAX, EBX;
        adc EDX, ECX; EDX:EAX = (a+b-c) +(a+b+d)
        mov EBX,0;
        mov ECX,0;
        pop EBX;
        pop ECX; ECX:EBX = a+b;
        sub EAX, EBX;
        sbb EDX, ECX;EDX:EAX = (a + b - c) + (a + b + d) - (a + b)

        push    dword 0      
        call    [exit]             
