 #    2
 #    3
 #    4
 #    5
 #    6
 #    7
 #    8
				# b_global_decl (J, alignment = 4, size = 4)
.globl J
	.data
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
				# b_func_prologue (main)
	.text
.global main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
 #   26
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
 #   27
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
 #   28
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
 #   29
 #   30
				# b_push_const_int (100)
	movl	$100, %eax
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
 #   31
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
 #   32
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (10)
	movl	$10, %eax
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
				#              .LC4)
	movsbl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	je	.LC4
 #   33
				# b_jump ( destination = .LC2 )
	jmp	.LC2
.LC4:
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
 #   34
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
 #   35
 #   36
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
 #   37
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
.LC6:
				# b_arith_rel_op ( < , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_cond_jump (signed long int, NON-ZERO,
				#              .LC5)
	movl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	jne	.LC5
 #   38
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
				# b_jump ( destination = .LC6 )
	jmp	.LC6
.LC5:
				# b_pop ()
	addl	$8, %esp
 #   39
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
 #   40
 #   41
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
.LC8:
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
				#              .LC7)
	movl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	jne	.LC7
 #   42
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
				# b_jump ( destination = .LC8 )
	jmp	.LC8
.LC7:
				# b_pop ()
	addl	$8, %esp
 #   43
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
 #   44
 #   45
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
.LC10:
				# b_arith_rel_op ( < , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_cond_jump (signed long int, NON-ZERO,
				#              .LC9)
	movl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	jne	.LC9
 #   46
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
 #   47
				# b_dispatch (  == ,signed long int, 8, .LC13, pop on jump )
	movl	(%esp), %edx
	movl	$8, %eax
	cmpl	%eax, %edx
	jne	.LC14
	addl	$8, %esp
				# b_jump ( destination = .LC13 )
	jmp	.LC13
.LC14:
				# b_dispatch (  == ,signed long int, 6, .LC13, pop on jump )
	movl	(%esp), %edx
	movl	$6, %eax
	cmpl	%eax, %edx
	jne	.LC15
	addl	$8, %esp
				# b_jump ( destination = .LC13 )
	jmp	.LC13
.LC15:
				# b_dispatch (  == ,signed long int, 4, .LC13, pop on jump )
	movl	(%esp), %edx
	movl	$4, %eax
	cmpl	%eax, %edx
	jne	.LC16
	addl	$8, %esp
				# b_jump ( destination = .LC13 )
	jmp	.LC13
.LC16:
				# b_dispatch (  == ,signed long int, 2, .LC13, pop on jump )
	movl	(%esp), %edx
	movl	$2, %eax
	cmpl	%eax, %edx
	jne	.LC17
	addl	$8, %esp
				# b_jump ( destination = .LC13 )
	jmp	.LC13
.LC17:
				# b_dispatch (  == ,signed long int, 0, .LC13, pop on jump )
	movl	(%esp), %edx
	movl	$0, %eax
	cmpl	%eax, %edx
	jne	.LC18
	addl	$8, %esp
				# b_jump ( destination = .LC13 )
	jmp	.LC13
.LC18:
				# b_jump ( destination = .LC12 )
	jmp	.LC12
.LC13:
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
				# b_jump ( destination = .LC11 )
	jmp	.LC11
.LC12:
 #   48
				# b_dispatch (  == ,signed long int, 9, .LC20, pop on jump )
	movl	(%esp), %edx
	movl	$9, %eax
	cmpl	%eax, %edx
	jne	.LC21
	addl	$8, %esp
				# b_jump ( destination = .LC20 )
	jmp	.LC20
.LC21:
				# b_dispatch (  == ,signed long int, 7, .LC20, pop on jump )
	movl	(%esp), %edx
	movl	$7, %eax
	cmpl	%eax, %edx
	jne	.LC22
	addl	$8, %esp
				# b_jump ( destination = .LC20 )
	jmp	.LC20
.LC22:
				# b_dispatch (  == ,signed long int, 5, .LC20, pop on jump )
	movl	(%esp), %edx
	movl	$5, %eax
	cmpl	%eax, %edx
	jne	.LC23
	addl	$8, %esp
				# b_jump ( destination = .LC20 )
	jmp	.LC20
.LC23:
				# b_dispatch (  == ,signed long int, 3, .LC20, pop on jump )
	movl	(%esp), %edx
	movl	$3, %eax
	cmpl	%eax, %edx
	jne	.LC24
	addl	$8, %esp
				# b_jump ( destination = .LC20 )
	jmp	.LC20
.LC24:
				# b_dispatch (  == ,signed long int, 1, .LC20, pop on jump )
	movl	(%esp), %edx
	movl	$1, %eax
	cmpl	%eax, %edx
	jne	.LC25
	addl	$8, %esp
				# b_jump ( destination = .LC20 )
	jmp	.LC20
.LC25:
				# b_jump ( destination = .LC19 )
	jmp	.LC19
.LC20:
 #   49
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
				# b_jump ( destination = .LC11 )
	jmp	.LC11
.LC19:
				# b_pop ()
	addl	$8, %esp
.LC11:
 #   50
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
				#              .LC26)
	movsbl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	je	.LC26
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
.LC26:
 #   51
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
.LC28:
				# b_arith_rel_op ( < , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_cond_jump (signed long int, NON-ZERO,
				#              .LC27)
	movl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	jne	.LC27
 #   52
				# b_push_ext_addr (J)
	subl	$8, %esp
	movl	$J, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (7)
	movl	$7, %eax
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
				#              .LC29)
	movsbl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	je	.LC29
 #   53
				# b_jump ( destination = .LC27 )
	jmp	.LC27
				# b_jump ( destination = .LC30 )
	jmp	.LC30
.LC29:
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
.LC30:
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
				# b_jump ( destination = .LC28 )
	jmp	.LC28
.LC27:
				# b_pop ()
	addl	$8, %esp
 #   54
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (99)
	movl	$99, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( > , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setg	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_convert (signed long int -> signed char)
				# b_cond_jump (signed char, ZERO,
				#              .LC31)
	movsbl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	je	.LC31
 #   55
				# b_jump ( destination = .LC9 )
	jmp	.LC9
.LC31:
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
				# b_jump ( destination = .LC10 )
	jmp	.LC10
.LC9:
				# b_pop ()
	addl	$8, %esp
 #   56
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
 #   57
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
 #   58
 #   59
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
.LC33:
				# b_arith_rel_op ( > , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setg	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_cond_jump (signed long int, NON-ZERO,
				#              .LC32)
	movl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	jne	.LC32
 #   60
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
				# b_jump ( destination = .LC33 )
	jmp	.LC33
.LC32:
				# b_pop ()
	addl	$8, %esp
 #   61
 #   62
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
				# b_jump ( destination = .LC35 )
	jmp	.LC35
.LC34:
				# b_pop ()
	addl	$8, %esp
 #   63
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
 #   64
 #   65
				# b_push_const_int (0)
	movl	$0, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
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
.LC37:
				# b_arith_rel_op ( > , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setg	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_cond_jump (signed long int, NON-ZERO,
				#              .LC36)
	movl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	jne	.LC36
 #   66
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
 #   67
				# b_dispatch (  == ,signed long int, 10, .LC40, pop on jump )
	movl	(%esp), %edx
	movl	$10, %eax
	cmpl	%eax, %edx
	jne	.LC41
	addl	$8, %esp
				# b_jump ( destination = .LC40 )
	jmp	.LC40
.LC41:
				# b_dispatch (  == ,signed long int, 8, .LC40, pop on jump )
	movl	(%esp), %edx
	movl	$8, %eax
	cmpl	%eax, %edx
	jne	.LC42
	addl	$8, %esp
				# b_jump ( destination = .LC40 )
	jmp	.LC40
.LC42:
				# b_dispatch (  == ,signed long int, 6, .LC40, pop on jump )
	movl	(%esp), %edx
	movl	$6, %eax
	cmpl	%eax, %edx
	jne	.LC43
	addl	$8, %esp
				# b_jump ( destination = .LC40 )
	jmp	.LC40
.LC43:
				# b_dispatch (  == ,signed long int, 4, .LC40, pop on jump )
	movl	(%esp), %edx
	movl	$4, %eax
	cmpl	%eax, %edx
	jne	.LC44
	addl	$8, %esp
				# b_jump ( destination = .LC40 )
	jmp	.LC40
.LC44:
				# b_dispatch (  == ,signed long int, 2, .LC40, pop on jump )
	movl	(%esp), %edx
	movl	$2, %eax
	cmpl	%eax, %edx
	jne	.LC45
	addl	$8, %esp
				# b_jump ( destination = .LC40 )
	jmp	.LC40
.LC45:
				# b_dispatch (  == ,signed long int, 0, .LC40, pop on jump )
	movl	(%esp), %edx
	movl	$0, %eax
	cmpl	%eax, %edx
	jne	.LC46
	addl	$8, %esp
				# b_jump ( destination = .LC40 )
	jmp	.LC40
.LC46:
				# b_jump ( destination = .LC39 )
	jmp	.LC39
.LC40:
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
				# b_jump ( destination = .LC38 )
	jmp	.LC38
.LC39:
 #   68
				# b_dispatch (  == ,signed long int, 9, .LC48, pop on jump )
	movl	(%esp), %edx
	movl	$9, %eax
	cmpl	%eax, %edx
	jne	.LC49
	addl	$8, %esp
				# b_jump ( destination = .LC48 )
	jmp	.LC48
.LC49:
				# b_dispatch (  == ,signed long int, 7, .LC48, pop on jump )
	movl	(%esp), %edx
	movl	$7, %eax
	cmpl	%eax, %edx
	jne	.LC50
	addl	$8, %esp
				# b_jump ( destination = .LC48 )
	jmp	.LC48
.LC50:
				# b_dispatch (  == ,signed long int, 3, .LC48, pop on jump )
	movl	(%esp), %edx
	movl	$3, %eax
	cmpl	%eax, %edx
	jne	.LC51
	addl	$8, %esp
				# b_jump ( destination = .LC48 )
	jmp	.LC48
.LC51:
				# b_dispatch (  == ,signed long int, 1, .LC48, pop on jump )
	movl	(%esp), %edx
	movl	$1, %eax
	cmpl	%eax, %edx
	jne	.LC52
	addl	$8, %esp
				# b_jump ( destination = .LC48 )
	jmp	.LC48
.LC52:
				# b_jump ( destination = .LC47 )
	jmp	.LC47
.LC48:
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
				# b_jump ( destination = .LC38 )
	jmp	.LC38
.LC47:
 #   69
				# b_dispatch (  == ,signed long int, 5, .LC54, pop on jump )
	movl	(%esp), %edx
	movl	$5, %eax
	cmpl	%eax, %edx
	jne	.LC55
	addl	$8, %esp
				# b_jump ( destination = .LC54 )
	jmp	.LC54
.LC55:
				# b_jump ( destination = .LC53 )
	jmp	.LC53
.LC54:
				# b_jump ( destination = .LC36 )
	jmp	.LC36
				# b_jump ( destination = .LC38 )
	jmp	.LC38
.LC53:
 #   70
				# b_pop ()
	addl	$8, %esp
.LC38:
 #   71
 #   72
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
				# b_duplicate (signed long int)
	movl	(%esp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_ext_addr (I)
	subl	$8, %esp
	movl	$I, (%esp)
				# b_inc_dec (signed long int, PRE-DEC)
	movl	(%esp), %edx
	movl	(%edx), %eax
	subl	$1, %eax
	movl	%eax, (%esp)
	movl	%eax, (%edx)
				# b_jump ( destination = .LC37 )
	jmp	.LC37
.LC36:
				# b_pop ()
	addl	$8, %esp
 #   73
 #   74
				# b_func_epilogue (main)
	leave
	ret
	.size	main, .-main
 #   75
