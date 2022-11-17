bits 32 

global start        

extern exit               
import exit msvcrt.dll    
    
segment data use32 class=data
a db 100;
b db 200;
c db 100;
d dw 05;
a1 db 20;
a2 db 10;
a3 dw 3;
a4 dw 5;

segment code use32 class=code
    start:
        ;3*[20*(b-a+2)-10*c]/5 (a,b,c - byte, d - word)
        mov AX, 0; AX = 0
        add Al, [b]; Al = b
        sub Al, [a]; Al = b-a
        add Al, 2; Al = b-a+2
        mul byte[a1]; AX = 20*(b-a+2)
        mov BX,AX; BX = 20*(b-a+2)
        mov EAX,0; EAX = 0
        mov Al,[c]; Al = c;
        mul byte[a2]; AX = 10* c
        sub BX,AX; BX = 20*(b-a+2), AX = 10*c, BX- AX => BX = 20*(b-a+2)-10*c
        mov AX,BX; AX = 20*(b-a+2)-10*c
        mul word[a3]; EAX = 3*[20*(b-a+2)-10*c]
        push DX;
        push AX;
        pop EAX;
        div word[a4]; AX = 3*[20*(b-a+2)-10*c]/5      
        
        push    dword 0     
        call    [exit]       
