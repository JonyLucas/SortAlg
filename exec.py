import subprocess as sp
import shlex

print("Escolha o algoritmo de Ordenacao: \n" + "(1) - Insertion\n" + "(2) - Selecion\n" + "(3) - Quick\n" + "(4) - Merge\n" + "(5) - Heap : ")

arg = input()

sp.call(["make"])
#sp.call(["./algsort", str(arg) ,input="< example.in", output="> saida.out"])
cmd = "./algsort " + str(arg) + " < example.in > saida.txt"
args = shlex.split(cmd)
print (args)
sp.Popen(args)
