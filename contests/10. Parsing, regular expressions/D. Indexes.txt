import re
import sys

for line in sys.stdin:
    line = re.sub(r'\$v_{+(([aA-zZ]*[0-9]+)|([0-9]*[aA-zZ]+))}+\$', r'v[\1]', line)
    line = re.sub(r'\$v_([aA-zZ]|[0-9])\$', r'v[\1]', line)
    print(line)