def rabin_karp(pattern, text):
    p_len = len(pattern)
    t_len = len(text)
    p_hash = hash(pattern)
    result = []

    for i in range(t_len - p_len + 1):
        substring = text[i:i + p_len]
        if hash(substring) == p_hash:
            if substring == pattern:
                result.append(i)

    return result

pattern = input("Type Pattern: ")
text = input("Type Text: ")
result = rabin_karp(pattern, text)
print(" ".join(map(str, result)))
