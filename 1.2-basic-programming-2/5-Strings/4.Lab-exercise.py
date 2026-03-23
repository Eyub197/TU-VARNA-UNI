random_text = "This is my text oddWord please dont read it"


def is_word_odd(word):
    if len(word) % 2 != 0:
        return True
    else:
        return False


odd_words = []


def populate_odd_words(text):
    for word in text.split():
        if is_word_odd(word):
            odd_words.append(word)


populate_odd_words(random_text)
print(odd_words)
