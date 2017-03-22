; Prototype : int ft_atoi(const char *nptr)
;

section .text
	global _ft_atoi
_ft_atoi:
	push rbp
	mov rbp, rsp

	mov rsi, 0							; Passera a 1 si le signe est negatif
	mov rax, 0							; rax contiendra le resultat

detecter_caracteres_non_affichables:
	cmp [rdi], byte ' '
	je passer_caractere_non_affichable
	cmp [rdi], byte 0x09
	je passer_caractere_non_affichable
	cmp [rdi], byte 0x0c
	je passer_caractere_non_affichable
	cmp [rdi], byte 0x0b
	je passer_caractere_non_affichable
	cmp [rdi], byte 0x0d
	je passer_caractere_non_affichable
	cmp [rdi], byte 0x0a
	je passer_caractere_non_affichable

	jmp lecture_du_signe_moins

passer_caractere_non_affichable:
	inc rdi
	jmp detecter_caracteres_non_affichables

lecture_du_signe_moins:
	cmp [rdi], byte '-'
	jne lecture_du_signe_plus
	mov rsi, 1
	inc rdi
	jmp lecture_des_chiffres

lecture_du_signe_plus:
	cmp [rdi], byte '+'
	jne lecture_des_chiffres
	inc rdi

lecture_des_chiffres:
	cmp [rdi], byte '0'
	jl affectation_du_signe
	cmp [rdi], byte '9'
	jg affectation_du_signe

	mov rcx, [rdi]				; Lecture du caractere
	and rcx, 0xff				; Seulement l'octet de poids faible
	mov rbx, 10					; Chargement du multiplicateur
	mul rbx						; Multipli rax par 10
	add rax, rcx				; Ajoute la valeur du caractere
	sub rax, '0'				; Retire la valeur du caractere '0'
	inc rdi						; Passe au caractere suivant

	jmp lecture_des_chiffres

affectation_du_signe:
	cmp rsi, 1
	jne fin
	not rax						; Complement
	inc rax						; +1

fin:

	leave
	ret
