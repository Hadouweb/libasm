; Prototype : int ft_strcmp(const char *s1, const char *s2)
;

section .text
	global _ft_strcmp
_ft_strcmp:
	push rbp
	mov rbp, rsp

	push rbx			; Sauvegarde de rbx

boucle:
	mov rax, [rdi]
	mov rbx, [rsi]
	cmp al, bl
	jne fin				; Caracteres differents
	cmp al, byte 0		; Fin de chaine
	je fin
	inc rdi
	inc rsi
	jmp boucle

fin:
	and rax, 0xff		; Conserve l'octet de poid faible
	and rbx, 0xff		; Conserve l'octet de poid faible
	sub eax, ebx		; Pour retourner la difference des deux

	pop rbx				; Restauration de rbx

	leave
	ret
