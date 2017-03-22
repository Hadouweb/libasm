; Prototype : int ft_memcmp(const void *s1, const void *s2, size_t n)
;

section .text
	global _ft_memcmp
_ft_memcmp:
	push rbp
	mov rbp, rsp

	push rbx			; Sauvegarde de rbx

boucle:
	cmp rdx, 0			; Compteur
	je fin
	mov rax, [rdi]
	mov rbx, [rsi]
	cmp al, bl
	jne fin				; Octets differents
	inc rdi
	inc rsi
	dec rdx
	jmp boucle

fin:
	and rax, 0xff		; Conserve l'octet de poid faible
	and rbx, 0xff		; Conserve l'octet de poid faible
	sub eax, ebx		; Pour retourner la difference des deux

	pop rbx				; Restauration de rbx

	leave
	ret
