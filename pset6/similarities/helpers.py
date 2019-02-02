def lines(a, b):
    """Return lines in both a and b"""
    a_lines = []
    b_lines = []

    file_a = a.split('\n')
    file_b = b.split('\n')

    for line in file_a:
        a_lines.append(line.strip())

    for line in file_b:
        b_lines.append(line.strip())

    result = []
    # Flatten list
    result = sorted(set(a_lines).intersection(b_lines))

    # print(result)
    return result

from nltk.tokenize import sent_tokenize
def sentences(a, b):
    """Return sentences in both a and b"""

    a_sentences = []
    b_sentences = []

    file_a = sent_tokenize(a)
    file_b = sent_tokenize(b)


    for sentence in file_a:
        a_sentences.append(sentence.strip())

    for sentence in file_b:
        b_sentences.append(sentence.strip())

    result = sorted(set(a_sentences).intersection(b_sentences))

    print(result)
    return result

def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    # print(len(a))
    # print(len(b))
    substrings = []

    for i in range(len(a) - n + 1):
        sub = a[i:i+n]

        if sub in b and sub not in substrings:
            substrings.append(sub.strip())

    # print(f'substrings: {substrings}')
    return substrings
