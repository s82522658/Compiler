.class public foo
.super java/lang/Object

.field public static g I
.method public static vinit()V
	.limit locals 100
	.limit stack 100
	ldc 0
	putstatic foo/g I
	return
.end method
.method public <init>()V
	aload_0
	invokenonvirtual java/lang/Object/<init>()V
	return
.end method
.method public static sum(II)V
.limit locals 100
.limit stack 100
	iload 0
	ldc 0
	if_icmpgt L0
	iload 1
	ldc 9
	iadd
	putstatic foo/g I
	goto L1
L0:
	iload 1
	ldc 3
	imul
	putstatic foo/g I
L1:
	return
.end method
.method public static main([Ljava/lang/String;)V
	.limit locals 100
	.limit stack 100
	invokestatic foo/vinit()V
	ldc 7
	putstatic foo/g I
	ldc 10
	ldc 32
	invokestatic foo/sum(II)V
	ldc -10
	ldc 21
	invokestatic foo/sum(II)V
	return
.end method
