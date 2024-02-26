import re
import sys

for line in sys.stdin:
    res = re.sub(r'[a+]+b+[b+]+c+c*', r'QQQ', line)
    print(res)