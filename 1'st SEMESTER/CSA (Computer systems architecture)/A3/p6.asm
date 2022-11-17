bits 32 

global start        

extern exit               
import exit msvcrt.dll    

segment data use32 class=data
a dw 01;
b db 02;
c dd 03;
x dq 04;

segment code use32 class=code
    start:
       ;(a*a+b+x)/(b+b)+c*c (a-word; b-byte; c-doubleword; x-qword, signed)
        mov AX, 0; AX = 0;
        mov AX, [a]; AX = a;
        imul word[a]; DX:AX = a*a;
        push DX;
        push AX;
        pop EAX; EAX = a*a;
        cdq; EDX:EAX = a*a;
        mov EBX, EAX;
        mov ECX, EDX; ECX:EBX = a*a;
        mov Al, 0;
        mov Al, [b]; Al = b
        cbw; AX = b
        cwd; DX:AX = b
        cwde; EAX = b
        cdq; EDX:EAX = b
        add EBX, EAX;
        adc ECX, EDX; ECX:EBX = a*a + b;
        mov EAX, 0;
        mov EDX, 0;
        mov EAX, [x];
        mov EDX, [x+4]; EDX:EAX = x;
        add EBX, EAX;
        adc ECX, EDX; ECX:EBX = a*a + b + x;
        mov Al, 0;
        mov Al, [b]; Al = b;
        add Al, [b]; Al = b+b; 
        cbw; AX = b+b;
        cwd; DX:AX = b+b
        cwde; EAX = b+b
        push EAX;
        mov EAX,0;
        mov EDX, 0;
        mov EAX, EBX;
        mov EDX, ECX; EDX:EAX = a*a + b + x;
        pop EBX; EBX = b+b
        idiv EBX; EAX = cat[(a*a + b + x)/(b+b)] EDX = rest[(a*a + b + x)/(b+b)]
        mov EBX, EAX; EBX = (a*a + b + x)/(b+b)
        mov EAX, 0;
        mov EAX, [c]; EAX = c
        imul dword[c]; EDX:EAX = c*c
        push EDX;
        push EAX;
        mov EAX, 0;
        mov EAX, EBX; EAX = (a*a + b + x)/(b+b);
        cdq; EDX:EAX = (a*a + b + x)/(b+b);
        pop EBX;
        pop ECX; ECX: EBX = c*c
        add EAX, EBX;
        adc EDX, ECX; EDX:EAX = (a*a+b+x)/(b+b)+c*c
 
        push    dword 0      
        call    [exit]       
