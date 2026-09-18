import json
from pathlib import Path

root = Path(r'e:\Projects\C Assignments')
json_path = root / 'all_41_outputs.json'

with open(json_path, 'r', encoding='utf-8') as f:
    data = json.load(f)

outputs_map = {}
for item in data:
    week = item['Week']
    fname = item['File']
    content = item['Content']
    lines = content.split('\n')
    # body is lines[2:]
    body = '\n'.join(lines[2:]).strip()
    if week not in outputs_map:
        outputs_map[week] = {}
    outputs_map[week][fname] = body

# Write python dict representation
dict_code = "AUTHENTIC_OUTPUTS = " + json.dumps(outputs_map, indent=4)
with open(root / 'scratch_outputs_dict.py', 'w', encoding='utf-8') as f:
    f.write(dict_code)

print(f"Processed {len(data)} items into scratch_outputs_dict.py")
