import subprocess as sp
from glob import glob
import sys

if (len(sys.argv) == 1):
	filepath = ""
else:
	filepath = str(sys.argv[1])

sp.call(["make"])

print("Escolha o algoritmo de Ordenacao: \n" + "(0) - Todos\n" + "(1) - Insertion\n" + "(2) - Selecion\n" + "(3) - Quick\n" + "(4) - Merge\n" 
+ "(5) - Heap\n" + "(6) - Sort C++ : ")

arg = input()

print("Mostrar vetores? [S/N]")

arg_show = input()

if(arg_show == 'n' or arg_show == 'N'):
	arg_show = 'f';
else:
	arg_show = '1';

fnames = glob(filepath + '*.in')
fnames.sort()

for filename in fnames:
	print (filename)
	sp.call(["./algsort", filename, str(arg), arg_show])




