bits 32 

global start        

extern exit               
import exit msvcrt.dll    
                          
segment data use32 class=data
a db 01
b db 02
c db 03
d db 04

segment code use32 class=code
    start:
          ;(a+d+d)-c+(b+b) (a,b,c,d - byte)
            mov Al, 0;
            add Al, [a];
            add Al, [d];
            add Al, [d];
            sub Al, [c];
            add Al, [b];
            add Al, [b];
            
        push    dword 0      
        call    [exit]       
