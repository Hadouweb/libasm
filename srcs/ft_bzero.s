; Prototype : void ft_bzero(void *s, size_t n)
;
; Notes :
; - Les 6 premiers parametres sont stockes dans les registres rdi, rsi, rdx, rcx, r8, r9

section .text
    global _ft_bzero
_ft_bzero:
    push rbp            ; {
    mov rbp, rsp        ;

    mov rax, rsi        ;     size_t i = n;
    cmp rax, 0          ;     z = i == 0;
    je fin              ;     if (z) goto fin;
boucle:                 ;     do {
    mov [rdi], byte 0   ;         *(char*)s = 0;
    inc rdi             ;         s++;
    dec rax             ;         i--;
    cmp rax, 0          ;         z = (i == 0);
    jne boucle          ;     } while( ! z);

fin:
    leave               ;
    ret                 ; return ; }
