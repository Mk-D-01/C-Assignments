from pathlib import Path
import re

root = Path(r'e:\Projects\C Assignments')
html_path = root / 'index.html'
text = html_path.read_text(encoding='utf-8')
weeks = ['Week1','Week2','Week3','Week4','Week5','Week6','Week7','Week8','Week9','Week10','Week11','Week12','Week13','Week14']


def esc_js(s: str) -> str:
    return (
        s.replace('\\', '\\\\')
        .replace('`', '\\`')
        .replace('${', '\\${')
        .replace('\r\n', '\n')
        .replace('\n', '\\n')
    )

parts = []
for week in weeks:
    d = root / 'Yuvraj_Singh' / week
    if not d.exists():
        continue
    qfiles = sorted(d.glob('question*.c'))
    qparts = []
    for f in qfiles:
        code = f.read_text(encoding='utf-8')
        qnum = f.stem.replace('question', '')
        qparts.append(
            '{ name: "' + f.name + '", title: "Question ' + qnum + '", code: `' + esc_js(code) + '`, outputTemplate: (dir) => `PS E:\\Codes\\C\\C Assignments\\${dir}\\' + week + '> gcc ' + f.name + ' -o a\\nPS E:\\Codes\\C\\C Assignments\\${dir}\\' + week + '> ./a\\nSample output for ' + f.name + '` }'
        )
    parts.append('"' + week + '": { title: "' + week + '", questions: [' + ',\n                    '.join(qparts) + '] }')

out = 'const labData = {\n            ' + ',\n            '.join(parts) + '\n        };\n\n        let selectedWeek = "Week1";'
pattern = r'const labData = \{[\s\S]*?\n\s*\};\n\s*let selectedWeek = "Week1";'
match = re.search(pattern, text)
if not match:
    raise RuntimeError('labData marker not found')
new_text = text[:match.start()] + out + text[match.end():]
html_path.write_text(new_text, encoding='utf-8')
print('Updated index.html from the repo source files.')
