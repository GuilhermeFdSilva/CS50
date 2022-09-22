from cs50 import get_string

def grade(t):
    letters = 0
    words = 1
    sentences = 0
    for i in range(len(t)):
        if t[i].isalpha():
            letters += 1
        elif t[i].isspace():
            words += 1
        elif t[i] == "." or t[i] == "!" or t[i] == "?":
            sentences += 1
    L = (float(letters) / words) * 100
    S = (float(sentences) / words) * 100
    grade = (0.0588 *L) - (0.296 * S) - 15.8
    grade = round(grade)
    if grade < 1:
        print("Before Grade 1")
    elif grade > 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")

text = get_string("Text: ")
grade(text)