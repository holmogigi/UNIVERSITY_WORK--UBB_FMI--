bits 32 

global start        

extern exit               
import exit msvcrt.dll    

segment data use32 class=data
a db 01;
b db 02;
c db 03;
d dw 05;
a1 db 5;

segment code use32 class=code
    start:    
        ;d+[(a+b)*5-(c+c)*5] (a,b,c - byte, d - word)
        mov ax,0;
        mov al, [a]; al = a
        add al, [b]; al = a+b
        mul byte[a1]; ax = (a+b)*5
        mov bx,ax; bl = (a+b)*5
        mov ax,0; ax = 0
        mov al, [c]; al = c
        add al, [c]; al = c+c
        mul byte[a1]; ax = (c+c)*5
        sub bx,ax; bx = (a+b)*5 - (c+c)*5
        mov ax,bx; ax = (a+b)*5 - (c+c)*5
        add ax, [d]; = d+[(a+b)*5-(c+c)*5]   
       
        push    dword 0      
        call    [exit]       
