import os
import sys
import subprocess

if len(sys.argv) != 3:
    print("Usage: python script.py <dir> <file>")
    sys.exit(1)

dir = sys.argv[1]
file = sys.argv[2]
exec_file = os.path.join(dir, "build", "shellSort.out")
real = os.path.join(dir, "tests", "test.txt")
ref = file + ".ans"

# Запуск исполняемого файла и перенаправление ввода/вывода
with open(file, 'r') as infile, open(real, 'w') as outfile:
    subprocess.run([exec_file], stdin=infile, stdout=outfile, stderr=subprocess.STDOUT)

with open(real, 'r') as realf:
    line1 = realf.readline()  # Читаем первую строку
    real_numbers = list(map(int, line1.split()))
    ref_numbers = sorted(real_numbers)

# Удаление временного файла
os.remove(real)

# Сравнение содержимого
if real_numbers == ref_numbers:
    print("Files match.")
    sys.exit(0)
else:
    print("Files do not match.")
    print("real\n", real_numbers)
    print("ref\n", ref_numbers)
    sys.exit(1)
