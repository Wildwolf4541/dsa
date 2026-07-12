grade = {
    "A": 10,
    "A-": 9,
    "B": 8,
    "B-": 7,
    "C": 6,
}

print("Enter grade of the following subjects:")

subjects = {
    "CAO": 3,
    "MOS": 4.5,
    "ADC": 4.5,
    "Humanities": 3,
    "NLP": 3,
    "SPS": 3
}

total_credits_sem6 = 210
obtained_credits_sem6 = 0

for i in subjects:
    print(i, end=": ")
    g = input().strip()

    if g not in grade:
        print("Invalid grade entered!")
        exit()

    obtained_credits_sem6 += grade[g] * subjects[i]

print("Obtained points:", obtained_credits_sem6)

# SGPA
print("SGPA:", round((obtained_credits_sem6 / total_credits_sem6) * 10, 2))

obtained_credits_cgpa = 1082 + obtained_credits_sem6
total_credits_cgpa = 1340

print("CGPA:", round((obtained_credits_cgpa / total_credits_cgpa) * 10, 2))