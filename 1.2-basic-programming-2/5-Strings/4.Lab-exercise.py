random_text = "This is my text, oddWord please dont read it"


def is_word_odd(word):
    if len(word) % 2 != 0:
        return True
    else:
        return False


def show_odd_words(text):
    for word in text.split():
        if is_word_odd(word):
            print(word)


print(show_odd_words(random_text))
