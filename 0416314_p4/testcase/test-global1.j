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
.method public static ss()I
.limit locals 100
.limit stack 100
	ldc 0
	istore 0
	getstatic aa/a I
	getstatic aa/b I
	iadd
	istore 0
	iload 0
	ireturn
.end method
.method public static main([Ljava/lang/String;)V
	.limit locals 100
	.limit stack 100
	invokestatic aa/vinit()V
	ldc 3
	putstatic aa/a I
	ldc 4
	putstatic aa/b I
	invokestatic aa/ss()I
	putstatic aa/b I
	getstatic java/lang/System/out Ljava/io/PrintStream;
	getstatic aa/b I
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	return
.end method
