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
        ;b+c+d+a-(d+c) (a - byte, b - word, c - double word, d - qword - Signed representation)
        mov AX, 0; AX = 0;
        mov AX, [b]; AX = b;
        cwd; DX:AX = b;
        cwde; EAX = b;
        mov EBX, 0;
        mov EBX, [c];
        add EAX, EBX; EAX = b+c
        cdq; EDX:EAX = b+c
        mov EBX, 0; EBX = 0;
        mov ECX, 0; ECX = 0;
        mov EBX, [d];
        mov ECX, [d+4]; ECX:EBX = d;
        add EAX, EBX;
        adc EDX, ECX; EDX:EAX = b+c+d
        mov EBX, 0;
        mov ECX, 0;
        mov EBX, EAX;
        mov ECX, EBX; ECX:EBX = b+c+d;
        mov Al, 0;
        mov Al, [a]; Al = a;
        cbw; AX = a;
        cwd; DX:AX = a;
        cwde; EAX = a;
        cdq; EDX:EAX = a;
        add EBX, EAX; 
        adc ECX, EDX; ECX:EBX = b+c+d+a
        mov EAX, 0; EAX = 0;
        mov EDX, 0; EDX = 0;       
        mov EAX, [d];
        mov EDX, [d+4]; EDX:EAX = d;
        sub EBX, EAX;
        sbb ECX, EDX; ECX:EBX = b+c+d+a-d
        mov EAX, 0; EAX = 0;
        mov EAX, [c]; EAX = c;
        cdq; EDX:EAX = c;
        sub EBX, EAX;
        sbb ECX, EDX; ECX:EBX = b+c+d+a-(d+c)

        push    dword 0     
        call    [exit]       
