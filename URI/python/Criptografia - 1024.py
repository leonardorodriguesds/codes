def encryption(_text_):
    return encryp_step3(encryp_step2(encryp_step1(_text_)))


def encryp_step1(_text_):
    for i in range(0, len(_text_)):
        character = ord(_text_[i])
        if 65 <= character <= 90 or 97 <= character <= 122:
            _text_ = _text_[:i] + chr(character + 3) + _text_[i + 1:]
    return _text_


def encryp_step2(_text_):
    return ''.join([_text_[len(_text_) - count] for count in range(1, len(_text_) + 1)])


def encryp_step3(_text_):
    for i in range(int(len(_text_) / 2), len(_text_)):
        _text_ = _text_[:i] + chr(ord(_text_[i]) - 1) + _text_[i + 1:]
    return _text_


num = int(input())
inputs = []
for x in range(0, num):
    try:
        inputs.append(input())
    except EOFError:
        break

for text in inputs:
    print("{}".format(encryption(text)))
