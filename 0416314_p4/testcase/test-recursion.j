.class public aa
.super java/lang/Object

.field public static c F
.field public static a I
.field public static b I
.method public static vinit()V
	.limit locals 100
	.limit stack 100
	ldc 0.0
	putstatic aa/c F
	ldc 0
	putstatic aa/a I
	ldc 0
	putstatic aa/b I
	return
.end method
.method public <init>()V
	aload_0
	invokenonvirtual java/lang/Object/<init>()V
	return
.end method
.method public static fact(I)I
.limit locals 100
.limit stack 100
	ldc 0
	istore 1
	iload 0
	ldc 1
	if_icmpne L0
	iload 0
	istore 1
	goto L1
L0:
	iload 0
	iload 0
	ldc 1
	isub
	invokestatic aa/fact(I)I
	imul
	istore 1
L1:
	iload 1
	ireturn
.end method
.method public static main([Ljava/lang/String;)V
	.limit locals 100
	.limit stack 100
	invokestatic aa/vinit()V
	ldc 3
	invokestatic aa/fact(I)I
	putstatic aa/a I
	getstatic java/lang/System/out Ljava/io/PrintStream;
	getstatic aa/a I
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	return
.end method
