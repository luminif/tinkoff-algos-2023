import re
import sys

for line in sys.stdin:
    line = re.sub(r'\\circle({)(\()([0-9]+),([0-9]+)(\))(,*)([0-9]*})', r'\\circle\1\2\4,\3\5\6\7', line)
    print(line)
