def process_file(file_path):
    with open(file_path, 'r', encoding='utf-8') as f:
        lines = f.read().splitlines()

    roles = []
    text_lines = []

    section = None
    for line in lines:
        line = line.strip()
        if line.startswith('roles:'):
            section = 'roles'
        elif line.startswith('textLines:'):
            section = 'textLines'
        else:
            if section == 'roles':
                roles.append(line)
            elif section == 'textLines':
                text_lines.append(line)

    role_lines = {role: [] for role in roles}
    idx = 1
    current_role = None
    for line in text_lines:
        if ':' in line:
            parts = line.split(':')
            role = parts[0].strip()
            text = parts[1].strip()
            if role in roles:
                current_role = role
        else:
            if current_role:
                text = line
                role_lines[current_role].append(f"{idx}) {text}")
        idx += 1

    result = ""
    for role in roles:
        if role_lines[role]:
            result += f"{role}:\n"
            result += "\n".join(role_lines[role]) + "\n"

    return result


file_path = "roles.txt"
output = process_file(file_path)
print(output)
