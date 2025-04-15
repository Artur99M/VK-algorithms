import os
import sys
import subprocess

if len(sys.argv) != 3:
    print("Usage: python script.py <dir> <file>")
    sys.exit(1)

dir = sys.argv[1]
file = sys.argv[2]
exec_file = os.path.join(dir, "build", "arrayOfAnagram.out")
real = os.path.join(dir, "tests", "test.txt")
ref = file + ".ans"

# Запуск исполняемого файла и перенаправление ввода/вывода
with open(file, 'r') as infile, open(real, 'w') as outfile:
    subprocess.run([exec_file], stdin=infile, stdout=outfile, stderr=subprocess.STDOUT)

with open(real, 'r') as realf, open(ref, 'r') as reff:
    line1 = realf.readline()  # Читаем первую строку
    line2 = reff.readline()  # Читаем первую строку

# Удаление временного файла
os.remove(real)

# Сравнение содержимого
if line1 == line2:
    print("Files match.")
    sys.exit(0)
else:
    print("Files do not match.")
    print("real\n", line1)
    print("ref\n", line2)
    sys.exit(1)
