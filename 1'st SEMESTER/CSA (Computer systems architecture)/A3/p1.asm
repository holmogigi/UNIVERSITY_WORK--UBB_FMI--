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
        ;(a+d+d)-c+(b+b) (a - byte, b - word, c - double word, d - qword - Unsigned representation)
        mov Al, 0; Al = 0
        mov Al, [a]; Al = a
        mov Ah, 0; AX = a
        mov DX, 0; DX:AX = a
        push DX;
        push AX;
        pop EAX; EAX = a
        mov EDX, 0; EDX:EAX = a 
        mov EBX, 0; EBX = 0
        mov ECX, 0; ECX = 0
        mov EBX, [d];
        mov ECX, [d+4]; ECX:EBX = d
        add EAX, EBX; 
        adc EDX, ECX; EDX:EAX = a + d
        add EAX, EBX; 
        adc EDX, ECX; EDX:EAX = a + d + d
        mov EBX, 0; EBX = 0
        mov EBX, [c]; EBX = c
        mov ECX, 0; ECX: EBX = c
        sub EAX, EBX; 
        sbb EDX, ECX; EDX:EAX = (a + d + d) - c
        mov BX, 0; BX = 0
        mov BX, [b]; BX = b
        mov CX, 0; CX:BX = b
        push CX
        push BX
        pop EBX; EBX = b
        mov ECX, 0; ECX:EBX = b
        add EAX, EBX; 
        adc EDX, ECX; EDX:EAX = (a + d + d) - c + 
        add EAX, EBX; 
        adc EDX, ECX; EDX:EAX = (a + d + d) - c + (b + b)
  
        push    dword 0      
        call    [exit]       
