; Prototype : char *ft_strcat(char *dest, const char *src)
;
; Notes :
; - La valeur de retour d'une fonction doit etre placee dans le registre rax.

section .text
    global _ft_strcat
_ft_strcat:
    push rbp                ; {
    mov rbp, rsp            ;

    mov rax, rdi            ; char *r = dest;
    mov rdx, rdi            ; char *d = dest;
    mov r10, rsi            ; char *s = src
recherche_fin_dest:
    mov rcx, [rdx]          ; c = *d;
    cmp cl, 0              ; z = c == 0
    je remplissage          ; if (z) goto remplissage;
    inc rdx                 ; d++;
    jmp recherche_fin_dest  ; goto recherche_fin_dest;
remplissage:
    mov cl, [r10]           ; c = *s;
    cmp cl, 0               ; z = c == 0;
    je fin_de_chaine        ; if (z) goto fin;
    mov [rdx], cl           ; *d = c;
    inc rdx                 ; d++;
    inc r10                 ; s++;
    jmp remplissage         ; goto remplissage;
fin_de_chaine:
    mov [rdx], byte 0       ; *d = '\0';

    leave
    ret                     ; return r; }
