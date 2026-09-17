from pathlib import Path
import re

root = Path(r'e:\Projects\C Assignments')
html_path = root / 'index.html'
text = html_path.read_text(encoding='utf-8')
weeks = ['Week1','Week2','Week3','Week4','Week5','Week6','Week7','Week8','Week9','Week10','Week11','Week12','Week13','Week14']


def strip_student_header(code: str) -> str:
    return re.sub(r'/\*\s*(?:Name-|Roll no\.?|Section-|Course-|Branch-)[\s\S]*?\*/\s*', '', code, flags=re.IGNORECASE)


def esc_js(s: str) -> str:
    return (
        s.replace('\\', '\\\\')
        .replace('`', '\\`')
        .replace('\r\n', '\n')
        .replace('\n', '\\n')
    )


def humanize_name(name: str) -> str:
    words = re.sub(r'([a-z0-9])([A-Z])', r'\1 \2', name)
    words = words.replace('_', ' ')
    words = re.sub(r'\s+', ' ', words).strip()
    if not words:
        return name

    title_words = []
    for word in words.split(' '):
        if not word:
            continue
        normalized = word.lower()
        if normalized in {'cll', 'dll', 'bst'}:
            title_words.append(normalized.upper())
        else:
            title_words.append(normalized.capitalize())
    return ' '.join(title_words)


def title_from_code(code: str, fallback: str) -> str:
    cleaned = re.sub(r'//.*', '', code)
    cleaned = re.sub(r'/\*.*?\*/', '', cleaned, flags=re.DOTALL)
    matches = re.findall(r'(?:[A-Za-z_][A-Za-z0-9_\s\*\[\]]+)\s+([A-Za-z_][A-Za-z0-9_]*)\s*\([^;]*\)\s*\{', cleaned)
    for name in matches:
        if name.lower() in {'main', 'printf', 'scanf', 'fgets', 'malloc', 'free', 'strlen', 'strcmp', 'strtok', 'isdigit', 'tolower', 'toupper'}:
            continue
        title = humanize_name(name)
        if title and title.lower() != 'main':
            return title
    return fallback


parts = []
for week in weeks:
    d = root / 'Yuvraj_Singh' / week
    if not d.exists():
        continue
    qfiles = sorted(d.glob('question*.c'))
    qparts = []
    for f in qfiles:
        code = strip_student_header(f.read_text(encoding='utf-8'))
        qnum = f.stem.replace('question', '')
        title = title_from_code(code, 'Question ' + qnum)
        qparts.append(
            '{ name: "' + f.name + '", title: "' + title + '", code: `' + esc_js(code) + '`, outputTemplate: (dir) => "PS E:\\Codes\\C\\C Assignments\\\\" + dir + "\\\\' + week + '> gcc ' + f.name + ' -o a\\nPS E:\\Codes\\C\\C Assignments\\\\" + dir + "\\\\' + week + '> ./a\\nSample output for ' + f.name + '" }'
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
