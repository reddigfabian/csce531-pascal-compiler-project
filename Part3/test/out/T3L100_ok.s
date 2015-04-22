 #    2
 #    3
 #    4
 #    5
 #    6
 #    7
 #    8
				# b_global_decl (K, alignment = 4, size = 4)
.globl K
	.data
	.align	4
	.type	K, @object
	.size	K, 4
K:
	.zero	4
				# b_global_decl (J, alignment = 4, size = 4)
.globl J
	.align	4
	.type	J, @object
	.size	J, 4
J:
	.zero	4
				# b_global_decl (I, alignment = 4, size = 4)
.globl I
	.align	4
	.type	I, @object
	.size	I, 4
I:
	.zero	4
 #    9
				# b_global_decl (F, alignment = 4, size = 4)
.globl F
	.align	4
	.type	F, @object
	.size	F, 4
F:
	.zero	4
 #   10
				# b_global_decl (C, alignment = 1, size = 1)
.globl C
	.align	1
	.type	C, @object
	.size	C, 1
C:
	.zero	1
 #   11
				# b_global_decl (Iaa, alignment = 4, size = 672)
.globl Iaa
	.align	4
	.type	Iaa, @object
	.size	Iaa, 672
Iaa:
	.zero	672
 #   12
				# b_global_decl (Raaa, alignment = 8, size = 576)
.globl Raaa
	.align	8
	.type	Raaa, @object
	.size	Raaa, 576
Raaa:
	.zero	576
 #   13
				# b_global_decl (R, alignment = 8, size = 8)
.globl R
	.align	8
	.type	R, @object
	.size	R, 8
R:
	.zero	8
 #   14
 #   15
 #   16
 #   17
 #   18
 #   19
 #   20
 #   21
 #   22
 #   23
 #   24
 #   25
 #   26
 #   27
 #   28
				# b_func_prologue (main)
	.text
.global main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
 #   29
				# b_push_const_int (10)
	movl	$10, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
.LC1:
				# b_arith_rel_op ( < , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_cond_jump (signed long int, NON-ZERO,
				#              .LC0)
	movl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	jne	.LC0
 #   30
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_dot, void)
	call	Print_dot
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_inc_dec (signed long int, PRE-INC)
	movl	(%esp), %edx
	movl	(%edx), %eax
	addl	$1, %eax
	movl	%eax, (%esp)
	movl	%eax, (%edx)
				# b_jump ( destination = .LC1 )
	jmp	.LC1
.LC0:
				# b_pop ()
	addl	$8, %esp
 #   31
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_nl, void)
	call	Print_nl
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #   32
 #   33
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_push_const_int (15)
	movl	$15, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   34
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
.LC3:
				# b_arith_rel_op ( < , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_cond_jump (signed long int, NON-ZERO,
				#              .LC2)
	movl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	jne	.LC2
 #   35
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_dot, void)
	call	Print_dot
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_inc_dec (signed long int, PRE-INC)
	movl	(%esp), %edx
	movl	(%edx), %eax
	addl	$1, %eax
	movl	%eax, (%esp)
	movl	%eax, (%edx)
				# b_jump ( destination = .LC3 )
	jmp	.LC3
.LC2:
				# b_pop ()
	addl	$8, %esp
 #   36
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_nl, void)
	call	Print_nl
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #   37
 #   38
				# b_push_const_int (10)
	movl	$10, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_convert (signed long int -> unsigned char)
				# b_convert (unsigned char -> signed long int)
	movzbl	(%esp), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_convert (signed long int -> unsigned char)
				# b_assign (unsigned char)
	movzbl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movb	%dl, (%eax)
	movb	%dl, (%esp)
.LC5:
				# b_convert (unsigned char -> signed long int)
	movzbl	(%esp), %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_arith_rel_op ( < , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_cond_jump (signed long int, NON-ZERO,
				#              .LC4)
	movl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	jne	.LC4
 #   39
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_dot, void)
	call	Print_dot
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
				# b_inc_dec (unsigned char, PRE-INC)
	movl	(%esp), %edx
	movzbl	(%edx), %eax
	addl	$1, %eax
	movb	%al, (%esp)
	movb	%al, (%edx)
				# b_jump ( destination = .LC5 )
	jmp	.LC5
.LC4:
				# b_pop ()
	addl	$8, %esp
 #   40
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_nl, void)
	call	Print_nl
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #   41
 #   42
				# b_push_const_int (9)
	movl	$9, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_push_const_int (0)
	movl	$0, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
.LC7:
				# b_arith_rel_op ( < , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_cond_jump (signed long int, NON-ZERO,
				#              .LC6)
	movl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	jne	.LC6
 #   43
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
 #   44
				# b_dispatch (  == ,signed long int, 8, .LC10, pop on jump )
	movl	(%esp), %edx
	movl	$8, %eax
	cmpl	%eax, %edx
	jne	.LC11
	addl	$8, %esp
				# b_jump ( destination = .LC10 )
	jmp	.LC10
.LC11:
				# b_dispatch (  == ,signed long int, 6, .LC10, pop on jump )
	movl	(%esp), %edx
	movl	$6, %eax
	cmpl	%eax, %edx
	jne	.LC12
	addl	$8, %esp
				# b_jump ( destination = .LC10 )
	jmp	.LC10
.LC12:
				# b_dispatch (  == ,signed long int, 4, .LC10, pop on jump )
	movl	(%esp), %edx
	movl	$4, %eax
	cmpl	%eax, %edx
	jne	.LC13
	addl	$8, %esp
				# b_jump ( destination = .LC10 )
	jmp	.LC10
.LC13:
				# b_dispatch (  == ,signed long int, 2, .LC10, pop on jump )
	movl	(%esp), %edx
	movl	$2, %eax
	cmpl	%eax, %edx
	jne	.LC14
	addl	$8, %esp
				# b_jump ( destination = .LC10 )
	jmp	.LC10
.LC14:
				# b_dispatch (  == ,signed long int, 0, .LC10, pop on jump )
	movl	(%esp), %edx
	movl	$0, %eax
	cmpl	%eax, %edx
	jne	.LC15
	addl	$8, %esp
				# b_jump ( destination = .LC10 )
	jmp	.LC10
.LC15:
				# b_jump ( destination = .LC9 )
	jmp	.LC9
.LC10:
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_even, void)
	call	Print_even
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_jump ( destination = .LC8 )
	jmp	.LC8
.LC9:
 #   45
				# b_dispatch (  == ,signed long int, 9, .LC17, pop on jump )
	movl	(%esp), %edx
	movl	$9, %eax
	cmpl	%eax, %edx
	jne	.LC18
	addl	$8, %esp
				# b_jump ( destination = .LC17 )
	jmp	.LC17
.LC18:
				# b_dispatch (  == ,signed long int, 7, .LC17, pop on jump )
	movl	(%esp), %edx
	movl	$7, %eax
	cmpl	%eax, %edx
	jne	.LC19
	addl	$8, %esp
				# b_jump ( destination = .LC17 )
	jmp	.LC17
.LC19:
				# b_dispatch (  == ,signed long int, 5, .LC17, pop on jump )
	movl	(%esp), %edx
	movl	$5, %eax
	cmpl	%eax, %edx
	jne	.LC20
	addl	$8, %esp
				# b_jump ( destination = .LC17 )
	jmp	.LC17
.LC20:
				# b_dispatch (  == ,signed long int, 3, .LC17, pop on jump )
	movl	(%esp), %edx
	movl	$3, %eax
	cmpl	%eax, %edx
	jne	.LC21
	addl	$8, %esp
				# b_jump ( destination = .LC17 )
	jmp	.LC17
.LC21:
				# b_dispatch (  == ,signed long int, 1, .LC17, pop on jump )
	movl	(%esp), %edx
	movl	$1, %eax
	cmpl	%eax, %edx
	jne	.LC22
	addl	$8, %esp
				# b_jump ( destination = .LC17 )
	jmp	.LC17
.LC22:
				# b_jump ( destination = .LC16 )
	jmp	.LC16
.LC17:
 #   46
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_odd, void)
	call	Print_odd
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_jump ( destination = .LC8 )
	jmp	.LC8
.LC16:
				# b_pop ()
	addl	$8, %esp
.LC8:
 #   47
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( == , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_convert (signed long int -> signed char)
				# b_cond_jump (signed char, ZERO,
				#              .LC23)
	movsbl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	je	.LC23
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_push_const_int (3)
	movl	$3, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
.LC23:
 #   48
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( - , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	subl	%ecx, %eax
	movl	%eax, (%esp)
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (J)
	subl	$8, %esp
	movl	$J, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
.LC25:
				# b_arith_rel_op ( < , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_cond_jump (signed long int, NON-ZERO,
				#              .LC24)
	movl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	jne	.LC24
 #   49
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_j, void)
	call	Print_j
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (J)
	subl	$8, %esp
	movl	$J, (%esp)
				# b_inc_dec (signed long int, PRE-INC)
	movl	(%esp), %edx
	movl	(%edx), %eax
	addl	$1, %eax
	movl	%eax, (%esp)
	movl	%eax, (%edx)
				# b_jump ( destination = .LC25 )
	jmp	.LC25
.LC24:
				# b_pop ()
	addl	$8, %esp
 #   50
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_inc_dec (signed long int, PRE-INC)
	movl	(%esp), %edx
	movl	(%edx), %eax
	addl	$1, %eax
	movl	%eax, (%esp)
	movl	%eax, (%edx)
				# b_jump ( destination = .LC7 )
	jmp	.LC7
.LC6:
				# b_pop ()
	addl	$8, %esp
 #   51
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_nl, void)
	call	Print_nl
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #   52
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_i_j_values, void)
	call	Print_i_j_values
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #   53
 #   54
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (J)
	subl	$8, %esp
	movl	$J, (%esp)
				# b_push_const_int (10)
	movl	$10, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
.LC27:
				# b_arith_rel_op ( > , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setg	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_cond_jump (signed long int, NON-ZERO,
				#              .LC26)
	movl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	jne	.LC26
 #   55
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_i_j_values, void)
	call	Print_i_j_values
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (J)
	subl	$8, %esp
	movl	$J, (%esp)
				# b_inc_dec (signed long int, PRE-DEC)
	movl	(%esp), %edx
	movl	(%edx), %eax
	subl	$1, %eax
	movl	%eax, (%esp)
	movl	%eax, (%edx)
				# b_jump ( destination = .LC27 )
	jmp	.LC27
.LC26:
				# b_pop ()
	addl	$8, %esp
 #   56
 #   57
				# b_push_const_int (9)
	movl	$9, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_push_const_int (0)
	movl	$0, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
.LC29:
				# b_arith_rel_op ( < , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_cond_jump (signed long int, NON-ZERO,
				#              .LC28)
	movl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	jne	.LC28
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_inc_dec (signed long int, PRE-INC)
	movl	(%esp), %edx
	movl	(%edx), %eax
	addl	$1, %eax
	movl	%eax, (%esp)
	movl	%eax, (%edx)
				# b_jump ( destination = .LC29 )
	jmp	.LC29
.LC28:
				# b_pop ()
	addl	$8, %esp
 #   58
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_oops, void)
	call	Print_oops
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #   59
 #   60
 #   61
				# b_push_const_int (11)
	movl	$11, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (J)
	subl	$8, %esp
	movl	$J, (%esp)
				# b_push_const_int (0)
	movl	$0, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
.LC31:
				# b_arith_rel_op ( < , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_cond_jump (signed long int, NON-ZERO,
				#              .LC30)
	movl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	jne	.LC30
 #   62
				# b_push_ext_addr (Iaa)
	subl	$8, %esp
	movl	$Iaa, (%esp)
				# b_push_const_int (0)
	movl	$0, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_const_int (0)
	movl	$0, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( - , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	subl	%ecx, %eax
	movl	%eax, (%esp)
				# b_ptr_arith_op ( + , signed long int, size = 48)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	imull	$48, %edx, %edx
	addl	%edx, %eax
	movl	%eax, (%esp)
				# b_push_ext_addr (J)
	subl	$8, %esp
	movl	$J, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (0)
	movl	$0, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( - , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	subl	%ecx, %eax
	movl	%eax, (%esp)
				# b_ptr_arith_op ( + , signed long int, size = 4)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	imull	$4, %edx, %edx
	addl	%edx, %eax
	movl	%eax, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (J)
	subl	$8, %esp
	movl	$J, (%esp)
				# b_inc_dec (signed long int, PRE-INC)
	movl	(%esp), %edx
	movl	(%edx), %eax
	addl	$1, %eax
	movl	%eax, (%esp)
	movl	%eax, (%edx)
				# b_jump ( destination = .LC31 )
	jmp	.LC31
.LC30:
				# b_pop ()
	addl	$8, %esp
 #   63
				# b_push_const_int (13)
	movl	$13, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
.LC33:
				# b_arith_rel_op ( < , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_cond_jump (signed long int, NON-ZERO,
				#              .LC32)
	movl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	jne	.LC32
 #   64
				# b_push_ext_addr (Iaa)
	subl	$8, %esp
	movl	$Iaa, (%esp)
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (0)
	movl	$0, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( - , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	subl	%ecx, %eax
	movl	%eax, (%esp)
				# b_ptr_arith_op ( + , signed long int, size = 48)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	imull	$48, %edx, %edx
	addl	%edx, %eax
	movl	%eax, (%esp)
				# b_push_const_int (0)
	movl	$0, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_const_int (0)
	movl	$0, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( - , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	subl	%ecx, %eax
	movl	%eax, (%esp)
				# b_ptr_arith_op ( + , signed long int, size = 4)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	imull	$4, %edx, %edx
	addl	%edx, %eax
	movl	%eax, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   65
				# b_push_const_int (11)
	movl	$11, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (J)
	subl	$8, %esp
	movl	$J, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
.LC35:
				# b_arith_rel_op ( < , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_cond_jump (signed long int, NON-ZERO,
				#              .LC34)
	movl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	jne	.LC34
 #   66
 #   67
				# b_push_ext_addr (Iaa)
	subl	$8, %esp
	movl	$Iaa, (%esp)
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (0)
	movl	$0, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( - , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	subl	%ecx, %eax
	movl	%eax, (%esp)
				# b_ptr_arith_op ( + , signed long int, size = 48)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	imull	$48, %edx, %edx
	addl	%edx, %eax
	movl	%eax, (%esp)
				# b_push_ext_addr (J)
	subl	$8, %esp
	movl	$J, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (0)
	movl	$0, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( - , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	subl	%ecx, %eax
	movl	%eax, (%esp)
				# b_ptr_arith_op ( + , signed long int, size = 4)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	imull	$4, %edx, %edx
	addl	%edx, %eax
	movl	%eax, (%esp)
				# b_push_ext_addr (Iaa)
	subl	$8, %esp
	movl	$Iaa, (%esp)
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (0)
	movl	$0, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( - , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	subl	%ecx, %eax
	movl	%eax, (%esp)
				# b_ptr_arith_op ( + , signed long int, size = 48)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	imull	$48, %edx, %edx
	addl	%edx, %eax
	movl	%eax, (%esp)
				# b_push_ext_addr (J)
	subl	$8, %esp
	movl	$J, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( - , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	subl	%ecx, %eax
	movl	%eax, (%esp)
				# b_push_const_int (0)
	movl	$0, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( - , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	subl	%ecx, %eax
	movl	%eax, (%esp)
				# b_ptr_arith_op ( + , signed long int, size = 4)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	imull	$4, %edx, %edx
	addl	%edx, %eax
	movl	%eax, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_ext_addr (Iaa)
	subl	$8, %esp
	movl	$Iaa, (%esp)
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( - , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	subl	%ecx, %eax
	movl	%eax, (%esp)
				# b_push_const_int (0)
	movl	$0, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( - , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	subl	%ecx, %eax
	movl	%eax, (%esp)
				# b_ptr_arith_op ( + , signed long int, size = 48)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	imull	$48, %edx, %edx
	addl	%edx, %eax
	movl	%eax, (%esp)
				# b_push_ext_addr (J)
	subl	$8, %esp
	movl	$J, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (0)
	movl	$0, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( - , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	subl	%ecx, %eax
	movl	%eax, (%esp)
				# b_ptr_arith_op ( + , signed long int, size = 4)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	imull	$4, %edx, %edx
	addl	%edx, %eax
	movl	%eax, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_arith_rel_op ( + , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	addl	%ecx, %eax
	movl	%eax, (%esp)
				# b_push_const_int (10000)
	movl	$10000, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( % , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%eax, %edx
	sarl	$31, %edx
	idivl	%ecx
	movl	%edx, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (J)
	subl	$8, %esp
	movl	$J, (%esp)
				# b_inc_dec (signed long int, PRE-INC)
	movl	(%esp), %edx
	movl	(%edx), %eax
	addl	$1, %eax
	movl	%eax, (%esp)
	movl	%eax, (%edx)
				# b_jump ( destination = .LC35 )
	jmp	.LC35
.LC34:
				# b_pop ()
	addl	$8, %esp
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_inc_dec (signed long int, PRE-INC)
	movl	(%esp), %edx
	movl	(%edx), %eax
	addl	$1, %eax
	movl	%eax, (%esp)
	movl	%eax, (%edx)
				# b_jump ( destination = .LC33 )
	jmp	.LC33
.LC32:
				# b_pop ()
	addl	$8, %esp
 #   68
 #   69
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_iaa, void)
	call	Print_iaa
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #   70
 #   71
				# b_push_ext_addr (R)
	subl	$8, %esp
	movl	$R, (%esp)
				# b_push_const_double (9.0000000000000000e+00)
	.section	.rodata
	.align	8
.LC36:
	.long	0
	.long	1075970048
	.text
	fldl	.LC36
	subl	$8, %esp
	fstpl	(%esp)
				# b_assign (double)
	fldl	(%esp)
	addl	$8, %esp
	movl	(%esp), %eax
	fstpl	(%eax)
	fstpl	(%esp)
				# b_pop ()
	addl	$8, %esp
 #   72
				# b_push_const_int (4)
	movl	$4, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_push_const_int (2)
	movl	$2, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
.LC38:
				# b_arith_rel_op ( < , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_cond_jump (signed long int, NON-ZERO,
				#              .LC37)
	movl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	jne	.LC37
 #   73
				# b_push_const_int (5)
	movl	$5, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (J)
	subl	$8, %esp
	movl	$J, (%esp)
				# b_push_const_int (0)
	movl	$0, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
.LC40:
				# b_arith_rel_op ( < , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_cond_jump (signed long int, NON-ZERO,
				#              .LC39)
	movl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	jne	.LC39
 #   74
				# b_push_const_int (4)
	movl	$4, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (K)
	subl	$8, %esp
	movl	$K, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
.LC42:
				# b_arith_rel_op ( < , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_cond_jump (signed long int, NON-ZERO,
				#              .LC41)
	movl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	jne	.LC41
 #   75
				# b_push_ext_addr (Raaa)
	subl	$8, %esp
	movl	$Raaa, (%esp)
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (2)
	movl	$2, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( - , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	subl	%ecx, %eax
	movl	%eax, (%esp)
				# b_ptr_arith_op ( + , signed long int, size = 192)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	imull	$192, %edx, %edx
	addl	%edx, %eax
	movl	%eax, (%esp)
				# b_push_ext_addr (J)
	subl	$8, %esp
	movl	$J, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (0)
	movl	$0, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( - , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	subl	%ecx, %eax
	movl	%eax, (%esp)
				# b_ptr_arith_op ( + , signed long int, size = 32)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	imull	$32, %edx, %edx
	addl	%edx, %eax
	movl	%eax, (%esp)
				# b_push_ext_addr (K)
	subl	$8, %esp
	movl	$K, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( - , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	subl	%ecx, %eax
	movl	%eax, (%esp)
				# b_ptr_arith_op ( + , signed long int, size = 8)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	imull	$8, %edx, %edx
	addl	%edx, %eax
	movl	%eax, (%esp)
				# b_push_ext_addr (R)
	subl	$8, %esp
	movl	$R, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_assign (double)
	fldl	(%esp)
	addl	$8, %esp
	movl	(%esp), %eax
	fstpl	(%eax)
	fstpl	(%esp)
				# b_pop ()
	addl	$8, %esp
 #   76
 #   77
				# b_push_ext_addr (R)
	subl	$8, %esp
	movl	$R, (%esp)
				# b_push_ext_addr (R)
	subl	$8, %esp
	movl	$R, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_push_const_double (9.0000000000000002e-01)
	.section	.rodata
	.align	8
.LC43:
	.long	-858993459
	.long	1072483532
	.text
	fldl	.LC43
	subl	$8, %esp
	fstpl	(%esp)
				# b_arith_rel_op ( * , double)
	fldl	8(%esp)
	fldl	(%esp)
	addl	$8, %esp
	fmulp	%st, %st(1)
	fstpl	(%esp)
				# b_assign (double)
	fldl	(%esp)
	addl	$8, %esp
	movl	(%esp), %eax
	fstpl	(%eax)
	fstpl	(%esp)
				# b_pop ()
	addl	$8, %esp
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (K)
	subl	$8, %esp
	movl	$K, (%esp)
				# b_inc_dec (signed long int, PRE-INC)
	movl	(%esp), %edx
	movl	(%edx), %eax
	addl	$1, %eax
	movl	%eax, (%esp)
	movl	%eax, (%edx)
				# b_jump ( destination = .LC42 )
	jmp	.LC42
.LC41:
				# b_pop ()
	addl	$8, %esp
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (J)
	subl	$8, %esp
	movl	$J, (%esp)
				# b_inc_dec (signed long int, PRE-INC)
	movl	(%esp), %edx
	movl	(%edx), %eax
	addl	$1, %eax
	movl	%eax, (%esp)
	movl	%eax, (%edx)
				# b_jump ( destination = .LC40 )
	jmp	.LC40
.LC39:
				# b_pop ()
	addl	$8, %esp
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_inc_dec (signed long int, PRE-INC)
	movl	(%esp), %edx
	movl	(%edx), %eax
	addl	$1, %eax
	movl	%eax, (%esp)
	movl	%eax, (%edx)
				# b_jump ( destination = .LC38 )
	jmp	.LC38
.LC37:
				# b_pop ()
	addl	$8, %esp
 #   78
 #   79
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_raaa, void)
	call	Print_raaa
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #   80
 #   81
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   82
				# b_push_ext_addr (J)
	subl	$8, %esp
	movl	$J, (%esp)
				# b_push_const_int (2)
	movl	$2, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   83
				# b_push_ext_addr (R)
	subl	$8, %esp
	movl	$R, (%esp)
				# b_push_ext_addr (Raaa)
	subl	$8, %esp
	movl	$Raaa, (%esp)
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (3)
	movl	$3, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( * , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	imull	%ecx, %eax
	movl	%eax, (%esp)
				# b_push_const_int (2)
	movl	$2, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( - , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	subl	%ecx, %eax
	movl	%eax, (%esp)
				# b_ptr_arith_op ( + , signed long int, size = 192)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	imull	$192, %edx, %edx
	addl	%edx, %eax
	movl	%eax, (%esp)
				# b_push_const_int (2)
	movl	$2, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (J)
	subl	$8, %esp
	movl	$J, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_arith_rel_op ( * , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	imull	%ecx, %eax
	movl	%eax, (%esp)
				# b_push_const_int (0)
	movl	$0, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( - , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	subl	%ecx, %eax
	movl	%eax, (%esp)
				# b_ptr_arith_op ( + , signed long int, size = 32)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	imull	$32, %edx, %edx
	addl	%edx, %eax
	movl	%eax, (%esp)
				# b_push_const_int (3)
	movl	$3, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( - , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	subl	%ecx, %eax
	movl	%eax, (%esp)
				# b_ptr_arith_op ( + , signed long int, size = 8)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	imull	$8, %edx, %edx
	addl	%edx, %eax
	movl	%eax, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_assign (double)
	fldl	(%esp)
	addl	$8, %esp
	movl	(%esp), %eax
	fstpl	(%eax)
	fstpl	(%esp)
				# b_pop ()
	addl	$8, %esp
 #   84
 #   85
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_r, void)
	call	Print_r
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #   86
 #   87
				# b_func_epilogue (main)
	leave
	ret
	.size	main, .-main
 #   88
