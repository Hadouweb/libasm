; Prototype : void *ft_memset(void *s, int c, size_t n);
;

section .text
	global _ft_memset
_ft_memset:
	push rbp
	mov rbp, rsp

	push rdi			; Sauvegarde de la destination
	mov rax, rsi		; rax = c; // Initialisation du caractere a utiliser
	mov rcx, rdx		; rcx = n; // Initialisation du compteur
	rep stosb			; Rempli rcx octets de rdi avec al
	pop rax				; Restauration de la destination a retourner

	leave
	ret
