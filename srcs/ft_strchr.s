; Prototype : char *ft_strchr(const char *s, int c)
;

section .text
	global _ft_strchr
_ft_strchr:
	push rbp
	mov rbp, rsp

	push rbx

	mov rbx, rsi				; Permet d'avoir c dans bl

boucle:
	mov rax, [rdi]				; Lecture d'un caractere
	cmp al, 0
	je chaine_parcourue			; Si c'est un '\0', la chaine a ete parcourue
	cmp al, bl
	je occurrence_trouvee		; L'occurence a ete trouvee
	inc rdi
	jmp boucle

chaine_parcourue:
	cmp bl, 0
	je occurrence_trouvee		; Si on cherchait un '\0', l'occurence est trouvee
	mov rax, 0					; Sinon on doit retourner NULL
	jmp fin

occurrence_trouvee:
	mov rax, rdi				; L'adresse a retournee

fin:
	pop rbx

	leave
	ret
