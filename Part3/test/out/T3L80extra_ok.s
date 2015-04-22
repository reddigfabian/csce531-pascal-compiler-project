 #    2
 #    3
 #    4
 #    5
 #    6
 #    7
 #    8
 #    9
				# b_global_decl (C, alignment = 4, size = 4)
.globl C
	.data
	.align	4
	.type	C, @object
	.size	C, 4
C:
	.zero	4
				# b_global_decl (B, alignment = 4, size = 4)
.globl B
	.align	4
	.type	B, @object
	.size	B, 4
B:
	.zero	4
				# b_global_decl (A, alignment = 4, size = 4)
.globl A
	.align	4
	.type	A, @object
	.size	A, 4
A:
	.zero	4
 #   10
				# b_global_decl (X, alignment = 4, size = 4)
.globl X
	.align	4
	.type	X, @object
	.size	X, 4
X:
	.zero	4
 #   11
				# b_global_decl (Z, alignment = 4, size = 4)
.globl Z
	.align	4
	.type	Z, @object
	.size	Z, 4
Z:
	.zero	4
 #   12
				# b_global_decl (Ca, alignment = 1, size = 8)
.globl Ca
	.align	1
	.type	Ca, @object
	.size	Ca, 8
Ca:
	.zero	8
 #   13
				# b_global_decl (Ia, alignment = 4, size = 24)
.globl Ia
	.align	4
	.type	Ia, @object
	.size	Ia, 24
Ia:
	.zero	24
 #   14
				# b_global_decl (Ra, alignment = 8, size = 24)
.globl Ra
	.align	8
	.type	Ra, @object
	.size	Ra, 24
Ra:
	.zero	24
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
 #   29
 #   30
 #   31
 #   32
 #   33
 #   34
 #   35
				# b_func_prologue (main)
	.text
.global main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
 #   36
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
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
 #   37
				# b_push_ext_addr (B)
	subl	$8, %esp
	movl	$B, (%esp)
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
 #   38
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
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
 #   39
 #   40
.LC1:
				# b_push_ext_addr (B)
	subl	$8, %esp
	movl	$B, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (99)
	movl	$99, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( < , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_convert (signed long int -> signed char)
				# b_cond_jump (signed char, ZERO,
				#              .LC0)
	movsbl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	je	.LC0
 #   41
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (19)
	movl	$19, %eax
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
				#              .LC2)
	movsbl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	je	.LC2
 #   42
				# b_push_ext_addr (B)
	subl	$8, %esp
	movl	$B, (%esp)
				# b_push_ext_addr (B)
	subl	$8, %esp
	movl	$B, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (2)
	movl	$2, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( * , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	imull	%ecx, %eax
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   43
 #   44
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (3)
	movl	$3, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( + , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	addl	%ecx, %eax
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   45
				# b_jump ( destination = .LC3 )
	jmp	.LC3
.LC2:
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (9)
	movl	$9, %eax
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
				#              .LC4)
	movsbl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	je	.LC4
 #   46
				# b_push_ext_addr (B)
	subl	$8, %esp
	movl	$B, (%esp)
				# b_push_ext_addr (B)
	subl	$8, %esp
	movl	$B, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (5)
	movl	$5, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( - , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	subl	%ecx, %eax
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   47
 #   48
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( + , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	addl	%ecx, %eax
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   49
				# b_jump ( destination = .LC5 )
	jmp	.LC5
.LC4:
 #   50
				# b_push_ext_addr (B)
	subl	$8, %esp
	movl	$B, (%esp)
				# b_push_ext_addr (B)
	subl	$8, %esp
	movl	$B, (%esp)
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
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   51
 #   52
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (2)
	movl	$2, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( * , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	imull	%ecx, %eax
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
.LC5:
.LC3:
 #   53
 #   54
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_abc, void)
	call	Print_abc
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #   55
 #   56
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( + , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	addl	%ecx, %eax
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
				# b_jump ( destination = .LC1 )
	jmp	.LC1
.LC0:
 #   57
 #   58
				# b_push_ext_addr (X)
	subl	$8, %esp
	movl	$X, (%esp)
				# b_push_const_int (9)
	movl	$9, %eax
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
 #   59
 #   60
.LC7:
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_convert (signed long int -> signed char)
				# b_cond_jump (signed char, ZERO,
				#              .LC6)
	movsbl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	je	.LC6
 #   61
				# b_push_ext_addr (X)
	subl	$8, %esp
	movl	$X, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (0)
	movl	$0, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( < , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_convert (signed long int -> signed char)
				# b_cond_jump (signed char, ZERO,
				#              .LC8)
	movsbl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	je	.LC8
 #   62
				# b_jump ( destination = .LC6 )
	jmp	.LC6
.LC8:
 #   63
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_x, void)
	call	Print_x
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #   64
 #   65
				# b_push_ext_addr (X)
	subl	$8, %esp
	movl	$X, (%esp)
				# b_push_ext_addr (X)
	subl	$8, %esp
	movl	$X, (%esp)
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
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
				# b_jump ( destination = .LC7 )
	jmp	.LC7
.LC6:
 #   66
 #   67
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_push_const_int (-1)
	movl	$-1, %eax
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
 #   68
				# b_push_ext_addr (B)
	subl	$8, %esp
	movl	$B, (%esp)
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
				# b_pop ()
	addl	$8, %esp
 #   69
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
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
 #   70
 #   71
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_ext_addr (B)
	subl	$8, %esp
	movl	$B, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
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
				#              .LC9)
	movsbl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	je	.LC9
 #   72
 #   73
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
				# b_jump ( destination = .LC10 )
	jmp	.LC10
.LC9:
 #   74
				# b_push_ext_addr (B)
	subl	$8, %esp
	movl	$B, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
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
				#              .LC11)
	movsbl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	je	.LC11
 #   75
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_7, void)
	call	Print_7
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #   76
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_1, void)
	call	Print_1
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #   77
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_convert (signed long int -> signed char)
				# b_cond_jump (signed char, ZERO,
				#              .LC12)
	movsbl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	je	.LC12
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_2, void)
	call	Print_2
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
.LC12:
 #   78
 #   79
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_newline, void)
	call	Print_newline
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
				# b_jump ( destination = .LC13 )
	jmp	.LC13
.LC11:
 #   80
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
.LC13:
 #   81
 #   82
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_is, void)
	call	Print_is
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
.LC10:
 #   83
 #   84
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_grooviest, void)
	call	Print_grooviest
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #   85
 #   86
 #   87
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_push_const_int (-1)
	movl	$-1, %eax
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
 #   88
 #   89
.LC15:
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (3)
	movl	$3, %eax
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
				#              .LC14)
	movsbl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	je	.LC14
 #   90
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
				# b_jump ( destination = .LC15 )
	jmp	.LC15
.LC14:
 #   91
 #   92
.LC17:
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (3)
	movl	$3, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( < , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_convert (signed long int -> signed char)
				# b_cond_jump (signed char, ZERO,
				#              .LC16)
	movsbl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	je	.LC16
 #   93
 #   94
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_outer, void)
	call	Print_outer
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #   95
 #   96
				# b_push_ext_addr (B)
	subl	$8, %esp
	movl	$B, (%esp)
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
				# b_pop ()
	addl	$8, %esp
 #   97
.LC19:
				# b_push_ext_addr (B)
	subl	$8, %esp
	movl	$B, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( + , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	addl	%ecx, %eax
	movl	%eax, (%esp)
				# b_arith_rel_op ( < , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_convert (signed long int -> signed char)
				# b_cond_jump (signed char, ZERO,
				#              .LC18)
	movsbl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	je	.LC18
 #   98
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_inner, void)
	call	Print_inner
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #   99
 #  100
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
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
				# b_pop ()
	addl	$8, %esp
 #  101
.LC21:
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (5)
	movl	$5, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( < , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_convert (signed long int -> signed char)
				# b_cond_jump (signed char, ZERO,
				#              .LC20)
	movsbl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	je	.LC20
 #  102
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_inner_inner, void)
	call	Print_inner_inner
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #  103
 #  104
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( + , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	addl	%ecx, %eax
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
				# b_jump ( destination = .LC21 )
	jmp	.LC21
.LC20:
 #  105
 #  106
 #  107
				# b_push_ext_addr (B)
	subl	$8, %esp
	movl	$B, (%esp)
				# b_push_ext_addr (B)
	subl	$8, %esp
	movl	$B, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( + , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	addl	%ecx, %eax
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
				# b_jump ( destination = .LC19 )
	jmp	.LC19
.LC18:
 #  108
 #  109
 #  110
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_push_ext_addr (A)
	subl	$8, %esp
	movl	$A, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( + , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	addl	%ecx, %eax
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
				# b_jump ( destination = .LC17 )
	jmp	.LC17
.LC16:
 #  111
 #  112
 #  113
				# b_push_ext_addr (X)
	subl	$8, %esp
	movl	$X, (%esp)
				# b_push_const_int (9)
	movl	$9, %eax
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
 #  114
 #  115
.LC23:
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_convert (signed long int -> signed char)
				# b_cond_jump (signed char, ZERO,
				#              .LC22)
	movsbl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	je	.LC22
 #  116
				# b_push_ext_addr (X)
	subl	$8, %esp
	movl	$X, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (0)
	movl	$0, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( < , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_convert (signed long int -> signed char)
				# b_cond_jump (signed char, ZERO,
				#              .LC24)
	movsbl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	je	.LC24
				# b_jump ( destination = .LC22 )
	jmp	.LC22
.LC24:
 #  117
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_looping, void)
	call	Print_looping
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #  118
 #  119
				# b_push_ext_addr (X)
	subl	$8, %esp
	movl	$X, (%esp)
				# b_push_ext_addr (X)
	subl	$8, %esp
	movl	$X, (%esp)
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
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
				# b_jump ( destination = .LC23 )
	jmp	.LC23
.LC22:
 #  120
 #  121
				# b_push_ext_addr (X)
	subl	$8, %esp
	movl	$X, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (0)
	movl	$0, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( != , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setne	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_convert (signed long int -> signed char)
				# b_cond_jump (signed char, ZERO,
				#              .LC25)
	movsbl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	je	.LC25
 #  122
				# b_push_ext_addr (X)
	subl	$8, %esp
	movl	$X, (%esp)
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
				# b_pop ()
	addl	$8, %esp
.LC25:
 #  123
 #  124
 #  125
				# b_push_ext_addr (X)
	subl	$8, %esp
	movl	$X, (%esp)
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
 #  126
 #  127
.LC27:
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_convert (signed long int -> signed char)
				# b_cond_jump (signed char, ZERO,
				#              .LC26)
	movsbl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	je	.LC26
 #  128
				# b_push_ext_addr (X)
	subl	$8, %esp
	movl	$X, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (0)
	movl	$0, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( < , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	setl	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_convert (signed long int -> signed char)
				# b_cond_jump (signed char, ZERO,
				#              .LC28)
	movsbl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	je	.LC28
				# b_jump ( destination = .LC26 )
	jmp	.LC26
.LC28:
 #  129
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_looping, void)
	call	Print_looping
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #  130
				# b_push_ext_addr (B)
	subl	$8, %esp
	movl	$B, (%esp)
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
				# b_pop ()
	addl	$8, %esp
 #  131
 #  132
.LC30:
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_convert (signed long int -> signed char)
				# b_cond_jump (signed char, ZERO,
				#              .LC29)
	movsbl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	je	.LC29
 #  133
				# b_push_ext_addr (B)
	subl	$8, %esp
	movl	$B, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
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
				# b_jump ( destination = .LC29 )
	jmp	.LC29
.LC31:
 #  134
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_looping_looping, void)
	call	Print_looping_looping
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #  135
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
				# b_push_const_int (8)
	movl	$8, %eax
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
 #  136
 #  137
.LC33:
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_convert (signed long int -> signed char)
				# b_cond_jump (signed char, ZERO,
				#              .LC32)
	movsbl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	je	.LC32
 #  138
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (10)
	movl	$10, %eax
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
				#              .LC34)
	movsbl	(%esp), %eax
	addl	$8, %esp
	testl	%eax, %eax
	je	.LC34
				# b_jump ( destination = .LC32 )
	jmp	.LC32
.LC34:
 #  139
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (Print_looping_looping_looping, void)
	call	Print_looping_looping_looping
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
 #  140
 #  141
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
				# b_push_ext_addr (C)
	subl	$8, %esp
	movl	$C, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( + , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	addl	%ecx, %eax
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
				# b_jump ( destination = .LC33 )
	jmp	.LC33
.LC32:
 #  142
 #  143
				# b_push_ext_addr (B)
	subl	$8, %esp
	movl	$B, (%esp)
				# b_push_ext_addr (B)
	subl	$8, %esp
	movl	$B, (%esp)
				# b_deref (signed long int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( + , signed long int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	addl	%ecx, %eax
	movl	%eax, (%esp)
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
				# b_jump ( destination = .LC30 )
	jmp	.LC30
.LC29:
 #  144
 #  145
				# b_push_ext_addr (X)
	subl	$8, %esp
	movl	$X, (%esp)
				# b_push_ext_addr (X)
	subl	$8, %esp
	movl	$X, (%esp)
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
				# b_assign (signed long int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
				# b_jump ( destination = .LC27 )
	jmp	.LC27
.LC26:
 #  146
 #  147
				# b_func_epilogue (main)
	leave
	ret
	.size	main, .-main
 #  148
