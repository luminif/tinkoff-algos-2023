import re
import sys

for s in sys.stdin:
    s = re.sub(r'\\texttt{([a-zA-Z]+|[0-9]+)}', r'\\begin{bfseries}\1\\end{bfseries}', s)
    print(s)