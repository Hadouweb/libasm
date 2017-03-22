; Prototype : int ft_puts(const char *s)
; Note : https://en.wikibooks.org/wiki/X86_Assembly/Interfacing_with_Linux#syscall
;

%define MACH_SYSCALL(nb)	0x2000000 | nb
%define WRITE				4

section .data
	eol: db 10		; '\n'

section .text
	global _ft_puts

_ft_puts:
	push rbp
	mov rbp, rsp

	mov rsi, rdi	; s
	mov r10, rdi	; met s dans r10. r10 va servir a mesurer la longueur de la chaine
	mov rdi, 1		; sortie standard
	mov rdx, 0		; length

recherche_longueur:
	mov rcx, [r10]
	cmp cl, 0
	je longueur_connue	; la longueur est dans rdx
	inc rdx
	inc r10
	jmp recherche_longueur

longueur_connue:

	mov rax, MACH_SYSCALL(WRITE)
	syscall
	jc erreur						; Gestion de l'erreur d'ecriture

	lea rsi, [rel eol]				; Adresse du '\n'
	mov rdx, 1
	mov rax, MACH_SYSCALL(WRITE)	; Ecriture du '\n'
	syscall

	; le retour de write est transmis a la fonction appelante de facon transparante par rax
	; Sauf si le carry est set
	jnc fin

erreur:
	mov rax, -1						; EOF
	

fin:
	
	leave
	ret
