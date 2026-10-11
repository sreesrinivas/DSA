def deserialize(self, s):
    # '-1' is not digit
    if s and s[-1].isdigit():
        return int(s)

    nested_integer = None
    digits = ''
    stack = []
    for c in s:
        if c.isdigit() or c == '-':
            digits += c
        elif c == '[':
            if nested_integer:
                stack.append(nested_integer)
            nested_integer = NestedInteger()
        elif c == ']':
            if digits:
                nested_integer.add(NestedInteger(int(digits)))
                digits = ''
            if stack:
                previous_nested_integer = stack.pop()
                previous_nested_integer.add(nested_integer)
                nested_integer = previous_nested_integer
        elif c == ',':
            if digits:
                nested_integer.add(NestedInteger(int(digits)))
                digits = ''

    return nested_integer
